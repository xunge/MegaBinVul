#include <stdint.h>
#include <string.h>
#include <stdlib.h>

class MetaData {
public:
    class typed_data {
    public:
        void setData(uint32_t type, const void *data, size_t size);
        void clear();
        void allocateStorage(size_t size);
        void* storage();
        uint32_t mType;
    };
};

#define ALOGE(...)