#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef double Double;

typedef enum {
    GF_OK = 0,
    GF_NOT_SUPPORTED,
    GF_EOS
} GF_Err;

typedef enum {
    GF_LOG_ERROR = 1,
    GF_LOG_WARNING = 2,
    GF_LOG_PARSER = 3
} GF_LogLevel;

typedef struct {
    u32 num;
    u32 den;
} GF_Fraction;

typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_TextSample GF_TextSample;
typedef struct GF_Filter GF_Filter;

typedef struct {
    void *src;
    GF_FilterPid *opid;
    u32 playstate;
    u32 seek_state;
    Bool is_setup;
    Bool first_samp;
    Bool noflush;
    u32 unicode_type;
    u32 start;
    u32 end;
    u32 prev_end;
    GF_Fraction fps;
} GF_TXTIn;

#define REM_TRAIL_MARKS(str, marks)

static GF_Err txtin_setup_srt(GF_Filter *filter, GF_TXTIn *ctx);
static char *gf_text_get_utf8_line(char *buf, u32 buf_size, void *src, u32 unicode_type);
static void gf_fseek(void *src, long offset, int origin);
static long gf_ftell(void *src);
static GF_TextSample *gf_isom_new_text_sample(void);
static void gf_isom_delete_text_sample(GF_TextSample *samp);
static void gf_isom_text_add_text(GF_TextSample *samp, const char *text, u32 len);
static void txtin_process_send_text_sample(GF_TXTIn *ctx, GF_TextSample *samp, u64 start, u32 duration, Bool flush);
static Bool gf_filter_pid_would_block(GF_FilterPid *pid);
static void gf_filter_pid_set_info(GF_FilterPid *pid, const char *prop, void *value);
static void gf_filter_pid_set_info_str(GF_FilterPid *pid, const char *prop, void *value);
static void GF_LOG(int level, int category, const char *fmt, ...);

typedef struct {
    u32 type;
    union {
        u32 u;
        u64 lu;
    } value;
} GF_PropertyValue;

#define PROP_UINT(val) ((GF_PropertyValue){ .type=0, .value.u=(val) })
#define PROP_LONGUINT(val) ((GF_PropertyValue){ .type=1, .value.lu=(val) })

#define GF_PROP_PID_DOWN_BYTES "DownBytes"