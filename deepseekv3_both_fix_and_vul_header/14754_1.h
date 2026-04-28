#include <sys/types.h>
#include <string.h>

typedef int64_t off64_t;
typedef ssize_t ssize_t;
typedef size_t size_t;

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& lock) {}
    };
};

class DataSource {
public:
    virtual ssize_t readAt(off64_t offset, void *data, size_t size) = 0;
};

class MPEG4DataSource : public DataSource {
public:
    ssize_t readAt(off64_t offset, void *data, size_t size) override;
private:
    Mutex mLock;
    off64_t mCachedOffset;
    size_t mCachedSize;
    char* mCache;
    DataSource* mSource;

    bool isInRange(off64_t cachedOffset, size_t cachedSize, off64_t offset, size_t size) {
        return offset >= cachedOffset && offset + size <= cachedOffset + cachedSize;
    }
};