#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef int32_t Fixed;
typedef uint16_t u16;
typedef int16_t s16;
typedef bool Bool;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_SM_SWF_NO_TEXT (1<<0)

#define SWF_TWIP_SCALE (1.0/20.0)

typedef struct {
    u32 ID;
    void *mat;
    void *text;
} SWFText;

typedef struct {
    u32 fontID;
    u32 fontSize;
    u32 col;
    Fixed orig_x;
    Fixed orig_y;
    u32 nbGlyphs;
    u32 *indexes;
    Fixed *dx;
} SWFGlyphRec;

typedef struct {
    u32 flags;
    GF_Err (*define_text)(void*, SWFText*);
} SWFReader;

typedef struct {
    // Placeholder for SWFRec structure
} SWFRec;

#define FLT2FIX(x) ((Fixed)((x) * 65536.0))
#define GF_SAFEALLOC(ptr, type) ptr = (type*)malloc(sizeof(type))
#define gf_malloc malloc
#define gf_free free
#define gf_list_new() NULL
#define gf_list_add(list, item) 
#define gf_list_count(list) 0
#define gf_list_get(list, index) NULL
#define gf_list_rem(list, index) 
#define gf_list_del(list) 

void swf_get_rec(SWFReader *read, SWFRec *rc);
void swf_get_matrix(SWFReader *read, void *mat);
void swf_align(SWFReader *read);
u32 swf_read_int(SWFReader *read, u32 bits);
u16 swf_get_16(SWFReader *read);
u32 swf_get_color(SWFReader *read);
u32 swf_get_argb(SWFReader *read);
s16 swf_get_s16(SWFReader *read);
void swf_report(SWFReader *read, GF_Err err, const char *msg, ...);