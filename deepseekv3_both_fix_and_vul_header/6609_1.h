#include <string>

class Path {
public:
    Path(const std::string& path);
    bool isRelative() const;
};

class ZipCommon {
public:
    static bool isValidPath(const std::string& path);
};