#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <memory>

typedef unsigned char uchar;

struct Size {
    int height;
    int width;
};

struct Mat {
    int channels();
    uchar* ptr();
    size_t step;
    int type();
    int depth();
    Size size();
    bool empty();
    void create(int height, int width, int type);
};

struct Error {
    enum {
        StsError
    };
};

#define CV_Error(code, msg) fprintf(stderr, "%s\n", msg)
#define CV_Assert(expr) ((void)0)

struct Jpeg2KDecoder {
    void* m_stream;
    void* m_image;
    int type();
    void close();
    bool readData(Mat& img);
    bool readComponent8u(uchar* data, void* buffer, int step, int cmptlut, int maxval, int offset, int ncmpts);
    bool readComponent16u(unsigned short* data, void* buffer, int step, int cmptlut, int maxval, int offset, int ncmpts);
};

template<typename T>
struct Ptr {
    Ptr(T* p, void(*d)(T*)) : ptr(p), deleter(d) {}
    ~Ptr() { if (deleter) deleter(ptr); }
    T* ptr;
    void(*deleter)(T*);
};

void Jpeg2KDecoder_close(Jpeg2KDecoder*);

typedef void jas_stream_t;
typedef void jas_image_t;
typedef void jas_cmprof_t;
typedef void jas_matrix_t;

#define CV_MAT_CN(type) ((type) & 7)
#define CV_8U 0
#define CV_16U 2

enum {
    JAS_CLRSPC_SRGB,
    JAS_CLRSPC_FAM_GRAY,
    JAS_CLRSPC_SGRAY,
    JAS_IMAGE_CT_RGB_R,
    JAS_IMAGE_CT_RGB_G,
    JAS_IMAGE_CT_RGB_B,
    JAS_IMAGE_CT_GRAY_Y,
    JAS_CMXFORM_INTENT_RELCLR
};

#define COLOR_BGR2GRAY 6

int jas_image_clrspc(jas_image_t* image);
int jas_clrspc_fam(int clrspc);
jas_cmprof_t* jas_cmprof_createfromclrspc(int colorspace);
jas_image_t* jas_image_chclrspc(jas_image_t* image, jas_cmprof_t* clrprof, int intent);
void jas_image_destroy(jas_image_t* image);
void jas_cmprof_destroy(jas_cmprof_t* clrprof);
int jas_image_getcmptbytype(jas_image_t* image, int cmpttype);
int jas_image_cmptprec(jas_image_t* image, int cmptno);
int jas_image_cmptsgnd(jas_image_t* image, int cmptno);
int jas_image_cmptbry(jas_image_t* image, int cmptno);
int jas_image_cmptvstep(jas_image_t* image, int cmptno);
int jas_image_cmptbrx(jas_image_t* image, int cmptno);
int jas_image_cmpthstep(jas_image_t* image, int cmptno);
jas_matrix_t* jas_matrix_create(int numrows, int numcols);
int jas_image_readcmpt(jas_image_t* image, int cmptno, int x, int y, int width, int height, jas_matrix_t* data);
void jas_matrix_destroy(jas_matrix_t* matrix);

inline int validateToInt(size_t val) { return static_cast<int>(val); }

namespace cv {
    void cvtColor(const Mat& src, Mat& dst, int code);
}