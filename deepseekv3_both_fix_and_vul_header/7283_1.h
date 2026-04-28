#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

struct abytewriter {
    abytewriter(size_t size);
    ~abytewriter();
    void write_n(const void* data, size_t size);
    uint8_t* getptr_aligned();
    uint32_t getpos();
};

extern uint8_t* hdrdata;
extern uint32_t hdrs;

#define B_SHORT(a, b) (((a) << 8) | (b))

void aligned_dealloc(void* ptr);
void custom_free(void* ptr);