#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))
#define SEEK_SET 0

typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;

typedef struct MOVFragmentIndexItem {
    int64_t time;
    int64_t moof_offset;
} MOVFragmentIndexItem;

typedef struct MOVFragmentIndex {
    unsigned int track_id;
    unsigned int item_count;
    MOVFragmentIndexItem *items;
} MOVFragmentIndex;

typedef struct MOVContext {
    AVFormatContext *fc;
    MOVFragmentIndex **fragment_index_data;
    unsigned int fragment_index_count;
} MOVContext;

#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AV_LOG_VERBOSE 0
#define AVERROR_INVALIDDATA (-(EINVAL))

void av_log(void*, int, const char*, ...);
int64_t avio_tell(AVIOContext*);
uint32_t avio_rb32(AVIOContext*);
void avio_rb24(AVIOContext*);
uint8_t avio_r8(AVIOContext*);
int64_t avio_rb64(AVIOContext*);
void avio_seek(AVIOContext*, int64_t, int);
int avio_feof(AVIOContext*);
void *av_mallocz(size_t);
void *av_realloc_array(void*, size_t, size_t);
void av_freep(void*);
void *av_mallocz_array(size_t, size_t);