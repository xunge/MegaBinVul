#include <stdlib.h>

#define SPL_FS_INFO 0
#define SPL_FS_DIR 1
#define SPL_FS_FILE 2

#define PHP_STREAM_FREE_CLOSE 0
#define PHP_STREAM_FREE_CLOSE_PERSISTENT 1

typedef struct {
    int is_persistent;
} php_stream;

typedef struct _spl_filesystem_object {
    struct {
        void *properties_table;
    } std;
    int type;
    union {
        struct {
            void *dirp;
            char *sub_path;
        } dir;
        struct {
            php_stream *stream;
            void *zcontext;
            char *open_mode;
        } file;
    } u;
    char *_path;
    char *file_name;
    char *orig_path;
    struct {
        void (*dtor)(void *intern);
    } *oth_handler;
} spl_filesystem_object;

typedef struct {
    void *data;
    struct {
        void (*dtor)(void *iterator);
    } *funcs;
} zend_object_iterator;

#define TSRMLS_DC
#define TSRMLS_CC
#define efree free

void zend_object_std_dtor(void *object);
void *spl_filesystem_object_to_iterator(void *intern);
void spl_filesystem_file_free_line(void *intern);
void php_stream_close(void *stream);
void php_stream_free(void *stream, int options);