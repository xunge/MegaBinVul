#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef uint32_t tdata_t;
typedef uint32_t uint32;
typedef uint16_t uint16;

#define GX_DEVICE_COLOR_MAX_COMPONENTS 16
#define GS_CLIENT_COLOR_MAX_COMPONENTS 16
#define NUM_CMYK_COMPONENTS 4
#define MAX_COLOR_VALUE 255
#define SUFFIX_SIZE 4
#define COMPRESSION_NONE 1

typedef struct {
    int num_std_colorant_names;
    int num_separation_order_names;
    struct {
        int num_separations;
    } separations;
    int* separation_order_map;
} devn_params_t;

typedef struct {
    int downscale_factor;
    int min_feature_size;
    int trap_w;
    int trap_h;
    int trap_order;
} downscale_params_t;

typedef struct gx_device_printer_s {
    void* memory;
    char* fname;
    char* dname;
    struct {
        int depth;
        int num_components;
    } color_info;
} gx_device_printer;

typedef struct gx_device_s gx_device;

typedef struct tiffsep_device_s {
    devn_params_t devn_params;
    downscale_params_t downscale;
    int BitsPerComponent;
    int width;
    int height;
    bool UseBigTIFF;
    bool BigEndian;
    bool NoSeparationFiles;
    bool PrintSpotCMYK;
    int Compression;
    int MaxStripSize;
    bool write_datetime;
    int PageCount;
    char* fname;
    char* dname;
    void* comp_file;
    void* tiff_comp;
    void* sep_file[16];
    void* tiff[16];
    void* memory;
    void* equiv_cmyk_colors;
    struct {
        int num_components;
    } color_info;
} tiffsep_device;

typedef struct gp_file_s gp_file;

typedef struct gs_parsed_file_name_s {
    // Minimal definition since actual structure is not known
    char dummy;
} gs_parsed_file_name_t;

typedef struct gx_downscaler_s {
    // Minimal definition since actual structure is not known
    int dummy;
} gx_downscaler_t;

typedef struct {
    int options;
    int x_offset;
    int raster;
    byte* data[16];
} gs_get_bits_params_t;

typedef struct {
    int components[4];
} cmyk_composite_map;

#define GB_RETURN_POINTER (1 << 0)
#define GB_RETURN_COPY (1 << 1)
#define GB_ALIGN_STANDARD (1 << 2)
#define GB_OFFSET_0 (1 << 3)
#define GB_RASTER_STANDARD (1 << 4)
#define GB_PACKING_PLANAR (1 << 5)
#define GB_COLORS_NATIVE (1 << 6)
#define GB_ALPHA_NONE (1 << 7)

#define gs_error_VMerror (-1)
#define gs_error_ioerror (-2)
#define gs_error_rangecheck (-3)
#define gs_error_invalidfileaccess (-4)

#define return_error(code) return (code)

size_t gp_file_name_sizeof;
long gp_ftell(gp_file* file);

void* gs_alloc_bytes(void* memory, size_t size, const char* cname);
void gs_free_object(void* memory, void* ptr, const char* cname);
void dmlprintf1(void* memory, const char* fmt, const char* arg);
void dmprintf(void* memory, const char* fmt);
void emprintf(void* memory, const char* fmt);
void dmlprintf(void* memory, const char* fmt);
int gs_note_error(int code);

int TIFFWriteScanline(void* tif, tdata_t buf, uint32 row, uint16 sample);
void TIFFCheckpointDirectory(void* tif);
int TIFFWriteDirectory(void* tif);

int length_base_file_name(tiffsep_device* dev, bool* double_f);
int copy_separation_name(tiffsep_device* dev, char* name, int size, int sep_num, int flag);
int gx_parse_output_file_name(gs_parsed_file_name_t* parsed, const char** fmt, const char* fname, size_t len, void* memory);
int gx_device_open_output_file(gx_device_printer* device, const char* fname, bool binary, bool seekable, gp_file** file);
void* tiff_from_filep(gx_device_printer* pdev, const char* name, gp_file* file, bool big_endian, bool use_big_tiff);
int tiff_set_fields_for_printer(gx_device_printer* pdev, void* tiff, int factor, int flag, bool write_datetime);
int tiff_set_cmyk_fields(gx_device_printer* pdev, void* tiff, int bpc, int compression, int max_strip_size);
int tiff_set_gray_fields(gx_device_printer* pdev, void* tiff, int bpc, int compression, int max_strip_size);
int number_output_separations(int num_components, int num_std_colorants, int num_order, int num_spot);
int create_separation_file_name(tiffsep_device* dev, char* name, int size, int sep_num, bool flag);
int tiffsep_close_sep_file(tiffsep_device* dev, const char* name, int comp_num);
int gs_remove_outputfile_control_path(void* memory, const char* name);
int gs_add_outputfile_control_path(void* memory, const char* name);
void build_cmyk_map(gx_device_printer* device, int num_comp, void* colors, cmyk_composite_map* map);
int print_cmyk_equivalent_colors(tiffsep_device* dev, int num_comp, cmyk_composite_map* map);
int bitmap_raster(int width);
int gx_downscaler_init_planar_trapped(gx_downscaler_t* ds, gx_device_printer* device, gs_get_bits_params_t* params, int num_comp, int factor, int mfs, int src_bpc, int dst_bpc, int trap_w, int trap_h, int trap_order);
int gx_downscaler_get_bits_rectangle(gx_downscaler_t* ds, gs_get_bits_params_t* params, int y);
void gx_downscaler_fin(gx_downscaler_t* ds);
int gx_downscaler_scale(int size, int factor);
void build_cmyk_raster_line_fromplanar(gs_get_bits_params_t* params, byte* sep_line, int width, int num_comp, cmyk_composite_map* map, int num_order, tiffsep_device* dev);
void build_cmyk_raster_line_fromplanar_4bpc(gs_get_bits_params_t* params, byte* sep_line, int width, int num_comp, cmyk_composite_map* map, int num_order, tiffsep_device* dev);
void build_cmyk_raster_line_fromplanar_2bpc(gs_get_bits_params_t* params, byte* sep_line, int width, int num_comp, cmyk_composite_map* map, int num_order, tiffsep_device* dev);
void build_cmyk_raster_line_fromplanar_1bpc(gs_get_bits_params_t* params, byte* sep_line, int width, int num_comp, cmyk_composite_map* map, int num_order, tiffsep_device* dev);
int tiffsep_close_comp_file(tiffsep_device* dev, const char* fname);