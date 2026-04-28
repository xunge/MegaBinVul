#include <cstdio>
#include <cstring>
#include <cerrno>
#include <vector>
#include <setjmp.h>
#include <string>
#include <cstdint>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define JCS_YCbCr 2
#define JPEG_APP0 0xE0
#define JPEG_XMP_MARKER (JPEG_APP0 + 1)
#define MAX_BYTES_IN_MARKER 65533
#define JPOOL_IMAGE 0

typedef unsigned char JSAMPLE;
typedef JSAMPLE* JSAMPROW;
typedef JSAMPROW* JSAMPARRAY;
typedef int JDIMENSION;
typedef unsigned char JOCTET;
typedef int boolean;

enum heif_channel {
    heif_channel_Y,
    heif_channel_Cb,
    heif_channel_Cr
};

struct jpeg_common_struct;
typedef jpeg_common_struct* j_common_ptr;

struct jpeg_error_mgr {
    void (*error_exit)(j_common_ptr);
    void (*output_message)(j_common_ptr);
};

struct jpeg_compress_struct {
    struct jpeg_error_mgr* err;
    JDIMENSION image_width;
    JDIMENSION image_height;
    int input_components;
    int in_color_space;
    JDIMENSION next_scanline;
    struct jpeg_memory_mgr* mem;
};

struct jpeg_memory_mgr {
    JSAMPARRAY (*alloc_sarray)(j_common_ptr, int, int, int);
};

struct ErrorHandler {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

class JpegEncoder {
public:
    static void OnJpegError(j_common_ptr);
    bool Encode(const struct heif_image_handle* handle,
                const struct heif_image* image, const std::string& filename);
};

extern "C" {
    struct jpeg_error_mgr* jpeg_std_error(struct jpeg_error_mgr*);
    void jpeg_create_compress(struct jpeg_compress_struct*);
    void jpeg_stdio_dest(struct jpeg_compress_struct*, FILE*);
    void jpeg_set_defaults(struct jpeg_compress_struct*);
    void jpeg_set_quality(struct jpeg_compress_struct*, int, boolean);
    void jpeg_start_compress(struct jpeg_compress_struct*, boolean);
    void jpeg_write_marker(struct jpeg_compress_struct*, int, const unsigned char*, unsigned int);
    void jpeg_write_icc_profile(struct jpeg_compress_struct*, const unsigned char*, unsigned int);
    void jpeg_write_scanlines(struct jpeg_compress_struct*, JSAMPARRAY, unsigned int);
    void jpeg_finish_compress(struct jpeg_compress_struct*);
    void jpeg_destroy_compress(struct jpeg_compress_struct*);
}

const char* JPEG_XMP_MARKER_ID = "http://ns.adobe.com/xap/1.0/";

int quality_ = 90;

int heif_image_get_width(const struct heif_image*, int) { return 0; }
int heif_image_get_height(const struct heif_image*, int) { return 0; }
uint8_t* GetExifMetaData(const struct heif_image_handle*, size_t*) { return nullptr; }
void modify_exif_orientation_tag_if_it_exists(uint8_t*, int, int) {}
std::vector<uint8_t> get_xmp_metadata(const struct heif_image_handle*) { return {}; }
size_t heif_image_handle_get_raw_color_profile_size(const struct heif_image_handle*) { return 0; }
void heif_image_handle_get_raw_color_profile(const struct heif_image_handle*, uint8_t*) {}
int heif_image_get_bits_per_pixel(const struct heif_image*, int) { return 0; }
const uint8_t* heif_image_get_plane_readonly(const struct heif_image*, int, int*) { return nullptr; }