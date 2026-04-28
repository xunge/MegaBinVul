#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int Bool;

#define FDNULL (-1)

typedef struct {
    int fd;
    u8 video_cnt;
    u8 audio_cnt;
    void **video_streams;
    void **audio_streams;
} mpeg2ps_t;

typedef struct {
    int m_fd;
    u8 m_stream_id;
    u8 first_pes_has_dts;
    u8 is_video;
    u32 ticks_per_frame;
    u32 samples_per_frame;
    u32 freq;
    u64 start_dts;
    struct {
        u8 have_dts;
        u8 have_pts;
        u64 dts;
        u64 pts;
    } frame_ts;
} mpeg2ps_stream_t;

void file_seek_to(int fd, int pos);
void clear_stream_buffer(mpeg2ps_stream_t *sptr);
int mpeg2ps_stream_read_frame(mpeg2ps_stream_t *sptr, u8 **buffer, u32 *buflen, int flag);
void get_info_from_frame(mpeg2ps_stream_t *sptr, u8 *buffer, u32 buflen);
void advance_frame(mpeg2ps_stream_t *sptr);