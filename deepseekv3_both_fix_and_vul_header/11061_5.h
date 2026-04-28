#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int GF_Err;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;
typedef struct GF_AdobeBootstrapInfoBox GF_AdobeBootstrapInfoBox;
typedef struct GF_AdobeSegmentRunTableBox GF_AdobeSegmentRunTableBox;
typedef struct GF_AdobeFragmentRunTableBox GF_AdobeFragmentRunTableBox;

struct GF_Box {
    u32 size;
};

struct GF_AdobeBootstrapInfoBox {
    GF_Box box;
    u32 bootstrapinfo_version;
    u32 profile;
    u32 live;
    u32 update;
    u32 reserved;
    u32 time_scale;
    u64 current_media_time;
    u64 smpte_time_code_offset;
    char *movie_identifier;
    u32 server_entry_count;
    GF_List *server_entry_table;
    u32 quality_entry_count;
    GF_List *quality_entry_table;
    char *drm_data;
    char *meta_data;
    u32 segment_run_table_count;
    GF_List *segment_run_table_entries;
    u32 fragment_run_table_count;
    GF_List *fragment_run_table_entries;
    u32 size;  // 添加size成员
};

struct GF_AdobeSegmentRunTableBox {
    GF_Box box;
};

struct GF_AdobeFragmentRunTableBox {
    GF_Box box;
};

char *gf_strdup(const char *s);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u8 gf_bs_read_u8(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
u64 gf_bs_read_u64(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int nbits);
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_list_insert(GF_List *list, void *item, u32 position);