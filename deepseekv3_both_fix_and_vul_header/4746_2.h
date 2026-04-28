#include <stddef.h>
#include <stdint.h>

typedef int32_t RunType;

struct SkIRect {
    int32_t fLeft;
    int32_t fTop;
    int32_t fRight;
    int32_t fBottom;
};

struct RunHead {
    RunType* writable_runs();
};

struct SkRBufferWithSizeCheck {
    SkRBufferWithSizeCheck(const void* storage, size_t length);
    bool readS32(int32_t* value);
    bool read(void* dst, size_t size);
    bool isValid() const;
    size_t pos() const;
};

struct SkRegion {
    SkIRect fBounds;
    RunHead* fRunHead;
    void allocateRuns(int32_t count, int32_t ySpanCount, int32_t intervalCount);
    void swap(SkRegion& other);
    size_t readFromMemory(const void* storage, size_t length);
};

extern RunHead* SkRegion_gRectRunHeadPtr;