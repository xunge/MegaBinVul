#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int Bool;
typedef int GF_Err;
typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterStats GF_FilterStats;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_FilterPidInst GF_FilterPidInst;

#define GF_BAD_PARAM 0
#define GF_OK 1
#define GF_FALSE 0
#define GF_TRUE 1

struct GF_Fraction {
    int num;
    int den;
};

struct GF_FilterStats {
    GF_Filter *filter;
    GF_Filter *filter_alias;
    s32 percent;
    char *status;
    u64 nb_pck_processed;
    u64 nb_bytes_processed;
    u64 time_process;
    u64 nb_hw_pck_sent;
    u64 nb_pck_sent;
    u64 nb_bytes_sent;
    u64 nb_tasks_done;
    u64 nb_errors;
    char *name;
    char *reg_name;
    u32 filter_id;
    Bool done;
    Bool report_updated;
    u32 type;
    u32 nb_pid_out;
    u64 nb_out_pck;
    Bool in_eos;
    u32 codecid;
    u32 stream_type;
    u32 nb_pid_in;
    u64 nb_in_pck;
    struct GF_Fraction last_ts_sent;
    struct GF_Fraction last_ts_drop;
};

#define GF_FS_STATS_FILTER_RAWOUT 0
#define GF_FS_STATS_FILTER_RAWIN 1
#define GF_FS_STATS_FILTER_DECODE 2
#define GF_FS_STATS_FILTER_ENCODE 3
#define GF_FS_STATS_FILTER_DEMUX 4
#define GF_FS_STATS_FILTER_MEDIA_SINK 5
#define GF_FS_STATS_FILTER_MEDIA_SOURCE 6

struct GF_Filter {
    GF_Filter *multi_sink_target;
    u32 status_percent;
    char *status_str;
    u64 nb_pck_processed;
    u64 nb_bytes_processed;
    u64 time_process;
    u64 nb_hw_pck_sent;
    u64 nb_pck_sent;
    u64 nb_bytes_sent;
    u64 nb_tasks_done;
    u64 nb_errors;
    char *name;
    struct {
        char *name;
    } *freg;
    u32 id;
    Bool removed;
    Bool finalized;
    Bool report_updated;
    u32 num_output_pids;
    void *output_pids;
    u32 num_input_pids;
    void *input_pids;
    void *tasks_mx;
};

struct GF_FilterPid {
    u64 nb_pck_sent;
    Bool has_seen_eos;
    struct GF_Fraction last_ts_sent;
    u32 codecid;
    u32 stream_type;
    char *name;
};

struct GF_FilterPidInst {
    u64 nb_processed;
    Bool is_end_of_stream;
    Bool is_decoder_input;
    Bool is_encoder_input;
    GF_FilterPid *pid;
    struct GF_Fraction last_ts_drop;
};

#define GF_STREAM_FILE 0

void *gf_list_get(void *list, u32 index);
void gf_mx_p(void *mx);
void gf_mx_v(void *mx);
#define GF_EXPORT