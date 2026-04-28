#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_SMIL_TIME_CLOCK,
    GF_SMIL_TIME_EVENT,
    GF_SMIL_TIME_INDEFINITE
} SMIL_TimeType;

typedef struct {
    SMIL_TimeType type;
    double clock;
    char *element_id;
} SMIL_Time;

typedef struct GF_List GF_List;

typedef struct {
    struct {
        int tag;
    } *sgprivate;
} GF_Node;

#define GF_OK 0
#define GF_LOG_ERROR 1
#define GF_LOG_PARSER 2
#define TAG_SVG_discard 0

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type)); if(!ptr)
#define gf_free(ptr) free(ptr)
#define GF_LOG(level, category, message)

GF_List *gf_list_new(void);
u32 gf_list_count(const GF_List *list);
void *gf_list_get(const GF_List *list, u32 index);
void gf_list_add(GF_List *list, void *item);
void gf_list_rem(GF_List *list, u32 index);
void gf_list_insert(GF_List *list, void *item, u32 index);
void gf_list_del(GF_List *list);
int smil_parse_time(GF_Node *e, SMIL_Time *value, char *value_string);