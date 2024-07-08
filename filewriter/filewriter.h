#ifndef SUNFLOWER_FILEWRITER_H
#define SUNFLOWER_FILEWRITER_H

#include <string>

namespace sunflower {
namespace filewriter {

// Writes the given string data to the specified file, checking for errors and syncing at the end.
bool WriteToFile(const std::string& filePath, const std::string& data);

// Returns a boolean value indicating whether the named file or directory exists or not.
bool FileExists(const std::string& name);

}  // namespace filewriter
}  // namespace sunflower

# endif //SUNFLOWER_FILEWRITER_H
