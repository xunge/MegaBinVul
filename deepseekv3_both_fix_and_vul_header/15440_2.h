#include <string.h>
#include <stdlib.h>

typedef struct cJSON {
    int type;
    char *valuestring;
} cJSON;

typedef struct internal_hooks {
    void *(*malloc_fn)(size_t sz);
    void (*free_fn)(void *ptr);
} internal_hooks;

static internal_hooks global_hooks = {
    .malloc_fn = malloc,
    .free_fn = free
};

#define cJSON_String 0x08
#define cJSON_IsReference 0x100
#define CJSON_PUBLIC(type) type

void *cJSON_malloc(size_t size);
void cJSON_free(void *object);
char *cJSON_strdup(const unsigned char *str, const internal_hooks *hooks);