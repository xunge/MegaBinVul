#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ut32;
typedef signed int st32;
typedef unsigned short ut16;

typedef struct {
    int type;
    char *data;
} pyc_object;

typedef struct {
    // Placeholder for RzBuffer structure
    // Add necessary fields if needed
} RzBuffer;

static st32 get_st32(RzBuffer *buffer, bool *error);
static ut16 get_ut16(RzBuffer *buffer, bool *error);
void rz_str_trim(char *str);

#define RZ_NEW0(type) ((type *)calloc(1, sizeof(type)))
#define TYPE_LONG 1