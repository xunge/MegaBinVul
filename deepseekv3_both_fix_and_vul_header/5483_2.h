#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <stdexcept>
#include <cerrno>
#include <cstring>

using namespace std;

#define TRACE_POINT()
int parseModeString(const string& mode);
class RuntimeException : public runtime_error { using runtime_error::runtime_error; };
class FileSystemException : public runtime_error { 
public:
    FileSystemException(const string& msg, int err, const string& path) 
        : runtime_error(msg + ": " + strerror(err)) {}
};