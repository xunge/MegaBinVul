#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <limits.h>
#include <cstddef>
#include <cstdlib>

#define ALOGI(...)
#define ERROR_MALFORMED 1
#define ERROR_IO 2
#define ERROR_OUT_OF_RANGE 3
#define OK 0

typedef int status_t;
typedef int64_t off64_t;

#define U32_AT(ptr) (*(const uint32_t*)(ptr))

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void* data, size_t size) = 0;
};

class CompositionDeltaLookup {
public:
    virtual void setEntries(uint32_t* entries, size_t numEntries) = 0;
};

class SampleTable {
public:
    status_t setCompositionTimeToSampleParams(off64_t data_offset, size_t data_size);
    
    uint32_t* mCompositionTimeDeltaEntries;
    size_t mNumCompositionTimeDeltaEntries;
    DataSource* mDataSource;
    CompositionDeltaLookup* mCompositionDeltaLookup;
};