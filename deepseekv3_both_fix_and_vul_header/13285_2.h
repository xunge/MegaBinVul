#include <stdint.h>
#include <stddef.h>

typedef uint16_t __u16;
typedef unsigned int gfp_t;

#define SCTP_STREAM_OPEN 0
#define __GFP_NOWARN 0

struct sctp_stream_out {
    int state;
};

struct sctp_stream {
    struct sctp_stream_out *out;
    void *in;
    __u16 outcnt;
};

struct sctp_sched_ops {
    void (*unsched_all)(struct sctp_stream *);
    void (*sched_all)(struct sctp_stream *);
    void (*free)(struct sctp_stream *);
};

#define SCTP_SO(stream, i) ((stream)->out + (i))

static inline struct sctp_sched_ops *sctp_sched_ops_from_stream(struct sctp_stream *stream) {
    return (struct sctp_sched_ops *)0;
}

static inline void sctp_stream_outq_migrate(struct sctp_stream *stream, void *a, __u16 b) {}
static inline int sctp_stream_alloc_out(struct sctp_stream *stream, __u16 cnt, gfp_t gfp) { return 0; }
static inline void sctp_stream_interleave_init(struct sctp_stream *stream) {}
static inline int sctp_stream_alloc_in(struct sctp_stream *stream, __u16 cnt, gfp_t gfp) { return 0; }
static inline void genradix_free(void **ptr) {}