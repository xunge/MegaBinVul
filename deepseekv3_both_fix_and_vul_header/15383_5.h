#include <cstdio>
#include <cstring>
#include <cerrno>
#include <vector>
#include <setjmp.h>
#include <string>
#include <cstdint>
#include <cstdlib>

typedef struct jpeg_compress_struct* j_common_ptr;
typedef unsigned char JSAMPLE;
typedef JSAMPLE* JSAMPROW;
typedef JSAMPROW* JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef unsigned char JOCTET;
typedef unsigned char boolean;
#define TRUE 1
#define FALSE 0
#define JCS_YCbCr 2
#define JPEG_APP0 0xE0
#define JPOOL_IMAGE 1

struct jpeg_error_mgr {
    void (*error_exit)(j_common_ptr);
    void (*output_message)(j_common_ptr);
    struct jpeg_error_mgr* (*jpeg_std_error)(struct jpeg_error_mgr*);
};

struct jpeg_memory_mgr {
    JSAMPARRAY (*alloc_sarray)(j_common_ptr, int, JDIMENSION, JDIMENSION);
};

struct jpeg_compress_struct {
    struct jpeg_error_mgr* err;
    struct jpeg_memory_mgr* mem;
    unsigned int image_width;
    unsigned int image_height;
    int input_components;
    int in_color_space;
    unsigned int next_scanline;
};

struct ErrorHandler {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

enum heif_channel {
    heif_channel_Y,
    heif_channel_Cb,
    heif_channel_Cr
};

class JpegEncoder {
public:
    static void OnJpegError(j_common_ptr cinfo);
    bool Encode(const struct heif_image_handle* handle,
                const struct heif_image* image, const std::string& filename);
private:
    int quality_ = 90;
};

extern "C" {
    void modify_exif_orientation_tag_if_it_exists(uint8_t* data, int size, int orientation);
    uint8_t* GetExifMetaData(const struct heif_image_handle* handle, size_t* size);
    std::vector<uint8_t> get_xmp_metadata(const struct heif_image_handle* handle);
    int heif_image_get_width(const struct heif_image* image, enum heif_channel);
    int heif_image_get_height(const struct heif_image* image, enum heif_channel);
    int heif_image_get_bits_per_pixel(const struct heif_image* image, enum heif_channel);
    const uint8_t* heif_image_get_plane_readonly(const struct heif_image* image, enum heif_channel, int* out_stride);
    size_t heif_image_handle_get_raw_color_profile_size(const struct heif_image_handle* handle);
    void heif_image_handle_get_raw_color_profile(const struct heif_image_handle* handle, uint8_t* out_data);
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

constexpr unsigned int MAX_BYTES_IN_MARKER = 65533;
const char* JPEG_XMP_MARKER_ID = "http://ns.adobe.com/xap/1.0/";
constexpr int JPEG_XMP_MARKER = JPEG_APP0 + 1;