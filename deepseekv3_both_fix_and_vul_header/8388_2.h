#include <stdbool.h>
#include <stddef.h>

#define DCHECK(condition) ((void)0)
#define DCHECK_EQ(val1, val2) ((void)0)

namespace net {
class IOBuffer {
public:
    explicit IOBuffer(int size) {}
};
}

template<typename T>
class scoped_refptr {
public:
    scoped_refptr() : ptr_(nullptr) {}
    explicit scoped_refptr(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
    void operator=(T* ptr) { ptr_ = ptr; }
private:
    T* ptr_;
};

class SaveFileResourceHandler {
public:
    bool OnWillRead(scoped_refptr<net::IOBuffer>* buf, int* buf_size, int min_size);
    scoped_refptr<net::IOBuffer> read_buffer_;
};

enum AuthorizationState {
    AUTHORIZED
};

AuthorizationState authorization_state_;

const int kReadBufSize = 4096;