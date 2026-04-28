#include <stdint.h>
#include <cassert>
#include <cstddef>

#define assertx(expr) assert(expr)
#define BZ2_bzread(stream, buf, len) (0)  // Dummy implementation

struct BZ2File {
    void* m_bzFile;
    void setEof(bool);
    int64_t readImpl(char* buf, int64_t length);
};