#include <mutex>
#include <stdint.h>
#include <sys/types.h>

class MetaDataBase {
public:
    bool remove(uint32_t key);
private:
    struct InternalData {
        std::mutex mLock;
        struct {
            ssize_t indexOfKey(uint32_t key) const;
            void removeItemsAt(size_t index);
        } mItems;
    };
    InternalData* mInternalData;
};