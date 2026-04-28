#include <vector>
#include <memory>
#include <algorithm>
#include <cstdint>

struct GifColorType {
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
};

struct ColorMapObject {
    int ColorCount;
    GifColorType* Colors;
};

struct SavedImage {
    ColorMapObject* ColorMap;
    int Width;
    int Height;
    int Top;
    int Left;
};

struct GifFileType {
    SavedImage Image;
    ColorMapObject* SColorMap;
};

struct ImageSpec {
    int width;
    int height;
    int nchannels;
    int get_int_attribute(const char*);
};

class GIFInput {
public:
    bool read_subimage_data();
private:
    GifFileType* m_gif_file;
    int m_subimage;
    int m_previous_disposal_method;
    int m_transparent_color;
    std::vector<uint8_t> m_canvas;
    ImageSpec m_spec;
};

enum {
    DISPOSE_BACKGROUND,
    GIF_ERROR
};

int DGifGetLine(GifFileType*, uint8_t*, int);
void errorf(const char*);
void errorfmt(const char*, ...);
void report_last_error();
int decode_line_number(int, int);