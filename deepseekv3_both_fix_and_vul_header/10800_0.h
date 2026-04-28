#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define OBJECT_TYPE_ARRAY 1
#define ERROR_SUCCESS 0
#define ERROR_INSUFFICIENT_MEMORY 1

typedef struct _YR_OBJECT YR_OBJECT;
typedef struct _YR_OBJECT_ARRAY YR_OBJECT_ARRAY;
typedef struct _YR_ARRAY_ITEMS YR_ARRAY_ITEMS;

struct _YR_OBJECT {
    int type;
    YR_OBJECT* parent;
};

struct _YR_OBJECT_ARRAY {
    YR_ARRAY_ITEMS* items;
};

struct _YR_ARRAY_ITEMS {
    int count;
    YR_OBJECT* objects[];
};

YR_OBJECT_ARRAY* object_as_array(YR_OBJECT* object);
int yr_max(int a, int b);
void* yr_malloc(size_t size);
void* yr_realloc(void* ptr, size_t size);