#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
typedef int GF_Err;
typedef int GF_Bool;
typedef double Double;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_NOT_SUPPORTED -1
#define GF_OK 0
#define GF_EOS -2
#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_PARSER 3
#define GF_PROP_PID_DOWN_BYTES "PIDDownBytes"

typedef struct {
    int den;
    int num;
} GF_Fraction;

typedef struct {
    u32 unicode_type;
    GF_Bool is_setup;
    void *opid;
    int playstate;
    int seek_state;
    FILE *src;
    GF_Fraction fps;
    u32 start;
    u32 end;
    u32 prev_end;
    GF_Bool first_samp;
    GF_Bool noflush;
} GF_TXTIn;

typedef struct {
} GF_Filter;

typedef struct {
} GF_FilterPacket;

typedef struct {
} GF_TextSample;

typedef struct {
} GF_PropertyValue;

#define PROP_LONGUINT(x) ((GF_PropertyValue){})
#define PROP_UINT(x) ((GF_PropertyValue){})

static GF_Err txtin_setup_srt(GF_Filter *filter, GF_TXTIn *ctx, GF_Bool flag);
static char *gf_text_get_utf8_line(char *buf, u32 size, FILE *src, u32 unicode_type);
static void gf_fseek(FILE *f, long offset, int whence);
static long gf_ftell(FILE *f);
static GF_TextSample *gf_isom_new_text_sample();
static void gf_isom_delete_text_sample(GF_TextSample *samp);
static void gf_isom_text_add_text(GF_TextSample *samp, const char *text, u32 len);
static void txtin_process_send_text_sample(GF_TXTIn *ctx, GF_TextSample *samp, u64 start, u32 dur, GF_Bool add_to_tail);
static void gf_filter_pid_set_info(void *pid, const char *prop, GF_PropertyValue *val);
static void gf_filter_pid_set_info_str(void *pid, const char *prop, GF_PropertyValue *val);
static GF_Bool gf_filter_pid_would_block(void *pid);

#define REM_TRAIL_MARKS(str, marks) \
    do { \
        char *end = str + strlen(str) - 1; \
        while (end >= str && strchr(marks, *end)) { \
            *end-- = '\0'; \
        } \
    } while (0);

#define GF_LOG(level, category, msg) printf msg