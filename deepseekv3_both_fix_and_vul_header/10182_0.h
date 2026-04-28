#include <stdlib.h>
#include <string.h>

typedef struct _zend_string zend_string;
extern zend_string *strpprintf(size_t max_len, const char *format, ...);
extern char *estrndup(const char *s, size_t len);