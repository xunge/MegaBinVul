#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <inttypes.h>

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define SEEK_CUR 1

typedef struct AVIOContext AVIOContext;
typedef struct AVFormatContext AVFormatContext;
typedef struct MOVContext MOVContext;
typedef struct MOVAtom MOVAtom;

struct MOVAtom {
    int64_t size;
    uint32_t type;
};

struct AVIOContext {
    int seekable;
    int64_t (*seek)(AVIOContext *, int64_t offset, int whence);
    int64_t (*tell)(AVIOContext *);
    int64_t (*size)(AVIOContext *);
    int (*read)(AVIOContext *, uint8_t *buf, int buf_size);
    int (*skip)(AVIOContext *, int64_t offset);
    int eof_reached;
};

struct AVFormatContext {
    int flags;
    void *priv_data;
};

struct MOVContext {
    AVFormatContext *fc;
    int atom_depth;
    int moov_retry;
    int found_moov;
    int found_mdat;
    int64_t next_root_atom;
};

typedef struct {
    uint32_t type;
    int (*parse)(MOVContext*, AVIOContext*, MOVAtom);
} MOVParseTableEntry;

extern MOVParseTableEntry mov_default_parse_table[];
extern int mov_read_udta_string(MOVContext*, AVIOContext*, MOVAtom);
extern void av_log(void *, int level, const char *fmt, ...);
extern void av_dlog(void *, const char *fmt, ...);
extern uint32_t avio_rb32(AVIOContext *);
extern uint32_t avio_rl32(AVIOContext *);
extern uint64_t avio_rb64(AVIOContext *);
extern int avio_read(AVIOContext *, uint8_t *buf, int buf_size);
extern int64_t avio_seek(AVIOContext *, int64_t offset, int whence);
extern int64_t avio_tell(AVIOContext *);
extern int64_t avio_size(AVIOContext *);
extern int avio_skip(AVIOContext *, int64_t offset);
extern int avio_feof(AVIOContext *);

#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AVFMT_FLAG_IGNIDX 1
#define AVERROR_INVALIDDATA (-1)