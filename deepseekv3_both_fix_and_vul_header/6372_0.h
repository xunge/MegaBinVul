#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_DataEntryURLBox GF_DataEntryURLBox;

struct GF_DataEntryURLBox {
    u32 size;
    char *location;
};

#define GF_OK 0
#define GF_OUT_OF_MEM 1
#define GF_ISOM_INVALID_FILE 2

enum GF_LOG_Level {
    GF_LOG_ERROR
};

enum GF_LOG_Tool {
    GF_LOG_CONTAINER
};

void GF_LOG(enum GF_LOG_Level level, enum GF_LOG_Tool tool, const char *format, ...);
void *gf_malloc(u32 size);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);