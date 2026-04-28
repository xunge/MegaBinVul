#include <setjmp.h>
#include <string.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE* JSAMPROW;
typedef JSAMPROW* JSAMPARRAY;
typedef void* j_common_ptr;
typedef unsigned char uchar;

struct JHUFF_TBL {
    void* dummy;
};

struct jpeg_error_mgr {
    void* dummy;
};

struct jpeg_memory_mgr {
    JSAMPARRAY (*alloc_sarray)(j_common_ptr, int, int, int);
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr* err;
    struct jpeg_memory_mgr* mem;
    JHUFF_TBL* ac_huff_tbl_ptrs[2];
    JHUFF_TBL* dc_huff_tbl_ptrs[2];
    int num_components;
    int out_color_space;
    int out_color_components;
};

struct JpegErrorMgr {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

struct JpegState {
    struct jpeg_decompress_struct cinfo;
    JpegErrorMgr jerr;
};

struct Size {
    int width;
    int height;
    Size(int w, int h) : width(w), height(h) {}
};

struct Mat {
    int step;
    int channels();
    uchar* ptr();
    Size size() const { return Size(0,0); }
};

struct JpegDecoder {
    void* m_state;
    int m_width;
    int m_height;
    void close();
    bool readData(Mat& img);
};

enum {
    JCS_UNKNOWN,
    JCS_GRAYSCALE,
    JCS_RGB,
    JCS_CMYK,
    JPOOL_IMAGE
};

inline Size cvSize(int width, int height) {
    return Size(width, height);
}

extern void my_jpeg_load_dht(struct jpeg_decompress_struct*, const unsigned char*,
                            struct JHUFF_TBL**, struct JHUFF_TBL**);
extern const unsigned char my_jpeg_odml_dht[];
extern void icvCvt_RGB2BGR_8u_C3R(const uchar*, int, uchar*, int, Size);
extern void icvCvt_CMYK2BGR_8u_C4C3R(const uchar*, int, uchar*, int, Size);
extern void icvCvt_CMYK2Gray_8u_C4C1R(const uchar*, int, uchar*, int, Size);
extern void jpeg_start_decompress(struct jpeg_decompress_struct*);
extern void jpeg_finish_decompress(struct jpeg_decompress_struct*);
extern int jpeg_read_scanlines(struct jpeg_decompress_struct*, JSAMPARRAY, int);