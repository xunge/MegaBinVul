#include <string>

class ZipCommon {
public:
    static bool isValidPath(const std::string& path);
};

class Path {
public:
    enum PathStyle {
        PATH_UNIX,
        PATH_WINDOWS
    };
    
    Path(const std::string& path, PathStyle style);
    bool isAbsolute() const;
};