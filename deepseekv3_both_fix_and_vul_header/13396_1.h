#include <stddef.h>
#include <stdint.h>

typedef unsigned char row_ver_t;
typedef unsigned char key_ver_t;
typedef unsigned char* db_buf_t;
typedef unsigned short row_size_t;
typedef uintptr_t dp_addr_t;

#define IE_ROW_VERSION(row) ((row_ver_t)((row)[0]))
#define IE_KEY_VERSION(row) ((key_ver_t)((row)[1]))
#define SHORT_REF(ptr) (*(unsigned short*)(ptr))
#define SHORT_REF_NA(ptr) (*(unsigned short*)(ptr))
#define LONG_REF(ptr) (*(dp_addr_t*)(ptr))
#define ROW_NO_MASK 0x7FFF
#define COL_OFFSET_SHIFT 15
#define COL_VAR_LEN_MASK 0x7FFF
#define COL_VAR_SUFFIX 0x8000
#define CL_FIRST_VAR (-1)
#define KV_LEFT_DUMMY 0
#define LD_LEAF 0

typedef struct {
    unsigned short *pm_entries;
    unsigned short pm_count;
} page_map_t;

typedef struct {
    unsigned char *bd_buffer;
    page_map_t *bd_content_map;
} buffer_desc_t;

typedef struct dbe_key_t {
    key_ver_t key_version;
    struct dbe_key_t **key_versions;
    unsigned short *key_key_var_start;
    unsigned short *key_row_var_start;
    unsigned short *key_length_area;
} dbe_key_t;

typedef struct {
    int cl_row_version_mask;
    int *cl_pos;
} dbe_col_loc_t;

void log_error(const char *fmt, ...);
void GPF_T1(const char *msg);