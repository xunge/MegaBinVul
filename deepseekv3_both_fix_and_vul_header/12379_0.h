#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int len;
    union {
        void* buf;
    } data;
} MAPI_Value;

typedef struct {
    int name;
    int type;
    int num_values;
    MAPI_Value* values;
} MAPI_Attr;

typedef struct {
    char* name;
    unsigned char* data;
    size_t len;
    char* mime_type;
    char* content_id;
} File;

enum {
    MAPI_ATTACH_LONG_FILENAME,
    MAPI_ATTACH_DATA_OBJ,
    MAPI_ATTACH_MIME_TAG,
    MAPI_ATTACH_CONTENT_ID
};

enum {
    szMAPI_STRING,
    szMAPI_BINARY,
    szMAPI_OBJECT
};

#define XFREE(ptr) free(ptr)
#define CHECKED_XMALLOC(type, size) (type*)malloc(size)