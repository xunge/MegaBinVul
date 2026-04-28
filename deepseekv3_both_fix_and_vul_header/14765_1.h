#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <limits.h>
#include <cstddef>

typedef int32_t status_t;
typedef int64_t off64_t;
#define ERROR_MALFORMED 1
#define ERROR_IO 2
#define ERROR_OUT_OF_RANGE 3
#define OK 0
#define ALOGI(...) 

#define U32_AT(p) (*((uint32_t*)(p)))

class SampleTable {
public:
    status_t setCompositionTimeToSampleParams(off64_t data_offset, size_t data_size);
    
private:
    uint32_t* mCompositionTimeDeltaEntries;
    size_t mNumCompositionTimeDeltaEntries;
    class DataSource {
    public:
        ssize_t readAt(off64_t offset, void* data, size_t size);
    };
    DataSource* mDataSource;
    
    class CompositionDeltaLookup {
    public:
        void setEntries(uint32_t* entries, size_t numEntries);
    };
    CompositionDeltaLookup* mCompositionDeltaLookup;
};