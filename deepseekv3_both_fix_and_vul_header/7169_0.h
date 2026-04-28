#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LOAD_UNSUPPORTED -1
#define LOAD_FORMAT_ERROR -2
#define LOAD_FILE_ERROR -3
#define LOAD_NOSAMPLES 0x01
#define LOAD_SUCCESS 0

#define MAX_CHANNELS 32
#define MAX_SAMPLES 255
#define MAX_PATTERNS 256
#define MAX_ORDERS 256

#define CHN_MUTE 0x01
#define CHN_LOOP 0x02
#define CHN_16BIT 0x04

#define ORDER_LAST 0xFF
#define FX_PATTERNBREAK 0x0D

#define MOD_FINETUNE(x) ((x) * 428)
#define SHORT_PANNING(x) ((x) * 17)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define SF_LE 0x01
#define SF_PCMU 0x02
#define SF_M 0x04
#define SF_8 0x08
#define SF_16 0x10

#define SONG_ITOLDEFFECTS 0x01
#define SONG_COMPATGXX 0x02

typedef struct {
    uint8_t note;
    uint8_t instrument;
    uint8_t volume;
    uint8_t effect;
    uint8_t param;
} song_note_t;

typedef struct {
    char name[23];
    uint32_t length;
    uint32_t loop_start;
    uint32_t loop_end;
    uint16_t c5speed;
    uint8_t volume;
    uint8_t global_volume;
    uint8_t vib_type;
    uint8_t vib_rate;
    uint8_t vib_depth;
    uint8_t vib_speed;
    uint8_t flags;
} song_sample_t;

typedef struct {
    uint8_t panning;
    uint8_t flags;
} channel_t;

typedef struct {
    char tracker_id[32];
    char title[21];
    channel_t channels[MAX_CHANNELS];
    song_sample_t samples[MAX_SAMPLES + 1];
    uint8_t orderlist[MAX_ORDERS];
    song_note_t *patterns[MAX_PATTERNS];
    uint16_t pattern_size[MAX_PATTERNS];
    uint16_t pattern_alloc_size[MAX_PATTERNS];
    char message[256];
    uint8_t flags;
} song_t;

typedef struct {
    uint8_t *data;
    size_t pos;
    size_t length;
} slurp_t;

uint16_t bswapLE16(uint16_t x);
uint32_t bswapLE32(uint32_t x);
void slurp_read(slurp_t *fp, void *buf, size_t count);
int slurp_getc(slurp_t *fp);
int slurp_eof(slurp_t *fp);
void slurp_seek(slurp_t *fp, long offset, int whence);
void *mem_calloc(size_t nmemb, size_t size);
void log_appendf(int level, const char *fmt, ...);
void mtm_unpack_track(uint8_t *src, song_note_t *dest, int rows);
song_note_t *csf_allocate_pattern(int rows);
uint32_t csf_read_sample(song_sample_t *smp, int flags, uint8_t *data, size_t length);
void read_lined_message(char *msg, slurp_t *fp, uint16_t len, uint8_t linelen);