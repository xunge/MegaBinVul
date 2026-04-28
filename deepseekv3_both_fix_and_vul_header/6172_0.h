#include <iostream>
#include <string>

class Params {
public:
    static Params& instance();
    bool force_;
    const std::string& progname() const;
};

namespace Exiv2 {
    bool fileExists(const std::string& path);
}

const char* _(const char* str);