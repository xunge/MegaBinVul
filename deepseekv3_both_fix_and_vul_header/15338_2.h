#include <cstdint>
#include <mutex>
#include <sys/types.h>

class MetaDataBase {
protected:
    struct typed_data {
        void setData(uint32_t type, const void* data, size_t size);
    };

    struct InternalData {
        std::mutex mLock;
        template<typename K, typename V> class KeyedVector {
        public:
            ssize_t indexOfKey(K key) const;
            V& editValueAt(ssize_t index);
            ssize_t add(K key, const V& value);
        };
        KeyedVector<uint32_t, typed_data> mItems;
    };
    InternalData* mInternalData;

public:
    bool setData(uint32_t key, uint32_t type, const void* data, size_t size);
};