#include <assert.h>
#include <stddef.h>

typedef unsigned char uchar;

#define CV_IMPL
#define CV_FUNCNAME(name)
#define __BEGIN__
#define __END__
#define CV_CALL(func) func
#define CV_ERROR(code, msg)
#define CV_Assert(expr) assert(expr)
#define CV_BadNumChannels 0
#define CV_BadDepth 0
#define CV_StsUnsupportedFormat 0
#define CV_CVTIMG_SWAP_RB 1
#define CV_CVTIMG_FLIP 2
#define CV_8U 0
#define CV_8S 1
#define CV_16S 2
#define CV_32S 3
#define CV_MAT_CN_MASK 0
#define CV_MAT_DEPTH_MASK 0
#define CV_IS_MAT_CONT(flags) 0
#define CV_ARE_DEPTHS_EQ(mat1, mat2) 0
#define CV_ARE_CNS_EQ(mat1, mat2) 0
#define CV_MAT_CN(type) 0
#define CV_MAT_DEPTH(type) 0

typedef struct CvArr CvArr;
typedef struct CvMat {
    int type;
    int height;
    int width;
    int step;
    union {
        uchar* ptr;
    } data;
    int cols;
    int rows;
} CvMat;

typedef struct CvSize {
    int width;
    int height;
    CvSize(int w, int h) : width(w), height(h) {}
} CvSize;

CvMat* cvGetMat(const CvArr* arr, CvMat* mat);
void cvConvertScale(const CvMat* src, CvMat* dst, double scale, double shift);
void cvFlip(const CvMat* src, CvMat* dst, int flip_mode);
void cvCopy(const CvMat* src, CvMat* dst);
void cvReleaseMat(CvMat** mat);
CvMat* cvCreateMat(int height, int width, int type);

void icvCvt_Gray2BGR_8u_C1C3R(uchar* src, int src_step, uchar* dst, int dst_step, CvSize size);
void icvCvt_BGR2Gray_8u_C3C1R(uchar* src, int src_step, uchar* dst, int dst_step, CvSize size, int swap_rb);
void icvCvt_RGB2BGR_8u_C3R(uchar* src, int src_step, uchar* dst, int dst_step, CvSize size);
void icvCvt_BGRA2Gray_8u_C4C1R(uchar* src, int src_step, uchar* dst, int dst_step, CvSize size, int swap_rb);
void icvCvt_BGRA2BGR_8u_C4C3R(uchar* src, int src_step, uchar* dst, int dst_step, CvSize size, int swap_rb);