#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stream;

struct jpeg_error_mgr {
    void (*error_exit)(void*);
    void* dummy[100];
};

struct jpeg_source_mgr {
    void (*init_source)(void*);
    unsigned char (*fill_input_buffer)(void*);
    void (*skip_input_data)(void*, long);
    void (*resync_to_restart)(void*, int);
    void (*term_source)(void*);
    size_t bytes_in_buffer;
    unsigned char *next_input_byte;
};

struct str_src_mgr {
    struct jpeg_source_mgr pub;
    struct Stream *str;
    int index;
    bool abort;
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_source_mgr *src;
    void* dummy[100];
};

struct DCTStream {
    struct jpeg_error_mgr jerr;
    struct str_src_mgr src;
    struct Stream *str;
    unsigned char *current;
    unsigned char *limit;
    struct jpeg_decompress_struct cinfo;
    unsigned char *row_buffer;
    void init();
};

void jpeg_std_error(struct jpeg_error_mgr *err);
void jpeg_create_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_resync_to_restart(void *cinfo, int desired);

static void exitErrorHandler(void *cinfo) {}
static void str_init_source(void *cinfo) {}
static unsigned char str_fill_input_buffer(void *cinfo) { return 0; }
static void str_skip_input_data(void *cinfo, long num_bytes) {}
static void str_term_source(void *cinfo) {}