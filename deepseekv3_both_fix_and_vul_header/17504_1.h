#include <stdlib.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GF_M2TS_Section GF_M2TS_Section;
typedef struct GF_M2TS_Program GF_M2TS_Program;
typedef struct GF_M2TS_SECTION_ES GF_M2TS_SECTION_ES;
typedef struct GF_M2TS_ES GF_M2TS_ES;
typedef struct GF_M2TS_Demuxer GF_M2TS_Demuxer;
typedef struct GF_List GF_List;

struct GF_M2TS_Section {
    unsigned char *data;
    u32 data_size;
};

struct GF_M2TS_SECTION_ES {
    u32 flags;
    u16 pid;
    GF_M2TS_Program *program;
    void *sec;
    u8 demux_restarted;
};

struct GF_M2TS_Program {
    GF_List *streams;
    u16 pmt_pid;
    u16 number;
    GF_M2TS_Demuxer *ts;
};

struct GF_M2TS_ES {
    // Base fields for ES
};

struct GF_M2TS_Demuxer {
    void (*on_event)(GF_M2TS_Demuxer *, u32, void *);
    GF_List *programs;
    GF_M2TS_SECTION_ES *pat;
    GF_M2TS_SECTION_ES *nit;
    GF_M2TS_ES *ess[8192];
};

#define GF_M2TS_TABLE_END 0x01
#define GF_M2TS_TABLE_REPEAT 0x02
#define GF_M2TS_TABLE_UPDATE 0x04
#define GF_M2TS_ES_IS_SECTION 0x01
#define GF_M2TS_EVT_PAT_REPEAT 0
#define GF_M2TS_EVT_PAT_UPDATE 1
#define GF_M2TS_EVT_PAT_FOUND 2
#define GF_M2TS_EVT_NIT_FOUND 3

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type)); if (!ptr) return
#define GF_LOG(level, subsystem, message) printf message

GF_List *gf_list_new(void);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_list_add(GF_List *list, void *item);
GF_M2TS_SECTION_ES *gf_m2ts_section_filter_new(void (*process)(GF_M2TS_Demuxer *, GF_M2TS_SECTION_ES *, GF_List *, u8, u16, u8, u8, u32), u32 flags);
void gf_m2ts_process_nit(GF_M2TS_Demuxer *ts, GF_M2TS_SECTION_ES *ses, GF_List *sections, u8 table_id, u16 ex_table_id, u8 version_number, u8 last_section_number, u32 status);
void gf_m2ts_process_pmt(GF_M2TS_Demuxer *ts, GF_M2TS_SECTION_ES *ses, GF_List *sections, u8 table_id, u16 ex_table_id, u8 version_number, u8 last_section_number, u32 status);