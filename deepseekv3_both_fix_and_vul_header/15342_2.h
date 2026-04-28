#include <cstdint>
#include <cstddef>
#include <mutex>
#include <sys/types.h>

class MetaDataBase {
protected:
    struct typed_data {
        void getData(uint32_t* type, const void** data, size_t* size) const;
    };

    struct InternalData {
        std::mutex mLock;
        class KeyedVector {
        public:
            ssize_t indexOfKey(uint32_t key) const;
            const typed_data& valueAt(ssize_t index) const;
        };
        KeyedVector mItems;
    };
    InternalData* mInternalData;

public:
    bool findData(uint32_t key, uint32_t* type, const void** data, size_t* size) const;
};