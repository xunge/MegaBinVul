#include <stddef.h>

struct QIntC {
    static size_t to_offset(size_t len);
};

struct Pl_Count {
    struct {
        size_t count;
        unsigned char last_char;
    } *m;
    Pl_Count* getNext();
    void write(unsigned char* buf, size_t len);
};