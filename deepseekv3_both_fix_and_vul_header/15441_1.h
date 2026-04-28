#include <stdbool.h>
#include <stddef.h>

typedef struct cJSON {
    struct cJSON *next;
    struct cJSON *prev;
    struct cJSON *child;
} cJSON;

typedef bool cJSON_bool;

cJSON* get_array_item(cJSON *array, size_t index);
cJSON_bool add_item_to_array(cJSON *array, cJSON *item);

#define CJSON_PUBLIC(type) type