#ifndef SUNFLOWER_REFLECTUTIL_H
#define SUNFLOWER_REFLECTUTIL_H

#include <string>
#include <type_traits>
#include <stdexcept>

namespace sunflower {
namespace reflectutil {

struct Field {
    std::string name;
    void* value;  
};

template <typename T>
bool hasField(const T& obj, const std::string& fieldName) {
    auto structType = typeid(obj);
    auto member = structType->getMember(fieldName);
    return member != nullptr;
}

template <typename T>
void setField(T& obj, const std::vector<Field>& fields) {
    for (const auto& field : fields) {
        auto structType = typeid(obj);
        auto member = structType->getMember(field.name);
        if (member == nullptr) {
            throw std::runtime_error("Field not found: " + field.name);
        }
        if (!member->canSet()) {
            throw std::runtime_error("The field you are trying to set is not settable: " + field.name);
        }
        member->setValue(&obj, field.value);
    }
}

template <typename T>
bool isNil(const T& obj, const std::string& fieldName) {
    auto structType = typeid(obj);
    auto member = structType->getMember(fieldName);
    if (member == nullptr) {
        throw std::runtime_error("Field not found: " + fieldName);
    }
    return member->isNil(&obj);
}

} // namespace reflectutil
} // namespace sunflower

#endif //SUNFLOWER_REFLECTUTIL_H
