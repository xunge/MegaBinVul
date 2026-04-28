#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <stdint.h>

typedef uint8_t uchar;

enum {
    CV_8U,
    CV_16U,
    CV_IMWRITE_PAM_TUPLETYPE,
    CV_IMWRITE_PAM_FORMAT_NULL
};

struct Error {
    enum {
        StsInternal
    };
};

#define CV_Error(code, msg) assert(0)

struct pam_format {
    const char* name;
};

class Mat {
public:
    int cols;
    int rows;
    int depth() const;
    const uchar* ptr(int y = 0) const;
    int channels() const;
    size_t elemSize() const;
    size_t elemSize1() const;
};

class WLByteStream {
public:
    bool open(const std::vector<uchar>& buf);
    bool open(const char* filename);
    void putBytes(const void* data, int size);
    void close();
};

template<typename T>
class AutoBuffer {
public:
    AutoBuffer(size_t size);
    T* data();
    operator T*() { return data(); }
};

class PAMEncoder {
public:
    std::vector<uchar>* m_buf;
    const char* m_filename;
    bool write(const Mat& img, const std::vector<int>& params);
};

static const int PAM_FORMATS_NO = 0;
static const pam_format formats[] = {0};

static bool isBigEndian() {
    union {
        uint32_t i;
        char c[4];
    } test = {0x01020304};
    return test.c[0] == 1;
}

static size_t alignSize(size_t sz, int n) {
    return (sz + n-1) & -n;
}