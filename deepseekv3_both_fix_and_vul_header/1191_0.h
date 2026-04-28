#include <iostream>
#include <string>
#include <filesystem>

class FileBody {
private:
    std::filesystem::path path_;
public:
    void Dump(std::ostream& os, const std::string& prefix) const;
};