#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <string>
#include <limits>
#include <iostream>

struct SharedMemoryCreateOptions {
    size_t size;
    const std::string* name;
    bool open_existing;
    bool executable;
};

class FilePath {
public:
    std::string value() const;
    FilePath DirName() const;
};

class SharedMemory {
private:
    int mapped_file_;
    size_t requested_size_;
public:
    bool Create(const SharedMemoryCreateOptions& options);
    bool PrepareMapFile(FILE* fp);
};

namespace file_util {
    FILE* CreateAndOpenTemporaryShmemFile(FilePath* path, bool executable);
    bool CloseFile(FILE* file);
    FILE* OpenFile(const FilePath& path, const char* mode);
}

bool FilePathForMemoryName(const std::string& name, FilePath* path);

namespace base {
    class ThreadRestrictions {
    public:
        class ScopedAllowIO {
        public:
            ScopedAllowIO();
            ~ScopedAllowIO();
        };
    };
}

#define DCHECK(condition) ((void)0)
#define DCHECK_EQ(val1, val2) ((void)0)
#define PLOG(level) std::cerr
#define LOG(level) std::cerr
#define HANDLE_EINTR(x) (x)
#define OS_MACOSX 0