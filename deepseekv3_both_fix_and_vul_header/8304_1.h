#include <stdint.h>

enum { ImageBitmapTag };

class SerializedScriptValueWriter {
public:
    void append(uint32_t value);
    void doWriteImageData(uint32_t width, uint32_t height, const uint8_t* pixelData, uint32_t pixelDataLength);
    void writeImageBitmap(uint32_t width, uint32_t height, uint32_t isOriginClean, const uint8_t* pixelData, uint32_t pixelDataLength);
    void writeImageBitmap(uint32_t width, uint32_t height, const uint8_t* pixelData, uint32_t pixelDataLength);
};