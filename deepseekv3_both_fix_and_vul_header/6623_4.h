#include <stdbool.h>
#include <string>

struct jas_stream_t;
struct jas_image_t;

class Jpeg2KDecoder {
public:
    std::string m_filename;
    jas_stream_t* m_stream;
    jas_image_t* m_image;
    int m_width;
    int m_height;
    int m_type;

    bool readHeader();
    void close();
};

extern "C" {
    jas_stream_t* jas_stream_fopen(const char *filename, const char *mode);
    jas_image_t* jas_image_decode(jas_stream_t *in, int fmt, const char *optstr);
    int jas_image_width(jas_image_t *image);
    int jas_image_height(jas_image_t *image);
    int jas_image_numcmpts(jas_image_t *image);
    int jas_image_cmptprec(jas_image_t *image, int cmptno);
    int jas_image_cmpttype(jas_image_t *image, int cmptno);
    int jas_image_cmptsgnd(jas_image_t *image, int cmptno);
    int jas_image_cmpttlx(jas_image_t *image, int cmptno);
    int jas_image_cmptbrx(jas_image_t *image, int cmptno);
    int jas_image_cmpthstep(jas_image_t *image, int cmptno);
    int jas_image_cmpttly(jas_image_t *image, int cmptno);
    int jas_image_cmptbry(jas_image_t *image, int cmptno);
    int jas_image_cmptvstep(jas_image_t *image, int cmptno);
    int jas_image_tlx(jas_image_t *image);
    int jas_image_tly(jas_image_t *image);
}

#define CV_Assert(expr) ((void)0)
#define CV_MAKETYPE(depth, channels) ((depth) | ((channels) << 3))
#define CV_8U 0
#define CV_16U 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))