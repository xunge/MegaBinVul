#include <stdio.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define AVI_MODE_WRITE 1
#define AVI_ERR_NOT_PERM 1
#define AVI_ERR_NO_IDX 2
#define AVI_ERR_READ 3

extern int AVI_errno;

typedef struct {
    u32 pos;
    u32 len;
    u8 key;
} avi_index_entry;

typedef struct {
    int mode;
    avi_index_entry *video_index;
    int video_pos;
    int video_frames;
    FILE *fdes;
} avi_t;

extern int gf_fseek(FILE *stream, long offset, int whence);
extern size_t avi_read(FILE *fdes, u8 *buf, size_t count);