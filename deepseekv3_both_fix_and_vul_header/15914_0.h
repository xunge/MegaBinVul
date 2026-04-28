#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define PHPAPI
#define zend_bool int
#define PHP_TAG_BUF_SIZE 1024

char *estrndup(const char *s, size_t len);
void *emalloc(size_t size);
void *erealloc(void *ptr, size_t size);
void efree(void *ptr);
char *zend_str_tolower_dup_ex(const char *s, size_t len);
int php_tag_find(const char *tag, size_t len, const char *allow);