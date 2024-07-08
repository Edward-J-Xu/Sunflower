#include "filewriter.h"
#include <fstream>
#include <sys/stat.h>

namespace sunflower {
namespace filewriter {

bool WriteToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << data;

    file.flush();

    file.close();

    return !file.fail();
}

bool FileExists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

} // namespace filewriter
} // namespace sunflower
