#include <mutex>
#include <cstdint>
#include <string>

class typed_data {
public:
    class StringResult {
    public:
        const char* string() const;
    };
    StringResult asString(bool) const;
};

class InternalData {
public:
    std::mutex mLock;
    class {
    public:
        int size() const;
        int32_t keyAt(int) const;
        const typed_data& valueAt(int) const;
    } mItems;
};

class MetaDataBase {
protected:
    InternalData* mInternalData;
public:
    void dumpToLog() const;
};

void MakeFourCCString(int32_t key, char cc[5]);
void ALOGI(const char* format, ...);