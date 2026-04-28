#include <cstring>
#include <new>

class CSNode;

enum MJ_RESULT { MJ_SYSTEMRES };
enum MN_RESULT { MN_MEMORY };

class CUDTException {
public:
    CUDTException(MJ_RESULT, MN_RESULT, int);
};

class CSndUList {
public:
    void realloc_();
private:
    CSNode** m_pHeap;
    int m_iArrayLength;
};