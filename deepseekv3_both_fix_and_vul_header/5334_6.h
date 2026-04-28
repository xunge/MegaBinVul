#include <stdlib.h>

struct archive_string {
    char *s;
    size_t length;
    size_t buffer_length;
};

struct archive_read;
struct zip;
struct zip_entry;

extern struct {
    void (*Ppmd8_Free)(void*);
} __archive_ppmd8_functions;

struct zip {
    void *data;
    int stream_valid;
    struct {
        void *next_in;
        unsigned int avail_in;
        void *next_out;
        unsigned int avail_out;
    } stream;
    int zipx_lzma_valid;
    struct {
        void *internal;
    } zipx_lzma_stream;
    int bzstream_valid;
    struct {
        void *state;
    } bzstream;
    void *uncompressed_buffer;
    int ppmd8_valid;
    void *ppmd8;
    struct zip_entry *zip_entries;
    void *decrypted_buffer;
    int cctx_valid;
    void *cctx;
    int hctx_valid;
    void *hctx;
    void *iv;
    void *erd;
    void *v_data;
    struct archive_string format_name;
};

struct zip_entry {
    struct zip_entry *next;
    struct archive_string rsrcname;
};

struct archive_read {
    struct {
        void *data;
    } *format;
};

#define ARCHIVE_OK 0

void archive_string_free(struct archive_string *str) {
    free(str->s);
}

void archive_decrypto_aes_ctr_release(void *ctx) {
    free(ctx);
}

void archive_hmac_sha1_cleanup(void *ctx) {
    free(ctx);
}