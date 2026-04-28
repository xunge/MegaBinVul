#include <stdint.h>

struct SkMatrix {
    float mat[9];
};

struct SkRect {
    float left, top, right, bottom;
};

class SkPicture {
public:
    static SkPicture* CreateFromBuffer(class SkReadBuffer&);
};

class SkReadBuffer {
public:
    void readMatrix(SkMatrix*);
    uint32_t read32();
    void readRect(SkRect*);
    bool isCrossProcess();
    bool isVersionLT(int);
    void validate(bool);
    bool readBool();
    static const int kPictureShaderHasPictureBool_Version;
};

template<typename T>
class SkAutoTUnref {
public:
    explicit SkAutoTUnref(T* obj = nullptr) : fObj(obj) {}
    void reset(T* obj) { fObj = obj; }
    T* get() const { return fObj; }
    operator T*() const { return fObj; }
private:
    T* fObj;
};

enum TileMode {
    kClamp_TileMode,
    kRepeat_TileMode, 
    kMirror_TileMode
};

class SkFlattenable {
};

class SkPictureShader {
public:
    static SkFlattenable* Create(SkPicture*, TileMode, TileMode, SkMatrix*, SkRect*);
    static SkFlattenable* CreateProc(SkReadBuffer&);
};

const int SkReadBuffer::kPictureShaderHasPictureBool_Version = 0;