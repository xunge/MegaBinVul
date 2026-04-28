#include <string.h>

typedef struct cJSON {
    struct cJSON *child;
    struct cJSON *next;
    char *string;
} cJSON;

typedef int cJSON_bool;

static int case_insensitive_strcmp(const unsigned char *str1, const unsigned char *str2);