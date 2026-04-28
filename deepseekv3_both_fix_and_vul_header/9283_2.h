#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USE(QCMSLIB) 0
#define RELEASE_ASSERT_NOT_REACHED() abort()

namespace blink {

template<typename T>
class WebVector {
};

class Platform {
public:
    virtual ~Platform() {}
    virtual const unsigned char* getTraceCategoryEnabledFlag(const char*) = 0;
    virtual void cryptographicallyRandomValues(unsigned char*, size_t) = 0;
    virtual void screenColorProfile(WebVector<char>*) = 0;
};

void initializeWithoutV8(Platform*) {}
} // namespace blink

class SharedBuffer {
public:
    size_t size() const { return 0; }
    const char* data() const { return nullptr; }
};

template<typename T>
class RefPtr {
public:
    RefPtr() : ptr(nullptr) {}
    RefPtr(T* p) : ptr(p) {}
    T* get() const { return ptr; }
    T* operator->() const { return ptr; }
private:
    T* ptr;
};

class ImageDecoder {
public:
    static void qcmsOutputDeviceProfile();
};

void getScreenColorProfile(blink::WebVector<char>*) {}
SharedBuffer* readFile(const char*) { return nullptr; }
double getCurrentTime() { return 0.0; }
bool decodeImageData(SharedBuffer*, bool, size_t) { return false; }

using blink::WebVector;