#include <stdlib.h>

typedef struct cJSON {
    struct cJSON *child;
    struct cJSON *next;
    struct cJSON *prev;
    char *string;
    char *valuestring;
    int type;
} cJSON;

static const unsigned char *skip(const unsigned char *in);
static const unsigned char *parse_string(cJSON *item, const unsigned char *str, const unsigned char **ep);
static const unsigned char *parse_value(cJSON *item, const unsigned char *value, const unsigned char **ep);
static cJSON *cJSON_New_Item(void);
static void cJSON_Delete(cJSON *item);

#define cJSON_Object 1