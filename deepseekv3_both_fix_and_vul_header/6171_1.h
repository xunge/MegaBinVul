#include <string>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdio>

namespace Params {
    enum FileExistsPolicy {
        overwritePolicy,
        renamePolicy,
        askPolicy
    };
    
    class instance {
    public:
        std::string format_;
        bool verbose_;
        bool timestamp_;
        FileExistsPolicy fileExistsPolicy_;
        std::string progname();
    };
    
    instance& instance();
}

namespace Util {
    std::string basename(const std::string& path, bool b = false);
    std::string dirname(const std::string& path);
    void replace(std::string& str, const std::string& from, const std::string& to);
    std::string suffix(const std::string& path);
}

namespace Exiv2 {
    bool fileExists(const std::string& path);
    std::string toString(int n);
    std::string strError();
}

#define EXV_SEPARATOR_STR "/"
#define _(str) str