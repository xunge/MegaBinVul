#include <mutex>
#include <cstdint>
#include <sys/types.h>

struct InternalData {
    std::mutex mLock;
    struct {
        ssize_t indexOfKey(uint32_t) const { return 0; }
    } mItems;
};

class MetaDataBase {
    InternalData* mInternalData;
public:
    bool hasData(uint32_t key) const;
};