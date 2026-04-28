#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char Guchar;
typedef int GBool;

enum GfxColorSpaceMode {
    csDeviceRGB,
    csICCBased
};

class GfxState {
public:
    double* getCTM();
};

class Object {};
class Stream {};

class GfxColorSpace {
public:
    virtual GfxColorSpaceMode getMode() = 0;
};

class GfxICCBasedColorSpace : public GfxColorSpace {
public:
    virtual GfxColorSpace* getAlt() = 0;
};

class GfxImageColorMap {
public:
    virtual int getNumPixelComps() = 0;
    virtual int getBits() = 0;
    virtual GfxColorSpace* getColorSpace() = 0;
    virtual void getRGBLine(Guchar* pix, unsigned int* dest, int width) = 0;
};

class ImageStream {
public:
    ImageStream(Stream* str, int width, int numComps, int bits);
    ~ImageStream();
    void reset();
    Guchar* getLine();
};

class QImage {
public:
    enum Format {
        Format_ARGB32,
        Format_RGB32
    };
    QImage(unsigned char* data, int width, int height, Format format);
    ~QImage();
    bool isNull();
};

class QMatrix {
public:
    void setMatrix(double m11, double m12, double m21, double m22, double dx, double dy);
};

class QPoint {
public:
    QPoint(int x, int y);
};

class QPainter {
public:
    void setMatrix(const QMatrix& matrix, bool combine);
    void drawImage(const QPoint& point, const QImage& image);
};

class QDebug {
public:
    QDebug();
    QDebug& operator<<(const char* message);
};

class ArthurOutputDev {
private:
    QImage* m_image;
    QPainter* m_painter;
public:
    void drawImage(GfxState* state, Object* ref, Stream* str, int width, int height,
                  GfxImageColorMap* colorMap, int* maskColors, GBool inlineImg);
};

extern void* gmallocn3(int a, int b, int c);
extern void* gmalloc(int size);
extern QDebug qDebug();