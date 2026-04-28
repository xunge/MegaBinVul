#include <string>
#include <cstdlib>
#include <set>

struct Token {
    std::string n;
    bool a;
    int i;
};

namespace Exiv2 {
    typedef std::set<std::string> StringSet;
}