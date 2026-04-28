#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <limits.h>

typedef int32_t status_t;
typedef int64_t off64_t;
typedef int64_t ssize_t;

#define ERROR_MALFORMED -1
#define ERROR_IO -2
#define ERROR_OUT_OF_RANGE -3
#define OK 0

#define U32_AT(ptr) ntohl(*((uint32_t *)(ptr)))

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void *data, size_t size) = 0;
};

class SampleTable {
private:
    DataSource *mDataSource;
    uint32_t *mTimeToSample;
    uint32_t mTimeToSampleCount;

public:
    status_t setTimeToSampleParams(off64_t data_offset, size_t data_size);
};