#include <stdint.h>

struct SkWriteBuffer {
    void writeMatrix(const void*);
    void write32(uint32_t);
    void writeRect(const void*);
    void writeBool(bool);
    bool isCrossProcess() const;
};

struct SkPicture {
    void flatten(SkWriteBuffer&) const;
};

struct SkPictureShader {
    const void* getLocalMatrix() const;
    uint32_t fTmx;
    uint32_t fTmy;
    void* fTile;
    SkPicture* fPicture;
    void flatten(SkWriteBuffer&) const;
};