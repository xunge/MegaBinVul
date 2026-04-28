#include <stdlib.h>
#include <string.h>
#include <exception>
#include <stdio.h>

typedef unsigned short ushort;

#define SEEK_SET 0

struct libraw_decoder_info_t {
    int decoder_flags;
};

struct libraw_internal_data_t {
    struct {
        char *input;
        char *meta_data;
    } internal_data;
    struct {
        size_t meta_length;
        int load_flags;
        int tiff_samples;
        int tiff_bps;
        size_t data_offset;
    } unpacker_data;
    struct {
        int internal_output_params;
    } internal_output_params;
};

struct imgdata_color_t {
    int cblack[4];
    int black;
    int maximum;
};

struct imgdata_sizes_t {
    int raw_width;
    int raw_height;
    int width;
    int height;
    int left_margin;
    int top_margin;
    int iwidth;
    int iheight;
    int raw_pitch;
};

struct imgdata_idata_t {
    char make[32];
    char model[32];
    int dng_version;
    int filters;
    int colors;
    int raw_count;
};

struct imgdata_rawdata_t {
    void *raw_alloc;
    ushort *raw_image;
    ushort (*color4_image)[4];
    ushort (*color3_image)[3];
    float *float_image;
    float (*float3_image)[3];
    imgdata_color_t color;
    imgdata_sizes_t sizes;
    imgdata_idata_t iparams;
    int ioparams;
};

struct imgdata_t {
    ushort (*image)[4];
    imgdata_rawdata_t rawdata;
    imgdata_idata_t idata;
    imgdata_sizes_t sizes;
    imgdata_color_t color;
};

struct options_t {
    int shot_select;
    int use_rawspeed;
    int raw_processing_options;
};

struct libraw_io_t {
    int shrink;
    int fuji_width;
    int (*seek)(size_t, int);
};

enum LibRaw_exceptions {
    LIBRAW_EXCEPTION_IO_CORRUPT
};

enum {
    LIBRAW_PROGRESS_LOAD_RAW,
    LIBRAW_PROGRESS_IDENTIFY,
    LIBRAW_INPUT_CLOSED,
    LIBRAW_REQUEST_FOR_NONEXISTENT_IMAGE,
    LIBRAW_UNSPECIFIED_ERROR,
    LIBRAW_DECODER_TRYRAWSPEED,
    LIBRAW_DECODER_OWNALLOC,
    LIBRAW_DECODER_LEGACY_WITH_MARGINS,
    LIBRAW_DECODER_ADOBECOPYPIXEL,
    LIBRAW_PROCESSING_SRAW_NO_RGB,
    LIBRAW_PROCESSING_SRAW_NO_INTERPOLATE
};

class LibRaw {
public:
    libraw_internal_data_t libraw_internal_data;
    imgdata_t imgdata;
    options_t O;
    struct {
        int raw_count;
        int colors;
    } P1;
    imgdata_sizes_t S;
    libraw_io_t IO;
    imgdata_color_t C;
    struct {
        struct {
            int (*seek)(size_t, int);
        } *input;
    } ID;
    void *dnghost;
    void *_rawspeed_camerameta;

    typedef int (LibRaw::*load_raw_func)();
    load_raw_func load_raw;

    void get_decoder_info(libraw_decoder_info_t *);
    int unpacked_load_raw();
    int packed_load_raw();
    int pentax_4shot_load_raw();
    int try_dngsdk();
    int try_rawspeed();
    int raw_was_read();
    int is_sraw();
    void crop_masked_pixels();
    int valid_for_dngsdk();
    int unpack();
};

#define CHECK_ORDER_HIGH(x)
#define CHECK_ORDER_LOW(x)
#define RUN_CALLBACK(x, y, z)
#define SET_PROC_FLAG(x)
#define EXCEPTION_HANDLER(x)
#define merror(x, y)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define USE_DNGSDK
#define USE_RAWSPEED