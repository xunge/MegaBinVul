#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    MALLOCED_NULL
} ExitCode;

extern void custom_exit(ExitCode code);
extern unsigned char* aligned_alloc(size_t size);
extern void* custom_calloc(size_t size);

struct abitwriter {
    int size_bound;
    int fillbit;
    int adds;
    int cbyte2;
    int cbit2;
    unsigned long buf;
    bool error;
    bool fmem;
    int dsize;
    unsigned char* data2;

    abitwriter(int size, int max_file_size);
};