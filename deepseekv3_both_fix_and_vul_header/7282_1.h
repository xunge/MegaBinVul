#include <stdlib.h>

void* aligned_dealloc(void* ptr);
void* custom_free(void* ptr);

struct abitwriter {
    void* data2;
    int fmem;
    ~abitwriter();
};