#include "keypair.h"
#include "filewriter/filewriter.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <openssl/pem.h>
#include <openssl/sha.h>

namespace sunflower {
namespace wallet {

KeyPair::KeyPair(const PublicKey& PublicKey, const std::vector<uint8_t>& privateKey)
    : publicKey(PublicKey), privateKey(privateKey), address({}) {}

PublicKey KeyPair::getPublicKey() const {
    return publicKey;
}

std::vector<uint8_t> KeyPair::getPrivateKey() const {
    return privateKey;
}

Address KeyPair::getAddress() const {
    if (address.empty()) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, publicKey.data(), publicKey.size());
        SHA256_Final(address.data(), &sha256);
    }
    return address;
}

bool KeyPair::writeTo(const std::string& dir, const std::string& prefix) const {
    std::string privPath = dir + "/" + prefix + "priv.key";
    std::string pubPath = dir + "/" + prefix + "pub.key";

    BIO* privBio = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(privBio, nullptr, nullptr, privateKey.data(), privateKey.size(), nullptr, nullptr);

    char* privData;
    long privLength = BIO_get_mem_data(privBio, &privData);
    std::string privKey(privData, privLength);
    BIO_free(privBio);

    if (!filewriter::WriteToFile(privPath, privKey)) {
        return false;
    }

    BIO* pubBio = BIO_new(BIO_s_mem());
    PEM_write_bio_PUBKEY(pubBio, publicKey.data(), publicKey.size());
    
    char* pubData;
    long pubLength = BIO_get_mem_data(pubBio, &pubData);
    std::string pubKey(pubData, pubLength);
    BIO_free(pubBio);

    return filewriter::WriteToFile(pubPath, pubKey);
}

void KeyPair::clean() {
    publicKey.clear();
    privateKey.clear();
}

bool KeyPair::isHexAddress(const std::string& hexAddress) {
    std::regex hexPattern(R"(^(0[xX])?[A-Fa-f\d]{64}$)");
    return std::regex_match(hexAddress, hexPattern);
}

Address KeyPair::fromHexAddress(const std::string& hexAddress) {
    if (!isHexAddress(hexAddress)) {
        throw std::runtime_error("Invalid hex address: " + hexAddress);
    }
    std::string hexStr = hexAddress.substr(0, 2) == "0x" ? hexAddress.substr(2) : hexAddress;

    std::vector<uint8_t> bytes(hexStr.size() / 2);
    for (size_t i = 0; i < hexStr.size(); ++i) {
        std::stringstream ss;
        ss << std::hex << hexStr.substr(i * 2, 2);
        int byte;
        ss >> byte;
        bytes[i] = static_cast<uint8_t>(byte);
    }

    return bytesToAddress(bytes);
}

std::string KeyPair::toHexAddress(const Address& address) {
    std::stringstream ss;
    ss << "0x";
    for (auto byte : address) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    return ss.str();
}

Address KeyPair::bytesToAddress(const std::vector<uint8_t>& bytes) {
    if (bytes.size() != 32) {
        throw std::runtime_error("Invalid address bytes length: " + std::to_string(bytes.size()));
    }
    Address address;
    std::copy(bytes.begin(), bytes.begin() + std::min(bytes.size(), address.size()), address.begin());
    return address;
}

PublicKey KeyPair::readPubKey(const std::string& pubKeyFile, std::vector<uint8_t>& rest) {
    std::ifstream file(pubKeyFile, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open public key file: " + pubKeyFile);
    }

    std::string keyData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    BIO* bio = BIO_new_mem_buf(keyData.data(), keyData.size());
    if (!bio) {
        throw std::runtime_error("Could not create public key BIO");
    }

    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    if (!pkey) {
        BIO_free(bio);
        throw std::runtime_error("Failed to decode PEM block containing public key");
    }

    int len = i2d_PUBKEY(pkey, nullptr);
    PublicKey pub(len);
    unsigned char* pubData = pub.data();
    i2d_PUBKEY(pkey, &pubData);

    BIO_free(bio);
    EVP_PKEY_free(pkey);

    return pub;
}

std::vector<uint8_t> KeyPair::readPrivKey(const std::string& privKeyFile, std::vector<uint8_t>& rest) {
    std::ifstream file(privKeyFile, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open private key file: " + privKeyFile);
    }

    std::string keyData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    BIO* bio = BIO_new_mem_buf(keyData.data(), keyData.size());
    if (!bio) {
        throw std::runtime_error("Could not create private key BIO");
    }

    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(bio, nullptr, nullptr, nullptr);
    if (!pkey) {
        BIO_free(bio);
        throw std::runtime_error("Failed to decode PEM block containing private key");
    }

    int len = i2d_PrivateKey(pkey, nullptr);
    std::vector<uint8_t> priv(len);
    unsigned char* privData = priv.data();
    i2d_PrivateKey(pkey, &privData);

    BIO_free(bio);
    EVP_PKEY_free(pkey);

    return priv;
}

}  // namespace wallet
}  // namespace sunflower
