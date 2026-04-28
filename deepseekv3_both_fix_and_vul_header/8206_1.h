#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LOC_PRIVATE_TAG ""
#define LOC_VARIANT_TAG ""
#define DELIMITER ""
#define TRUE 1

typedef struct _zval zval;

#define TSRMLS_DC

void* ecalloc(size_t nmemb, size_t size);
void efree(void* ptr);
char* get_private_subtags(const char* loc_name);
char* get_icu_value_internal(const char* loc_name, char* key_name, int* result, int something);
char* php_strtok_r(char* str, const char* delim, char** saveptr);
void add_assoc_string(zval* array, char* key, char* value, int duplicate);