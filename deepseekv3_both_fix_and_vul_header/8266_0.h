#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _spl_filesystem_object {
    struct {
        struct {
            char *current_line;
            size_t current_line_len;
            long current_line_num;
            int max_line_len;
            void *stream;
            int current_zval;
        } file;
    } u;
    char *file_name;
    int flags;
} spl_filesystem_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define SPL_FILE_OBJECT_DROP_NEW_LINE (1<<0)
#define SPL_HAS_FLAG(flags, flag) ((flags) & (flag))

void spl_filesystem_file_free_line(spl_filesystem_object *intern TSRMLS_DC);
void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
void efree(void *ptr);
char *estrdup(const char *s);
int php_stream_eof(void *stream);
char *php_stream_get_line(void *stream, char *buf, size_t maxlen, size_t *len);
void zend_throw_exception_ex(void *exception, long code TSRMLS_DC, const char *format, ...);
extern void *spl_ce_RuntimeException;