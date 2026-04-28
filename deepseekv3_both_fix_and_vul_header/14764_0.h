#include <stdint.h>
#include <stddef.h>

typedef int status_t;
#define OK 0
#define ERROR_MALFORMED -1

template<typename T>
class sp {
    T* m_ptr;
public:
    sp(T* ptr) : m_ptr(ptr) {}
    T* operator->() const { return m_ptr; }
};

class MetaData {
public:
    void setData(int key, int unused, const void* data, size_t size);
};

enum {
    kKeyVorbisInfo,
    kKeyVorbisBooks
};