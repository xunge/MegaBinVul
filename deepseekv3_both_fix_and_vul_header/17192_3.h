#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t utf16_t;

struct x3f_header_t {
    int rotation;
};

struct x3f_image_data_t {
    int columns;
    int rows;
};

struct x3f_property_t {
    utf16_t *name;
    utf16_t *value;
};

struct x3f_property_table_t {
    size_t size;
    x3f_property_t *element;
};

struct x3f_property_list_t {
    void *data;
    uint32_t data_size;
    int num_properties;
    x3f_property_table_t property_table;
};

struct x3f_data_subsection_t {
    union {
        x3f_image_data_t image_data;
        x3f_property_list_t property_list;
    };
};

struct x3f_directory_entry_header_t {
    x3f_data_subsection_t data_subsection;
};

struct x3f_directory_entry_t {
    x3f_directory_entry_header_t header;
    struct {
        size_t offset;
    } input;
};

struct x3f_directory_section_t {
    // Placeholder for directory section
};

struct x3f_t {
    x3f_header_t header;
    x3f_directory_section_t directory_section;
};

struct LibRaw_IO {
    virtual int tell() = 0;
    virtual void seek(int pos, int whence) = 0;
    virtual int read(void *buf, size_t size, size_t count) = 0;
};

struct libraw_internal_data_t {
    struct {
        LibRaw_IO *input;
        size_t toffset;
    } internal_data;
    struct {
        int raw_color;
    } internal_output_params;
    struct {
        int order;
    } unpacker_data;
};

struct libraw_data_t {
    struct {
        int flip;
        int raw_width;
        int raw_height;
        int raw_pitch;
    } sizes;
    struct {
        int raw_count;
        int is_foveon;
        char make[64];
        char model[64];
    } idata;
    struct {
        float iso_speed;
        int timestamp;
        float shutter;
        float aperture;
        float focal_len;
        float SensorTemperature;
    } other;
    struct {
        char model2[64];
        int maximum;
    } color;
    struct {
        char BodySerial[64];
    } shootinginfo;
    struct {
        struct {
            int twidth;
            int theight;
            int tcolors;
            int tformat;
        } thumbnail;
    };
    struct {
        struct {
            float MaxAp4CurFocal;
            float MinAp4CurFocal;
            float MinFocal;
            float MaxFocal;
            int LensID;
            int LensMount;
            float FocalLengthIn35mmFormat;
        } makernotes;
    } lens;
};

enum LibRaw_thumbnail_formats {
    LIBRAW_THUMBNAIL_UNKNOWN,
    LIBRAW_THUMBNAIL_JPEG,
    LIBRAW_THUMBNAIL_BITMAP
};

class LibRaw {
public:
    void parse_x3f();
    void x3f_load_raw();
    void x3f_thumb_loader();
};

extern libraw_data_t imgdata;
extern libraw_internal_data_t libraw_internal_data;
extern void *_x3f_data;
extern void (LibRaw::*load_raw)();
extern void (LibRaw::*write_thumb)();

#define X3F_OK 0
#define LIBRAW_EXCEPTION_IO_CORRUPT 1
#define Sigma_X3F 1

#define MIN(a,b) ((a) < (b) ? (a) : (b))

extern x3f_t *x3f_new_from_file(LibRaw_IO *input);
extern x3f_directory_entry_t *x3f_get_raw(x3f_t *x3f);
extern x3f_directory_entry_t *x3f_get_prop(x3f_t *x3f);
extern int x3f_load_data(x3f_t *x3f, x3f_directory_entry_t *DE);
extern x3f_directory_entry_t *x3f_get_thumb_jpeg(x3f_t *x3f);
extern x3f_directory_entry_t *x3f_get_thumb_plain(x3f_t *x3f);
extern void utf2char(utf16_t *src, char *dst, int maxlen);
extern void *lr_memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen);

#define my_swap(type,a,b) {type _temp=(a);(a)=(b);(b)=_temp;}