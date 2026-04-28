#include <stdlib.h>
#include <string.h>

#define SF_TRUE 1
#define SF_FALSE 0
#define STR_MARKER 0x53545220

typedef struct {
    int rsrc_len;
    void *rsrc_data;
    int need_to_free_rsrc_data;
    int data_offset;
    int map_offset;
    int data_length;
    int map_length;
    int string_offset;
    int type_offset;
    int type_count;
    int item_offset;
    int str_index;
    int str_count;
} SD2_RSRC;

typedef struct {
    void *header;
    int headindex;
    int headend;
} SF_PRIVATE;

#define SFE_SD2_BAD_DATA_OFFSET 1
#define SFE_SD2_BAD_MAP_OFFSET 2
#define SFE_SD2_BAD_DATA_LENGTH 3
#define SFE_SD2_BAD_MAP_LENGTH 4
#define SFE_SD2_BAD_RSRC 5

#define SIGNED_SIZEOF(x) (sizeof(x))