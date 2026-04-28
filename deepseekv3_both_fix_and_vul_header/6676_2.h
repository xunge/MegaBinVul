#include <stdint.h>
#include <algorithm>
#include <stdio.h>

typedef uint32_t GifWord;
typedef uint32_t Color8888;

#define NO_TRANSPARENT_COLOR (-1)
#define DISPOSE_BACKGROUND 2
#define DISPOSE_PREVIOUS 3
#define TRANSPARENT 0

#define ALOGD printf
#define ALOGW printf
#define GIF_DEBUG 1

struct ColorMapObject {
    int ColorCount;
    int BitsPerPixel;
    uint8_t* Colors;
};

struct GifImageDesc {
    int Left;
    int Top;
    int Width;
    int Height;
    ColorMapObject* ColorMap;
};

struct SavedImage {
    GifImageDesc ImageDesc;
    unsigned char* RasterBits;
};

struct GraphicsControlBlock {
    int TransparentColor;
    int DisposalMode;
    int DelayTime;
};

struct GifFileType {
    int ImageCount;
    SavedImage* SavedImages;
    ColorMapObject* SColorMap;
};

class FrameSequenceState_gif {
public:
    long drawFrame(int frameNr, Color8888* outputPtr, int outputPixelStride, int previousFrameNr);
private:
    struct {
        GifFileType* getGif();
        int getHeight();
        int getWidth();
        Color8888 getBackgroundColor();
        int getRestoringFrame(int i);
        int getPreservedFrame(int i);
    } mFrameSequence;
    int mPreserveBufferFrame;
};

using std::max;

bool willBeCleared(const GraphicsControlBlock& gcb);
bool checkIfCover(const GifImageDesc& frame, const GifImageDesc& prevFrame);
void getCopySize(const GifImageDesc& desc, int width, int height, GifWord& copyWidth, GifWord& copyHeight);
void setLineColor(Color8888* dst, Color8888 color, GifWord width);
void restorePreserveBuffer(Color8888* outputPtr, int outputPixelStride);
void savePreserveBuffer(Color8888* outputPtr, int outputPixelStride, int frameNr);
void copyLine(Color8888* dst, const unsigned char* src, const ColorMapObject* cmap, int transparentColor, GifWord width);
long getDelayMs(const GraphicsControlBlock& gcb);
int DGifSavedExtensionToGCB(GifFileType* gif, int i, GraphicsControlBlock* gcb);