#include <cassert>
#include <limits>
#include <memory>

#define STANDARD_ALIGNMENT 32

enum de265_error {
    DE265_OK,
    DE265_ERROR_OUT_OF_MEMORY
};

enum de265_chroma {
    de265_chroma_mono,
    de265_chroma_420,
    de265_chroma_422,
    de265_chroma_444
};

enum de265_image_format {
    de265_image_format_YUV420P8,
    de265_image_format_YUV422P8,
    de265_image_format_YUV444P8,
    de265_image_format_mono8
};

struct de265_image_spec {
    de265_image_format format;
    int width;
    int height;
    int alignment;
    int crop_left;
    int crop_right;
    int crop_top;
    int crop_bottom;
    int visible_width;
    int visible_height;
};

struct seq_parameter_set {
    int SubWidthC;
    int SubHeightC;
    int conf_win_left_offset;
    int conf_win_right_offset;
    int conf_win_top_offset;
    int conf_win_bottom_offset;
    int BitDepth_Y;
    int BitDepth_C;
    int PicWidthInMinPUs;
    int PicHeightInMinPUs;
    int Log2MinPUSize;
    int PicWidthInMinCbsY;
    int PicHeightInMinCbsY;
    int Log2MinCbSizeY;
    int PicWidthInTbsY;
    int PicHeightInTbsY;
    int Log2MinTrafoSize;
    int pic_width_in_luma_samples;
    int pic_height_in_luma_samples;
    int PicWidthInCtbsY;
    int PicHeightInCtbsY;
    int Log2CtbSizeY;
    int PicSizeInCtbsY;
};

struct de265_progress_lock {};

struct decoder_context;

struct ImageAllocFuncs {
    bool (*get_buffer)(struct decoder_context*, struct de265_image_spec*, void*, void*);
};

struct decoder_context {
    void* param_image_allocation_userdata;
    ImageAllocFuncs param_image_allocation_functions;
};

typedef int64_t de265_PTS;

struct de265_image {
    static int s_next_image_ID;
    static ImageAllocFuncs default_image_allocation;

    de265_error alloc_image(int w, int h, enum de265_chroma c,
                          std::shared_ptr<const seq_parameter_set> sps, bool allocMetadata,
                          decoder_context* dctx, de265_PTS pts, void* user_data,
                          bool useCustomAllocFunc);
    void release();
    std::shared_ptr<const seq_parameter_set> sps;
    decoder_context* decctx;
    enum de265_chroma chroma_format;
    int width;
    int height;
    int chroma_width;
    int chroma_height;
    void* user_data;
    de265_PTS pts;
    int SubWidthC;
    int SubHeightC;
    int width_confwin;
    int height_confwin;
    int chroma_width_confwin;
    int chroma_height_confwin;
    int BitDepth_Y;
    int BitDepth_C;
    int bpp_shift[3];
    ImageAllocFuncs image_allocation_functions;
    unsigned char* pixels[3];
    unsigned char* pixels_confwin[3];
    int stride;
    int chroma_stride;
    int ID;
    int32_t removed_at_picture_id;
    struct {
        int width_in_units;
        int height_in_units;
        int data_size;
        bool alloc(int, int, int);
    } ctb_info;
    de265_progress_lock* ctb_progress;
    struct {
        bool alloc(int, int, int);
    } intraPredMode;
    struct {
        bool alloc(int, int, int);
    } intraPredModeC;
    struct {
        bool alloc(int, int, int);
    } cb_info;
    struct {
        bool alloc(int, int, int);
    } pb_info;
    struct {
        bool alloc(int, int, int);
    } tu_info;
    struct {
        bool alloc(int, int, int);
    } deblk_info;
};

int de265_image::s_next_image_ID = 0;
ImageAllocFuncs de265_image::default_image_allocation = {nullptr};