#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GF_M2TS_Section {
    unsigned char *data;
    u32 data_size;
} GF_M2TS_Section;

typedef struct GF_M2TS_SDT {
    u16 service_id;
    u8 EIT_schedule;
    u8 EIT_present_following;
    u8 running_status;
    u8 free_CA_mode;
    char *provider;
    char *service;
    u8 service_type;
} GF_M2TS_SDT;

typedef struct GF_List {
    // Placeholder for list implementation
    void **items;
    u32 count;
} GF_List;

typedef struct GF_M2TS_Demuxer {
    GF_List *SDTs;
    void (*on_event)(struct GF_M2TS_Demuxer *, u32, void *);
} GF_M2TS_Demuxer;

typedef struct GF_M2TS_SECTION_ES {
    // Placeholder for SECTION_ES implementation
} GF_M2TS_SECTION_ES;

#define GF_M2TS_TABLE_END 0x1
#define GF_M2TS_TABLE_REPEAT 0x2
#define GF_M2TS_TABLE_ID_SDT_ACTUAL 0x42
#define GF_M2TS_DVB_SERVICE_DESCRIPTOR 0x48
#define GF_M2TS_EVT_SDT_REPEAT 0
#define GF_M2TS_EVT_SDT_FOUND 1

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_LOG(a, b, c) printf c

static void gf_m2ts_reset_sdt(GF_M2TS_Demuxer *ts);
static u32 gf_list_count(GF_List *list);
static void *gf_list_get(GF_List *list, u32 index);
static void gf_list_add(GF_List *list, void *item);
static void gf_free(void *ptr);
static void *gf_malloc(size_t size);