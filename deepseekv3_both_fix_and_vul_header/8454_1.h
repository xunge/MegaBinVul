#include <stdint.h>
#include <string.h>

struct archive_read {
    struct {
        void *data;
    } *format;
    struct {
        int errno;
    } archive;
};

struct zip_entry {
    unsigned int zip_flags;
    uint8_t decdat;
};

struct zip {
    struct zip_entry *entry;
    struct trad_enc_ctx *tctx;
    int tctx_valid;
    int64_t entry_bytes_remaining;
    int64_t entry_compressed_bytes_read;
    int64_t decrypted_bytes_remaining;
};

struct trad_enc_ctx;

#define ARCHIVE_OK 0
#define ARCHIVE_FATAL 1
#define ARCHIVE_FAILED 2
#define ARCHIVE_ERRNO_FILE_FORMAT 3
#define ARCHIVE_ERRNO_MISC 4
#define ZIP_LENGTH_AT_END 0x01

int trad_enc_init(struct trad_enc_ctx *, const char *, size_t, const void *, size_t, uint8_t *);
const void *__archive_read_ahead(struct archive_read *, size_t, void *);
const char *__archive_read_next_passphrase(struct archive_read *);
void __archive_read_consume(struct archive_read *, size_t);
void archive_set_error(void *, int, const char *, ...);
int zip_alloc_decryption_buffer(struct archive_read *);