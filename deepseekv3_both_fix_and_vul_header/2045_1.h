#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define TSRMLS_DC
#define TSRMLS_CC
#define FAILURE -1
#define SUCCESS 0

typedef struct _phar_entry_info {
    size_t uncompressed_filesize;
    char *filename;
    size_t filename_len;
    void *metadata;
    struct _phar_archive_data *phar;
} phar_entry_info;

typedef struct _phar_archive_data {
    void *manifest;
    void *metadata;
} phar_archive_data;

typedef struct _php_stream {
    // stream implementation details would go here
} php_stream;

extern void *emalloc(size_t size);
extern void efree(void *ptr);
extern size_t php_stream_tell(php_stream *fp);
extern size_t php_stream_read(php_stream *fp, char *buf, size_t count);
extern int php_stream_seek(php_stream *fp, size_t offset, int whence);
extern int phar_parse_metadata(char **metadata, void **dest, size_t metadata_len TSRMLS_DC);
extern int zend_hash_find(void *ht, const char *arKey, unsigned int nKeyLength, void **pData);