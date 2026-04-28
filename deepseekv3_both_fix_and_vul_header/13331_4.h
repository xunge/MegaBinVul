#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

using std::string;

#define THROW(msg) do { \
    std::ostringstream oss; \
    oss << msg; \
    throw std::runtime_error(oss.str()); \
} while(0)

#define LOG_DEBUG(level, msg)

namespace SystemUtilities {
    bool isDirectory(const string& path);
    string getCanonicalPath(const string& path);
    void ensureDirectory(const string& path);
    std::ostream* oopen(const string& path, int mode);
}

namespace String {
    bool startsWith(const string& str, const string& prefix);
}

class TarFileReader {
public:
    enum FileType {
        REG_FILE,
        NORMAL_FILE,
        CONTIGUOUS_FILE,
        DIRECTORY
    };

    bool hasMore();
    string getFilename();
    FileType getType();
    bool didReadHeader;
    int getMode();
    string extract(const string& _path);
    string extract(std::ostream& os);
};