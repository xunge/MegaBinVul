#include <stdint.h>
#include <stddef.h>

template<typename T> class sp {
public:
    sp(T* ptr) : m_ptr(ptr) {}
    T* operator->() { return m_ptr; }
private:
    T* m_ptr;
};

class AString {
public:
    size_t size() const;
    const char* c_str() const;
};

class ABuffer {
public:
    ABuffer(size_t size);
    uint8_t* data();
    size_t size() const;
};