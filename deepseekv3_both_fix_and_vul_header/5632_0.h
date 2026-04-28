#include <algorithm>
#include <cstdint>

using uint32 = uint32_t;
using uint8 = uint8_t;

#define DCHECK(condition)
#define DCHECK_EQ(val1, val2)
#define DCHECK_LT(val1, val2)
#define DCHECK_LE(val1, val2)

struct BufferData {
    uint8* data;
    uint32 wrap_position;
};

class PartialCircularBuffer {
public:
    void Write(const void* buffer, uint32 buffer_size);
private:
    BufferData* buffer_data_;
    uint32 position_;
    uint32 data_size_;
    void DoWrite(uint8* dest, const void* src, uint32 size);
    void DoWrite(const void* src, uint32 size);
};