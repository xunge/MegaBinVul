#include <ctype.h>
#include <string.h>

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct _mime_header_entry {
    char *key;
    char *value;
} mime_header_entry;

typedef struct _multipart_buffer {
    char *boundary;
    int input_encoding;
    const char *detect_order;
    size_t detect_order_size;
} multipart_buffer;

typedef struct _zend_llist {
    void *head;
    void *tail;
    size_t count;
    size_t size;
    void *dtor;
} zend_llist;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_C

extern int find_boundary(multipart_buffer *self, char *boundary TSRMLS_DC);
extern char *get_line(multipart_buffer *self TSRMLS_DC);
extern int php_rfc1867_encoding_translation(TSRMLS_D);
extern const char *zend_multibyte_encoding_detector(unsigned char *line, size_t len, const char *detect_order, size_t detect_order_size TSRMLS_DC);
extern char *estrdup(const char *s);
extern void smart_str_appends(smart_str *str, const char *s);
extern void smart_str_0(smart_str *str);
extern void zend_llist_add_element(zend_llist *list, void *element);