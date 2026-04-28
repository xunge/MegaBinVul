#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint64_t ut64;
typedef int64_t st64;

struct minidump_location_descriptor {
    uint32_t data_size;
    uint32_t rva;
};

struct minidump_vs_fixedfileinfo {
    uint32_t dw_signature;
    uint32_t dw_struc_version;
    uint32_t dw_file_version_ms;
    uint32_t dw_file_version_ls;
    uint32_t dw_product_version_ms;
    uint32_t dw_product_version_ls;
    uint32_t dw_file_flags_mask;
    uint32_t dw_file_flags;
    uint32_t dw_file_os;
    uint32_t dw_file_type;
    uint32_t dw_file_subtype;
    uint32_t dw_file_date_ms;
    uint32_t dw_file_date_ls;
};

struct minidump_module {
    uint64_t base_of_image;
    uint32_t size_of_image;
    uint32_t check_sum;
    uint32_t time_date_stamp;
    uint32_t module_name_rva;
    struct minidump_vs_fixedfileinfo version_info;
    struct minidump_location_descriptor cv_record;
    struct minidump_location_descriptor misc_record;
    uint64_t reserved_0;
    uint64_t reserved_1;
};

typedef struct r_buf_t RBuffer;

enum {
    R_BUF_SET,
    R_BUF_CUR
};

#define R_NEW0(x) calloc(1, sizeof(x))

st64 r_buf_seek(RBuffer *b, ut64 addr, int whence);
uint64_t r_buf_read_le64(RBuffer *b);
uint32_t r_buf_read_le32(RBuffer *b);