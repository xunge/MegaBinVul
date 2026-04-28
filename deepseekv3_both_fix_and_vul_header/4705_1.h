#include <mutex>

class SkTypeface_FreeType {
public:
    void onFilterRec(class SkScalerContextRec* rec) const;
};

typedef float SkScalar;

class SkAutoMutexAcquire {
public:
    SkAutoMutexAcquire(std::mutex& mutex) {}
};

class SkMask {
public:
    enum Format {
        kA8_Format
    };
};

class SkPaint {
public:
    enum Hinting {
        kNo_Hinting,
        kSlight_Hinting,
        kNormal_Hinting,
        kFull_Hinting
    };
};

class SkScalerContext {
public:
    enum Flags {
        kSubpixelPositioning_Flag
    };
};

class SkScalerContextRec {
public:
    SkScalar fTextSize;
    SkMask::Format fMaskFormat;
    unsigned fFlags;

    SkPaint::Hinting getHinting() const;
    void setHinting(SkPaint::Hinting h);
    void ignorePreBlend();
};

class FTLibrary {
public:
    bool isLCDSupported() const;
};

std::mutex gFTMutex;
FTLibrary* gFTLibrary;

void ref_ft_library();
void unref_ft_library();

bool isLCD(const SkScalerContextRec& rec);
bool isAxisAligned(const SkScalerContextRec& rec);

SkScalar SkIntToScalar(int value);