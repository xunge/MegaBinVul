#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define MAX_PATTERNS 256
#define MAX_SAMPLES 256
#define MAX_ORDERS 256

#define LOAD_UNSUPPORTED 0
#define LOAD_FORMAT_ERROR 1
#define LOAD_SUCCESS 2
#define LOAD_NOPATTERNS 4
#define LOAD_NOSAMPLES 8

#define ORDER_LAST 0xFF

#define SEEK_SET 0

#define SF_BE 0x01
#define SF_M 0x02
#define SF_PCMS 0x04

typedef struct song_sample_t {
    uint32_t length;
    uint8_t *data;
} song_sample_t;

typedef struct {
    unsigned int initial_speed;
    unsigned int initial_tempo;
    uint8_t orderlist[MAX_ORDERS];
    song_sample_t samples[MAX_SAMPLES];
    int pan_separation;
    char tracker_id[32];
} song_t;

typedef struct {
    size_t pos;
    uint8_t *data;
} slurp_t;

#define OKT_BLOCK(a,b,c,d) ((a)<<24|(b)<<16|(c)<<8|(d))
#define OKT_BLK_CMOD OKT_BLOCK('C','M','O','D')
#define OKT_BLK_SAMP OKT_BLOCK('S','A','M','P')
#define OKT_BLK_SPEE OKT_BLOCK('S','P','E','E')
#define OKT_BLK_SLEN OKT_BLOCK('S','L','E','N')
#define OKT_BLK_PLEN OKT_BLOCK('P','L','E','N')
#define OKT_BLK_PATT OKT_BLOCK('P','A','T','T')
#define OKT_BLK_PBOD OKT_BLOCK('P','B','O','D')
#define OKT_BLK_SBOD OKT_BLOCK('S','B','O','D')

#define OKT_HAS_CMOD 1
#define OKT_HAS_SAMP 2
#define OKT_HAS_SPEE 4
#define OKT_HAS_PLEN 8
#define OKT_HAS_PATT 16

#define CLAMP(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static inline uint32_t bswapBE32(uint32_t x) {
    return ((x & 0xFF000000) >> 24) | ((x & 0x00FF0000) >> 8) | 
           ((x & 0x0000FF00) << 8) | ((x & 0x000000FF) << 24);
}

static inline uint16_t bswapBE16(uint16_t x) {
    return (x >> 8) | (x << 8);
}

void log_appendf(int level, const char *fmt, ...);
int okt_read_cmod(song_t *song, slurp_t *fp);
void okt_read_samp(song_t *song, slurp_t *fp, uint32_t blklen, uint32_t *smpflag);
uint32_t okt_read_pbod(song_t *song, slurp_t *fp, int nchn, int pat);
void csf_read_sample(song_sample_t *ssmp, int flags, uint8_t *data, uint32_t length);

size_t slurp_tell(slurp_t *fp);
int slurp_seek(slurp_t *fp, size_t pos, int whence);
int slurp_eof(slurp_t *fp);
void slurp_read(slurp_t *fp, void *buf, size_t size);