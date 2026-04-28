#include <stdint.h>
#include <stdio.h>

typedef int64_t s64;
typedef uint8_t u8;

#define AVI_MODE_WRITE 1
#define AVI_ERR_NOT_PERM 1
#define AVI_ERR_NO_IDX 2
#define AVI_ERR_READ 3
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2
#define LLD "lld"

extern int AVI_errno;

typedef struct {
    s64 pos;
    s64 len;
} audio_index_entry;

typedef struct {
    audio_index_entry *audio_index;
    int audio_posc;
    int audio_posb;
    int audio_chunks;
} track_info;

typedef struct {
    int mode;
    int aptr;
    track_info *track;
    FILE *fdes;
} avi_t;

extern int gf_fseek(FILE *fdes, s64 pos, int whence);
extern s64 avi_read(FILE *fdes, void *buf, int size);
extern void GF_LOG(int level, int category, const char *fmt, ...);