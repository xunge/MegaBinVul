#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned char u8;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef int GF_Err;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1

typedef struct __tag_bitstream GF_BitStream;
typedef struct __tag_box GF_Box;

typedef struct {
    u32 bootstrapinfo_version;
    int profile;
    Bool live;
    Bool update;
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
    u32 size;
} GF_AdobeBootstrapInfoBox;

typedef struct {
    // placeholder for GF_AdobeSegmentRunTableBox structure
} GF_AdobeSegmentRunTableBox;

typedef struct {
    // placeholder for GF_AdobeFragmentRunTableBox structure
} GF_AdobeFragmentRunTableBox;

u32 gf_bs_read_u32(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
u64 gf_bs_read_u64(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
char *gf_strdup(const char *str);
void gf_list_insert(void *list, void *item, int position);
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *box);