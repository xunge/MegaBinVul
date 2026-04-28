#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef long ogg_int64_t;
typedef ogg_int64_t opus_int64;

struct ogg_page {
    unsigned char *header;
    long header_len;
    unsigned char *body;
    long body_len;
};

struct ogg_sync_state {
    unsigned char *data;
    int storage;
    int fill;
    int returned;
};

struct ogg_stream_state {
    unsigned char *body_data;
    long body_storage;
    long body_fill;
    long body_returned;
    int *lacing_vals;
    ogg_int64_t *granule_vals;
    long lacing_storage;
    long lacing_fill;
    long lacing_packet;
    long lacing_returned;
    unsigned char header[282];
    int header_fill;
    int e_o_s;
    int b_o_s;
    long serialno;
    long pageno;
    ogg_int64_t packetno;
    ogg_int64_t granulepos;
};

struct OpusHead {
    int version;
    int channels;
    int preskip;
    unsigned int input_sample_rate;
    int gain;
    int channel_mapping;
    int nb_streams;
    int nb_coupled;
    unsigned char stream_map[255];
};

struct OpusTags {
    char *vendor;
    char **user_comments;
    int *comment_lengths;
    int comments;
    int vendor_length;
};

struct OpusFileCallbacks {
    int (*read)(void *, unsigned char *, int);
    int (*seek)(void *, opus_int64, int);
    opus_int64 (*tell)(void *);
    int (*close)(void *);
};

struct OggOpusLink {
    struct OpusHead head;
    struct OpusTags tags;
    opus_int64 offset;
    opus_int64 data_offset;
    opus_int64 pcm_end;
    int serialno;
};

typedef struct OggOpusFile {
    struct ogg_sync_state oy;
    struct ogg_stream_state os;
    struct OpusFileCallbacks callbacks;
    void *stream;
    int seekable;
    int end;
    opus_int64 offset;
    int ready_state;
    int nlinks;
    int cur_link;
    struct OggOpusLink *links;
    int *serialnos;
    int nserialnos;
    int cserialnos;
} OggOpusFile;

typedef struct OpusFileCallbacks OpusFileCallbacks;
typedef struct ogg_page ogg_page;
typedef struct OggOpusLink OggOpusLink;

#define OP_UNLIKELY(x) (x)
#define OP_LIKELY(x) (x)
#define OP_EFAULT (-1)
#define OP_EREAD (-2)
#define OP_EINVAL (-3)
#define OP_PARTOPEN (1)
#define SEEK_CUR (1)

void *(*_ogg_malloc)(size_t size) = malloc;
void ogg_sync_init(struct ogg_sync_state *oy);
unsigned char *ogg_sync_buffer(struct ogg_sync_state *oy, long size);
void ogg_sync_wrote(struct ogg_sync_state *oy, long bytes);
void ogg_stream_init(struct ogg_stream_state *os, int serialno);
int op_fetch_headers(OggOpusFile *of, struct OpusHead *head, struct OpusTags *tags, int **serialnos, int *nserialnos, int *cserialnos, struct ogg_page *og);
int op_find_initial_pcm_offset(OggOpusFile *of, struct OggOpusLink *links, struct ogg_page *og);
void opus_tags_clear(struct OpusTags *tags);