#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

typedef unsigned char u8;
typedef off_t off_t;

namespace AK {
    struct String {
        String(const char* str);
        bool starts_with(const String& other) const;
        const char* c_str() const;
        bool operator==(const String& other) const;
    };
}

struct MappedFile {
    bool seek_and_read(void* buffer, off_t offset, size_t size) const;
};

struct StringBuilder {
    void append(const AK::String& str);
    void append(const char* str);
    AK::String to_string() const;
};

struct LexicalPath {
    LexicalPath(const AK::String& path);
    AK::String string() const;
};

namespace Core {
    struct IODevice {
        enum {
            WriteOnly
        };
    };

    struct File {
        static File* construct(const AK::String& name);
        bool open(int mode);
        bool write(const void* data, size_t size);
        bool close();
        const char* error_string() const;
    };
}

#define VERIFY(x) assert(x)

static inline bool seek_and_read(void* buffer, const MappedFile& file, off_t offset, size_t size) {
    return file.seek_and_read(buffer, offset, size);
}

using String = AK::String;