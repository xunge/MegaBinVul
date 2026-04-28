#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char Bool;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef int GF_Err;

#define GF_FALSE 0
#define GF_TRUE 1
#define GF_OK 0
#define GF_OUT_OF_MEM -1
#define GF_ISOM_INVALID_FILE -2

#define ISOM_DECREASE_SIZE(ptr, size) 
#define ISOM_DECREASE_SIZE_GOTO_EXIT(ptr, size) 

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

typedef struct GF_AdobeBootstrapInfoBox {
    u32 bootstrapinfo_version;
    int profile;
    int live;
    int update;
    int reserved;
    u32 time_scale;
    u64 current_media_time;
    u64 smpte_time_code_offset;
    char *movie_identifier;
    u8 server_entry_count;
    GF_List *server_entry_table;
    u8 quality_entry_count;
    GF_List *quality_entry_table;
    char *drm_data;
    char *meta_data;
    u8 segment_run_table_count;
    GF_List *segment_run_table_entries;
    u8 fragment_run_table_count;
    GF_List *fragment_run_table_entries;
    u32 size;
} GF_AdobeBootstrapInfoBox;

typedef struct GF_AdobeSegmentRunTableBox GF_AdobeSegmentRunTableBox;
typedef struct GF_AdobeFragmentRunTableBox GF_AdobeFragmentRunTableBox;

u32 gf_bs_read_u32(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
u64 gf_bs_read_u64(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
char *gf_strdup(const char *str);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
void gf_list_insert(GF_List *list, void *item, u32 position);
u32 gf_list_count(const GF_List *list);
void gf_list_add(GF_List *list, void *item);
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *box);