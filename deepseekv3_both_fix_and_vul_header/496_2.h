#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANNELS 32
#define MAX_SAMPLES 255
#define MAX_PATTERNS 255
#define MAX_ORDERS 256

#define CHN_MUTE 0x01
#define CHN_LOOP 0x02
#define CHN_16BIT 0x04

#define ORDER_LAST 0xFF
#define FX_PATTERNBREAK 0x0D

#define SF_LE 0x01
#define SF_PCMU 0x02
#define SF_M 0x04
#define SF_16 0x08
#define SF_8 0x10

#define SONG_ITOLDEFFECTS 0x01
#define SONG_COMPATGXX 0x02

#define LOAD_UNSUPPORTED 1
#define LOAD_FORMAT_ERROR 2
#define LOAD_SUCCESS 0
#define LOAD_NOSAMPLES 0x04
#define LOAD_FILE_ERROR 3

#define SHORT_PANNING(x) (x)
#define MOD_FINETUNE(x) (x)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    uint8_t note;
    uint8_t instrument;
    uint8_t effect;
    uint8_t param;
} song_note_t;

typedef struct {
    char name[23];
    uint32_t length;
    uint32_t loop_start;
    uint32_t loop_end;
    int flags;
    int c5speed;
    int volume;
    int global_volume;
    int vib_type;
    int vib_rate;
    int vib_depth;
    int vib_speed;
} song_sample_t;

typedef struct {
    uint8_t *data;
    size_t length;
    size_t pos;
} slurp_t;

typedef struct {
    char tracker_id[32];
    char title[21];
    struct {
        int panning;
        int flags;
    } channels[MAX_CHANNELS];
    song_sample_t samples[MAX_SAMPLES+1];
    uint8_t orderlist[MAX_ORDERS];
    song_note_t *patterns[MAX_PATTERNS];
    int pattern_size[MAX_PATTERNS];
    int pattern_alloc_size[MAX_PATTERNS];
    char message[256];
    int flags;
} song_t;

void slurp_read(slurp_t *fp, void *buf, size_t size);
int slurp_getc(slurp_t *fp);
void slurp_seek(slurp_t *fp, long offset, int whence);
uint16_t bswapLE16(uint16_t x);
uint32_t bswapLE32(uint32_t x);
void *mem_calloc(size_t nmemb, size_t size);
void mtm_unpack_track(uint8_t *src, song_note_t *dest, int rows);
void read_lined_message(char *msg, slurp_t *fp, uint16_t len, int maxlen);
uint32_t csf_read_sample(song_sample_t *smp, int flags, uint8_t *data, size_t length);
void *csf_allocate_pattern(int rows);
void log_appendf(int level, const char *fmt, ...);