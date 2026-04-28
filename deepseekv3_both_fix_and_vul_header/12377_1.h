#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t len;
} VarLenData;

typedef struct {
    size_t len;
    union {
        unsigned char *buf;
    } data;
} MAPI_Value;

typedef struct {
    int type;
    size_t num_values;
    MAPI_Value *values;
} MAPI_Attr;

#define szMAPI_BINARY 1

#define XCALLOC(type, num) ((type *)calloc((num), sizeof(type)))
#define XMALLOC(type, num) ((type *)malloc((num) * sizeof(type)))
#define CHECKED_XCALLOC(type, num) ((type *)calloc((num), sizeof(type)))