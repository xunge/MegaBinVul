#include <stdint.h>

#define GROWABLE_SIZE 0

struct FontData {
    void* array_;
    int32_t bound_offset_;
    int32_t bound_length_;
    
    FontData(FontData* data, int32_t offset);
    void Init(void* array);
    void Bound(int32_t offset, int32_t length);
};