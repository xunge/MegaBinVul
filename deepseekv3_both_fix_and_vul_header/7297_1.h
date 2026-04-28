#include <sys/ioctl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define HAVE_OSS_GETVERSION
#define OSS_GETVERSION _IOR('M', 0, int)

typedef const char* RString;

class RageSoundDriver_OSS {
public:
    static RString CheckOSSVersion(int fd);
};

extern class Logger* LOG;

class Logger {
public:
    void Warn(const char* format, ...);
    void Info(const char* format, ...);
};

bool IsADirectory(const char* path);