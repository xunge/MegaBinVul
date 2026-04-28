#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int GF_Err;

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_Box {
    u32 size;
} GF_Box;

typedef struct GF_AdobeBootstrapInfoBox {
    GF_Box box;
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
    void *server_entry_table;
    u8 quality_entry_count;
    void *quality_entry_table;
    char *drm_data;
    char *meta_data;
    u8 segment_run_table_count;
    void *segment_run_table_entries;
    u8 fragment_run_table_count;
    void *fragment_run_table_entries;
    u32 size;  // 添加size成员
} GF_AdobeBootstrapInfoBox;

typedef struct GF_AdobeSegmentRunTableBox GF_AdobeSegmentRunTableBox;
typedef struct GF_AdobeFragmentRunTableBox GF_AdobeFragmentRunTableBox;

#define GF_FALSE 0
#define GF_TRUE 1
#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_OUT_OF_MEM 2

#define ISOM_DECREASE_SIZE(ptr, size)
#define ISOM_DECREASE_SIZE_GOTO_EXIT(ptr, size)

extern char *gf_strdup(const char *s);
extern void *gf_malloc(size_t size);
extern void gf_free(void *ptr);
extern u32 gf_bs_read_u32(GF_BitStream *bs);
extern u64 gf_bs_read_u64(GF_BitStream *bs);
extern unsigned int gf_bs_read_int(GF_BitStream *bs, int nbits);
extern unsigned char gf_bs_read_u8(GF_BitStream *bs);
extern GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
extern void gf_isom_box_del(GF_Box *box);
extern void gf_list_insert(void *list, void *item, int position);
extern unsigned int gf_list_count(void *list);
extern void gf_list_add(void *list, void *item);