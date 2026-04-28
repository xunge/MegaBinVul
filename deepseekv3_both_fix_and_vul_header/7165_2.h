#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

struct MPContext;
struct MPOpts;
struct ao_chain;
struct mp_chmap;
struct mp_filter;
struct mp_pin;
struct track;
struct dec_audio;
struct vo_chain;
struct encode_lavc_context;
struct mp_audio_buffer;
struct ao;

enum {
    STATUS_EOF,
    STATUS_DRAINING,
    STATUS_PLAYING,
    STATUS_SYNCING,
    STATUS_FILLING,
    STATUS_READY
};

enum {
    AD_OK,
    AD_EOF,
    AD_WAIT
};

enum {
    AO_EVENT_RELOAD,
    AO_EVENT_INITIAL_UNBLOCK
};

enum {
    VS_DISP_ADROP
};

enum {
    STREAM_AUDIO
};

enum {
    AOPLAY_FINAL_CHUNK
};

#define MPMAX(a, b) ((a) > (b) ? (a) : (b))
#define MPMIN(a, b) ((a) < (b) ? (a) : (b))

struct MPOpts {
    double sync_max_audio_change;
    double sync_max_video_change;
    double sync_audio_drop_size;
    int video_sync;
    bool gapless_audio;
};

struct mp_filter {
    struct mp_pin **pins;
    bool failed_output_conversion;
    bool got_output_eof;
    bool ao_needs_update;
    struct mp_filter *f;
};

struct ao_chain {
    struct mp_filter *filter;
    struct track *track;
    struct dec_audio *dec;
    struct mp_audio_buffer *ao_buffer;
    double ao_resume_time;
};

struct track {
    struct dec_audio *dec;
};

struct dec_audio {
    bool pts_reset;
};

struct mp_chmap {
    int num;
};

struct MPContext {
    struct MPOpts *opts;
    struct ao *ao;
    struct ao_chain *ao_chain;
    struct vo_chain *vo_chain;
    struct encode_lavc_context *encode_lavc_ctx;
    int audio_status;
    int video_status;
    double audio_speed;
    double delay;
    double last_av_difference;
    double audio_drop_throttle;
    bool display_sync_active;
    bool paused;
};

// Function declarations
void dump_audio_stats(struct MPContext *mpctx);
bool ao_query_and_reset_events(struct ao *ao, int event);
void reload_audio_output(struct MPContext *mpctx);
void ao_unblock(struct ao *ao);
void error_on_track(struct MPContext *mpctx, struct track *track);
void mp_pin_out_request_data(struct mp_pin *pin);
void reinit_audio_filters_and_output(struct MPContext *mpctx);
void MP_VERBOSE(struct MPContext *mpctx, const char *fmt, ...);
void mp_filter_reset(struct mp_filter *f);
void encode_lavc_stream_eof(struct encode_lavc_context *ctx, int stream);
double mp_time_sec(void);
void mp_set_timeout(struct MPContext *mpctx, double timeout);
void reset_playback_state(struct MPContext *mpctx);
void mp_wakeup_core(struct MPContext *mpctx);
void ao_get_format(struct ao *ao, int *rate, int *format, struct mp_chmap *chmap);
int af_format_sample_alignment(int format);
bool ao_untimed(struct ao *ao);
int ao_get_space(struct ao *ao);
bool get_sync_samples(struct MPContext *mpctx, int *skip);
void ao_reset(struct ao *ao);
int filter_audio(struct MPContext *mpctx, struct mp_audio_buffer *buf, int samples);
int mp_audio_buffer_samples(struct mp_audio_buffer *buf);
void mp_audio_buffer_skip(struct mp_audio_buffer *buf, int samples);
void mp_audio_buffer_prepend_silence(struct mp_audio_buffer *buf, int samples);
void MP_STATS(struct MPContext *mpctx, const char *tag);
void mp_audio_buffer_duplicate(struct mp_audio_buffer *buf, int samples);
void mp_audio_buffer_peek(struct mp_audio_buffer *buf, uint8_t ***planes, int *samples);
int write_to_ao(struct MPContext *mpctx, uint8_t **planes, int samples, int playflags);
bool ao_eof_reached(struct ao *ao);