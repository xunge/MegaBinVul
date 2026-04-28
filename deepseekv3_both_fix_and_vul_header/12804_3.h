#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/mman.h>

#define MiB (1024 * 1024)

extern "C" {
    int unveil(const char *path, const char *permissions);
}

class String {
public:
    String(const char*);
    const char* characters() const;
};

class StringBuilder {
public:
    void append(const char*);
    String to_string() const;
};

class LexicalPath {
public:
    LexicalPath(const String&);
    String string() const;
};

namespace Core {
    class ArgsParser {
    public:
        enum class Required { Yes, No };
        void add_option(int&, const char*, const char*, int, const char*);
        void add_positional_argument(const char*&, const char*, const char*, Required);
        void parse(int, char**);
    };
}

template<typename T, typename E>
class Result {
public:
    bool is_error() const;
    T& value();
    const E& error() const;
};

template<typename T>
class NonnullOwnPtr {
public:
    T& operator*();
};

class MappedFile {
public:
    static Result<NonnullOwnPtr<MappedFile>, String> map(const String&);
};

String human_readable_size(int);
int round_up_to_power_of_two(int, int);
bool find_next_central_directory(off_t, MappedFile&, off_t, off_t&);
bool unpack_file_for_central_directory_index(off_t, MappedFile&, const String&);
bool unpack_file_for_central_directory_index(off_t, MappedFile&);

void warnln(const char*, const String&, const String&);