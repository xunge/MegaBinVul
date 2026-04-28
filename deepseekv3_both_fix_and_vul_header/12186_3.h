#include <memory>
#include <algorithm>
#include <vector>

struct GifColorType {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
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

enum {
    DISPOSE_BACKGROUND,
    GIF_ERROR
};

class GIFInput {
public:
    bool read_subimage_data();
    
private:
    GifFileType* m_gif_file;
    int m_subimage;
    int m_previous_disposal_method;
    std::vector<unsigned char> m_canvas;
    int m_transparent_color;
    struct ImageSpec {
        int width;
        int height;
        int nchannels;
        int get_int_attribute(const char*) const { return 0; }
    } m_spec;
    
    void errorf(const char*) {}
    void errorfmt(const char*, ...) {}
    void report_last_error() {}
    int decode_line_number(int, int) { return 0; }
    int DGifGetLine(GifFileType*, unsigned char*, int) { return 0; }
};