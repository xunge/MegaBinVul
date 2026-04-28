#include <cstdint>
#include <cstring>
#include <string>

class Parcel {
public:
    bool writeString8(const std::string&);
    bool writeUint32(uint32_t);
    bool writeBool(bool);
    bool writeDupFileDescriptor(int);
    void* writeInplace(size_t);
};

enum status_t {
    OK,
    UNKNOWN_ERROR
};

class CursorWindow {
public:
    status_t writeToParcel(Parcel* parcel);
private:
    std::string mName;
    uint32_t mNumRows;
    uint32_t mNumColumns;
    int mAshmemFd;
    uint32_t mSize;
    void* mData;
    size_t mAllocOffset;
    size_t mSlotsOffset;
    
    size_t sizeOfSlots();
    size_t sizeInUse();
    std::string toString();
};

#define LOG(level) Logger()
class Logger {
public:
    template<typename T>
    Logger& operator<<(const T&);
};