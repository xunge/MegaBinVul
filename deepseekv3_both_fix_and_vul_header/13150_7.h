#include <cstdint>
#include <memory>
#include <string>
#include <limits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <functional>

using std::string;
typedef uint8_t uint8;
typedef uint16_t uint16;

struct StringPiece {
    const char* data() const { return nullptr; }
    size_t size() const { return 0; }
};

struct Status {
    Status() {}
    Status(const string& msg) {}
    Status(const char* msg) {}
    bool ok() const { return false; }
    friend std::ostream& operator<<(std::ostream& os, const Status&) { return os; }
};

template<typename T>
struct TensorFlat {
    T* data() { return nullptr; }
    template<typename Device> 
    TensorFlat& device(const Device&) { return *this; }
    template<typename U>
    TensorFlat& operator=(const U&) { return *this; }
};

struct Tensor {
    template<typename T> TensorFlat<T> flat() { return TensorFlat<T>(); }
};

struct TensorShape {
    TensorShape(std::initializer_list<int64_t>) {}
};

template <typename T>
class TTypes {
public:
    class UnalignedConstFlat {
    public:
        UnalignedConstFlat(const uint8*, int) {}
        template <typename U> U cast() const { return U(); }
    };
};

namespace Eigen {
    class ThreadPoolDevice {};
}

namespace gif {
    using AllocatorFn = std::function<uint8*(int, int, int, int)>;
    uint8* Decode(const char*, size_t, AllocatorFn, string*, bool);
}

namespace errors {
    class InvalidArgument : public Status {
    public:
        InvalidArgument(const string& msg) : Status(msg) {}
        InvalidArgument(const char* msg) : Status(msg) {}
        template<typename... Args>
        InvalidArgument(Args&&... args) : Status("") {
            std::ostringstream oss;
            (oss << ... << args);
            *this = InvalidArgument(oss.str());
        }
    };
}

enum DataType {
    DT_UINT8,
    DT_UINT16,
    DT_FLOAT
};

struct OpKernelContext {
    void SetStatus(const Status&) {}
    Status allocate_output(int, const TensorShape&, Tensor**) { return Status(""); }
    template<typename Device> Device& eigen_device() { static Device d; return d; }
};

#define OP_REQUIRES(CTX, COND, STATUS) \
    do { if (!(COND)) { (CTX)->SetStatus(STATUS); return; } } while (0)

#define VLOG(LEVEL) if (LEVEL <= 0) {} else std::cout

extern int channels_;
extern string op_type_;
extern DataType data_type_;
extern bool expand_animations_;