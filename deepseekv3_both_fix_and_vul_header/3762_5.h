#include <string>
#include <stdexcept>
#include <ostream>
#include <memory>
#include <sstream>

#define THROW(msg) do { std::ostringstream oss; oss << msg; throw std::runtime_error(oss.str()); } while(0)
#define LOG_DEBUG(level, msg)

using std::string;

namespace SystemUtilities {
    bool isDirectory(const string& path);
    string getCanonicalPath(const string& path);
    void ensureDirectory(const string& path);
    std::unique_ptr<std::ostream> oopen(const string& path);
}

namespace String {
    bool startsWith(const string& str, const string& prefix);
}

class TarFileReader {
public:
    enum FileType {
        NORMAL_FILE,
        CONTIGUOUS_FILE,
        DIRECTORY
    };

    bool hasMore();
    string getFilename();
    FileType getType();
    string extract(const string& path);
    string extract(std::ostream& out);
};