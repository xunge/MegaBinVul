#include <stdint.h>
#include <stdio.h>

#define WTV_SECTOR_SIZE 4096
#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))
#define AVFMTCTX_NOHEADER 0x0001
#define AVINDEX_KEYFRAME 0x0001
#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)
#define SEEK_TO_DATA 0
#define SEEK_SET 0
#define SEEK_CUR 1

typedef struct AVIOContext {
    unsigned char *buffer;
    int buffer_size;
    unsigned char *buf_ptr;
    void *opaque;
} AVIOContext;

typedef struct AVStream {
    int index;
    int64_t duration;
    void *priv_data;
} AVStream;

typedef struct AVFormatContext {
    AVIOContext *pb;
    unsigned int ctx_flags;
    int nb_streams;
    AVStream **streams;
    void *priv_data;
} AVFormatContext;

typedef struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int64_t size;
    int flags;
} AVIndexEntry;

typedef struct WtvContext {
    int64_t epoch;
    int64_t pts;
    int64_t last_valid_pts;
    AVIOContext *pb;
    AVIndexEntry *index_entries;
    int nb_index_entries;
    int index_entries_allocated_size;
} WtvContext;

static const uint8_t ff_timeline_le16[16] = {0};
static const uint8_t ff_table_0_entries_legacy_attrib_le16[16] = {0};
static const uint8_t ff_table_0_entries_time_le16[16] = {0}; 
static const uint8_t ff_timeline_table_0_entries_Events_le16[16] = {0};

int avio_rl32(AVIOContext *s);
int64_t avio_rl64(AVIOContext *s);
int avio_read(AVIOContext *s, uint8_t *buf, int size);
void avio_skip(AVIOContext *s, int64_t offset);
int64_t avio_tell(AVIOContext *s);
void avio_seek(AVIOContext *s, int64_t offset, int whence);
int avio_feof(AVIOContext *s);
void av_log(void *avcl, int level, const char *fmt, ...);
int64_t seek_by_sector(AVIOContext *s, unsigned sector, int flags);
AVIOContext *wtvfile_open(AVFormatContext *s, uint8_t *root, int root_size, const void *guid);
void wtvfile_close(AVIOContext *pb);
int parse_chunks(AVFormatContext *s, int seek_to, int64_t arg1, int64_t arg2);
void parse_legacy_attrib(AVFormatContext *s, AVIOContext *pb);
void ff_add_index_entry(AVIndexEntry **entries, int *nb_entries, int *allocated_size,
                      int64_t pos, int64_t timestamp, int64_t size, int distance, int flags);