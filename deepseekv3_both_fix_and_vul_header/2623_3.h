#include <string>
#include <ctime>
#include <cstring>
#include <libgen.h>
#include <algorithm>

class queueloader {
public:
    std::string get_dlpath();
    std::string get_filename(const std::string& str);
};

namespace utils {
    std::string replace_all(const std::string& str, const std::string& from, const std::string& to);
}

extern std::string NEWSBEUTER_PATH_SEP;
extern queueloader* ctrl;