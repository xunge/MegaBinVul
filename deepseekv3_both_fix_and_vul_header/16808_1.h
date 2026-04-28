#include <utility>

typedef unsigned char byte;

class DataBuf {
public:
    std::pair<byte*, long> release();
};

class CiffComponent {
private:
    bool isAllocated_;
    byte* pData_;
    long size_;
    int tag_;
public:
    void setValue(DataBuf buf);
    int dataLocation();
    static const int directoryData;
};