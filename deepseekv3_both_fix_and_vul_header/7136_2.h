#include <stdlib.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GF_M2TS_Section {
    unsigned char *data;
    u32 data_size;
} GF_M2TS_Section;

typedef struct GF_M2TS_TDT_TOT {
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;
} GF_M2TS_TDT_TOT;

typedef struct GF_M2TS_TDT_TOT_Entry {
    u32 length;
    u8 *section;
} GF_M2TS_TDT_TOT_Entry;

typedef struct GF_M2TS_Demuxer {
    GF_M2TS_TDT_TOT *TDT_time;
    GF_M2TS_TDT_TOT_Entry *tdt_tot;
    void (*on_event)(struct GF_M2TS_Demuxer *, int, GF_M2TS_TDT_TOT *);
} GF_M2TS_Demuxer;

typedef struct GF_M2TS_SECTION_ES GF_M2TS_SECTION_ES;
typedef struct GF_List GF_List;

enum {
    GF_M2TS_TABLE_ID_TDT,
    GF_M2TS_TABLE_ID_TOT,
    GF_M2TS_PID_TDT_TOT_ST
};

enum {
    GF_M2TS_TABLE_END = 1,
    GF_M2TS_EVT_TDT,
    GF_M2TS_EVT_TOT
};

#define GF_LOG(level, category, message)
#define GF_SAFEALLOC(ptr, type) ((ptr) = malloc(sizeof(type)))
#define gf_list_count(list) 0
#define gf_list_get(list, index) NULL
#define gf_free(ptr) free(ptr)
#define gf_m2ts_crc32_check(data, size) 1