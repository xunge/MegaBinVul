#include <cstdio>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

class FileIo {
    struct Impl {
        struct StructStat {
            size_t st_size;
        };
        FILE* fp_;
        std::string openMode_;
        int stat(StructStat& buf);
    };
    Impl* p_;
public:
    size_t size() const;
};