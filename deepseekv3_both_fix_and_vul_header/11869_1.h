#include <stdlib.h>
#include <string.h>
#include <exception>
#include <cstdio>
#include <algorithm>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef unsigned short ushort;

struct libraw_decoder_info_t {
    int decoder_flags;
};

struct LibRaw_exceptions {
    int code;
};

struct LibRaw {
    struct {
        struct {
            void *input;
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
            void *internal_output_params;
        } internal_output_params;
    } libraw_internal_data;
    
    struct {
        struct {
            void *raw_alloc;
            ushort *raw_image;
            ushort (*color4_image)[4];
            ushort (*color3_image)[3];
            float *float_image;
            float (*float3_image)[3];
            struct {
                int raw_width;
                int raw_height;
            } sizes;
            void *color;
            void *iparams;
            void *ioparams;
        } rawdata;
        ushort (*image)[4];
        struct {
            int dng_version;
            int raw_count;
            char *software;
            char *make;
            char *model;
            int filters;
        } idata;
        struct {
            int raw_width;
            int raw_height;
        } sizes;
        void *color;
    } imgdata;
    
    struct {
        int shot_select;
        int use_rawspeed;
        int raw_processing_options;
    } O;
    
    struct {
        int raw_count;
        int colors;
    } P1;
    
    struct {
        int iwidth;
        int iheight;
        int raw_width;
        int raw_height;
        int width;
        int height;
        int left_margin;
        int top_margin;
        int raw_pitch;
    } S;
    
    struct {
        int shrink;
        int fuji_width;
    } IO;
    
    struct {
        int maximum;
        int cblack[4];
        int black;
    } C;
    
    struct {
        struct {
            int (*seek)(size_t, int);
        } *input;
    } ID;
    
    int (LibRaw::*load_raw)();
    void *dnghost;
    void *_rawspeed_camerameta;
    
    int unpack();
    void get_decoder_info(libraw_decoder_info_t *);
    int raw_was_read();
    void crop_masked_pixels();
    int try_rawspeed();
    int try_dngsdk();
    int is_sraw();
    int valid_for_dngsdk();
    int packed_load_raw();
    int unpacked_load_raw();
    int pentax_4shot_load_raw();
};

enum {
    LIBRAW_PROGRESS_LOAD_RAW,
    LIBRAW_PROGRESS_IDENTIFY,
    LIBRAW_INPUT_CLOSED,
    LIBRAW_REQUEST_FOR_NONEXISTENT_IMAGE,
    LIBRAW_UNSPECIFIED_ERROR,
    LIBRAW_EXCEPTION_IO_CORRUPT,
    LIBRAW_PROCESSING_SRAW_NO_RGB,
    LIBRAW_PROCESSING_SRAW_NO_INTERPOLATE,
    LIBRAW_DECODER_TRYRAWSPEED,
    LIBRAW_DECODER_OWNALLOC,
    LIBRAW_DECODER_ADOBECOPYPIXEL,
    LIBRAW_DECODER_LEGACY_WITH_MARGINS
};

#define SEEK_SET 0
#define CHECK_ORDER_HIGH(x)
#define CHECK_ORDER_LOW(x)
#define RUN_CALLBACK(x, y, z)
#define SET_PROC_FLAG(x)
#define EXCEPTION_HANDLER(x)
#define merror(x, y)
#define USE_DNGSDK
#define USE_RAWSPEED