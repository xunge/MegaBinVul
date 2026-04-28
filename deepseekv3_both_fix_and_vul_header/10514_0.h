#include <stdbool.h>
#include <stdint.h>

typedef int64_t off64_t;

#define OK 0

struct DataSource {
    int getSize(off64_t* size);
};

class NuMediaExtractor {
private:
    int64_t mTotalBitrate;
    int64_t mDurationUs;
    DataSource* mDataSource;

public:
    bool getTotalBitrate(int64_t* bitrate) const;
};