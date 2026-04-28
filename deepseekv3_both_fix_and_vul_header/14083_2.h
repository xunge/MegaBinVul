#include <stdint.h>
#include <stddef.h>

#define AVERROR_EOF 1
#define AVERROR_EXIT 2
#define AVDISCARD_ALL 0
#define AV_LOG_INFO 0
#define AV_LOG_WARNING 1
#define READ_NORMAL 0

typedef struct AVFormatContext AVFormatContext;
typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct AVDictionary AVDictionary;
typedef struct AVIOInterruptCB AVIOInterruptCB;
typedef struct HLSContext HLSContext;
typedef struct playlist playlist;

struct AVFormatContext {
    int nb_streams;
    AVStream **streams;
    void *priv_data;
};

struct AVIOContext {
    int dummy;
};

struct AVStream {
    int discard;
};

struct AVIOInterruptCB {
    int dummy;
};

struct HLSContext {
    int max_reload;
    int cur_seq_no;
    AVIOInterruptCB *interrupt_callback;
};

struct playlist {
    int needed;
    AVIOContext *input;
    AVFormatContext *ctx;
    int stream_offset;
    int index;
    int64_t last_load_time;
    int finished;
    int cur_seq_no;
    int start_seq_no;
    int n_segments;
    int is_id3_timestamped;
    char *url;
    int target_duration;
    AVFormatContext *parent;
};

int64_t av_gettime(void);
void av_log(void *avcl, int level, const char *fmt, ...);
void av_usleep(unsigned usec);
int ff_check_interrupt(AVIOInterruptCB *cb);
int ffurl_close(AVIOContext *h);
int parse_playlist(HLSContext *c, const char *url, playlist *v, AVDictionary **options);
int open_input(HLSContext *c, playlist *v);
int read_from_url(playlist *v, uint8_t *buf, int buf_size, int flags);
void intercept_id3(playlist *v, uint8_t *buf, int buf_size, int *ret);
int64_t default_reload_interval(playlist *v);