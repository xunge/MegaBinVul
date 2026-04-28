#include <mutex>
#include <cstdint>

struct String8 {
    void appendFormat(const char* fmt, ...);
    const char* string() const;
    void append(const char* str);
};

struct typed_data {
    String8 asString(bool) const;
};

template<typename K, typename V>
class KeyedVector {
public:
    int size() const;
    K keyAt(int) const;
    V valueAt(int) const;
};

struct InternalData {
    std::mutex mLock;
    KeyedVector<int32_t, typed_data> mItems;
};

class MetaDataBase {
    InternalData* mInternalData;
public:
    String8 toString() const;
};

void MakeFourCCString(int32_t, char[5]);