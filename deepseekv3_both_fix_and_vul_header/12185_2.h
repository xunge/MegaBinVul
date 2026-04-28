#include <stdbool.h>
#include <vector>
#include <memory>
#include <algorithm>

typedef struct GifColorType {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} GifColorType;

typedef struct ColorMapObject {
    int ColorCount;
    GifColorType* Colors;
} ColorMapObject;

typedef struct SavedImage {
    ColorMapObject* ColorMap;
    int Width;
    int Height;
    int Top;
    int Left;
} SavedImage;

typedef struct GifFileType {
    SavedImage Image;
    ColorMapObject* SColorMap;
} GifFileType;

enum {
    DISPOSE_BACKGROUND,
    GIF_ERROR
};

class GIFInput {
public:
    GifFileType* m_gif_file;
    int m_subimage;
    int m_previous_disposal_method;
    int m_transparent_color;
    std::vector<unsigned char> m_canvas;

    struct ImageSpec {
        int width;
        int height;
        int nchannels;
        int get_int_attribute(const char*);
    } m_spec;

    bool read_subimage_data();
};

int DGifGetLine(GifFileType*, unsigned char*, int);
void report_last_error();
void errorf(const char*);
void errorfmt(const char*, ...);
int decode_line_number(int, int);