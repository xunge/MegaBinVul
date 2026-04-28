#include <stdint.h>
#include <string.h>

typedef struct InMemoryUrlProtocol {
    uint8_t* data_;
    int64_t size_;
    int64_t position_;
    int Read(int size, uint8_t* data);
} InMemoryUrlProtocol;

#define AVERROR(e) (-(e))
#define EIO 5

typedef int64_t int64;
typedef uint8_t uint8;