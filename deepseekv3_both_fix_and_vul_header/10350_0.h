#include <stddef.h>

struct iwgifrcontext;
struct lzwdeccontext;
struct colortable_entry;

struct iwgifrcontext {
    unsigned char rbuf[9];
    int image_left;
    int image_top;
    int image_width;
    int image_height;
    int interlaced;
    int has_transparency;
    int trans_color_index;
    size_t total_npixels;
    size_t pixels_set;
    int include_screen;
    void* ctx;
    struct {
        struct colortable_entry* entry;
        int num_entries;
    } colortable;
};

struct lzwdeccontext {
    int eoi_flag;
};

struct colortable_entry {
    unsigned char a;
};

unsigned short iw_get_ui16le(const unsigned char* buf);
int iwgif_read(struct iwgifrcontext* rctx, unsigned char* buf, size_t count);
int iwgif_read_color_table(struct iwgifrcontext* rctx, struct colortable_entry* ct);
int iwgif_init_screen(struct iwgifrcontext* rctx);
int iwgif_make_row_pointers(struct iwgifrcontext* rctx);
void lzw_init(struct lzwdeccontext* d, unsigned int root_codesize);
void lzw_clear(struct lzwdeccontext* d);
int lzw_process_bytes(struct iwgifrcontext* rctx, struct lzwdeccontext* d, const unsigned char* buf, size_t size);
void iw_set_error(void* ctx, const char* msg);