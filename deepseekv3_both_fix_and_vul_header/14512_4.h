#include <string>
#include <map>
#include <sys/stat.h>

struct FileInfo {
    std::string path;
    int statResult;
    struct stat statbuf;
};

class Response {
public:
    void add_header(const std::string&, const std::string&);
    void end();
};

namespace utility {
    std::string sanitize_filename(const std::string&);
}

extern FileInfo file_info;
extern int code;
extern std::map<std::string, std::string> mime_types;
extern Response* current_response;
extern bool compressed;

#define this current_response