#include <stdint.h>
#include <assert.h>

class Http2 {
public:
    static uint32_t max_concurrent_streams_in;
    static uint32_t min_concurrent_streams_in;
    static uint32_t max_active_streams_in;
    static uint32_t stream_priority_enabled;
    static uint32_t initial_window_size;
    static uint32_t max_frame_size;
    static uint32_t header_table_size;
    static uint32_t max_header_list_size;
    static uint32_t accept_no_activity_timeout;
    static uint32_t no_activity_timeout_in;
    static uint32_t active_timeout_in;
    static uint32_t push_diary_size;
    static uint32_t zombie_timeout_in;
    static float stream_error_rate_threshold;
    static uint32_t stream_error_sampling_threshold;
    static uint32_t max_settings_per_frame;
    static uint32_t max_settings_per_minute;
    static uint32_t max_settings_frames_per_minute;
    static uint32_t max_ping_frames_per_minute;
    static uint32_t max_priority_frames_per_minute;
    static uint32_t max_rst_stream_frames_per_minute;
    static float min_avg_window_update;
    static uint32_t con_slow_log_threshold;
    static uint32_t stream_slow_log_threshold;
    static uint32_t header_table_size_limit;
    static uint32_t write_buffer_block_size;
    static float write_size_threshold;
    static uint32_t write_time_threshold;
    static uint32_t buffer_water_mark;
    
    static void init();
};

enum {
    HTTP2_SETTINGS_MAX_CONCURRENT_STREAMS,
    HTTP2_SETTINGS_INITIAL_WINDOW_SIZE,
    HTTP2_SETTINGS_MAX_FRAME_SIZE,
    HTTP2_SETTINGS_HEADER_TABLE_SIZE,
    HTTP2_SETTINGS_MAX_HEADER_LIST_SIZE
};

enum {
    HTTP2_STAT_CURRENT_CLIENT_SESSION_COUNT,
    HTTP2_STAT_CURRENT_ACTIVE_CLIENT_CONNECTION_COUNT,
    HTTP2_STAT_CURRENT_CLIENT_STREAM_COUNT,
    HTTP2_STAT_TOTAL_CLIENT_STREAM_COUNT,
    HTTP2_STAT_TOTAL_TRANSACTIONS_TIME,
    HTTP2_STAT_TOTAL_CLIENT_CONNECTION_COUNT,
    HTTP2_STAT_CONNECTION_ERRORS_COUNT,
    HTTP2_STAT_STREAM_ERRORS_COUNT,
    HTTP2_STAT_SESSION_DIE_DEFAULT,
    HTTP2_STAT_SESSION_DIE_OTHER,
    HTTP2_STAT_SESSION_DIE_EOS,
    HTTP2_STAT_SESSION_DIE_ACTIVE,
    HTTP2_STAT_SESSION_DIE_INACTIVE,
    HTTP2_STAT_SESSION_DIE_ERROR,
    HTTP2_STAT_SESSION_DIE_HIGH_ERROR_RATE,
    HTTP2_STAT_MAX_SETTINGS_PER_FRAME_EXCEEDED,
    HTTP2_STAT_MAX_SETTINGS_PER_MINUTE_EXCEEDED,
    HTTP2_STAT_MAX_SETTINGS_FRAMES_PER_MINUTE_EXCEEDED,
    HTTP2_STAT_MAX_PING_FRAMES_PER_MINUTE_EXCEEDED,
    HTTP2_STAT_MAX_PRIORITY_FRAMES_PER_MINUTE_EXCEEDED,
    HTTP2_STAT_MAX_RST_STREAM_FRAMES_PER_MINUTE_EXCEEDED,
    HTTP2_STAT_INSUFFICIENT_AVG_WINDOW_UPDATE,
    HTTP2_STAT_MAX_CONCURRENT_STREAMS_EXCEEDED_IN,
    HTTP2_STAT_MAX_CONCURRENT_STREAMS_EXCEEDED_OUT,
    HTTP2_N_STATS
};

enum {
    RECT_PROCESS,
    RECT_NODE,
    RECT_CLUSTER,
    RECT_LOCAL
};

enum {
    RECD_INT,
    RECD_COUNTER,
    RECD_FLOAT,
    RECD_STRING,
    RECD_NULL
};

enum {
    RECP_NON_PERSISTENT,
    RECP_PERSISTENT
};

static int http2_rsb;

struct Http2SettingsParameter {
    int id;
    uint32_t value;
};

const char* HTTP2_STAT_CURRENT_CLIENT_CONNECTION_NAME = "proxy.process.http2.current_client_connections";
const char* HTTP2_STAT_CURRENT_ACTIVE_CLIENT_CONNECTION_NAME = "proxy.process.http2.current_active_client_connections";
const char* HTTP2_STAT_CURRENT_CLIENT_STREAM_NAME = "proxy.process.http2.current_client_streams";
const char* HTTP2_STAT_TOTAL_CLIENT_STREAM_NAME = "proxy.process.http2.total_client_streams";
const char* HTTP2_STAT_TOTAL_TRANSACTIONS_TIME_NAME = "proxy.process.http2.total_transactions_time";
const char* HTTP2_STAT_TOTAL_CLIENT_CONNECTION_NAME = "proxy.process.http2.total_client_connections";
const char* HTTP2_STAT_CONNECTION_ERRORS_NAME = "proxy.process.http2.connection_errors";
const char* HTTP2_STAT_STREAM_ERRORS_NAME = "proxy.process.http2.stream_errors";
const char* HTTP2_STAT_SESSION_DIE_DEFAULT_NAME = "proxy.process.http2.session_die_default";
const char* HTTP2_STAT_SESSION_DIE_OTHER_NAME = "proxy.process.http2.session_die_other";
const char* HTTP2_STAT_SESSION_DIE_EOS_NAME = "proxy.process.http2.session_die_eos";
const char* HTTP2_STAT_SESSION_DIE_ACTIVE_NAME = "proxy.process.http2.session_die_active";
const char* HTTP2_STAT_SESSION_DIE_INACTIVE_NAME = "proxy.process.http2.session_die_inactive";
const char* HTTP2_STAT_SESSION_DIE_ERROR_NAME = "proxy.process.http2.session_die_error";
const char* HTTP2_STAT_SESSION_DIE_HIGH_ERROR_RATE_NAME = "proxy.process.http2.session_die_high_error_rate";
const char* HTTP2_STAT_MAX_SETTINGS_PER_FRAME_EXCEEDED_NAME = "proxy.process.http2.max_settings_per_frame_exceeded";
const char* HTTP2_STAT_MAX_SETTINGS_PER_MINUTE_EXCEEDED_NAME = "proxy.process.http2.max_settings_per_minute_exceeded";
const char* HTTP2_STAT_MAX_SETTINGS_FRAMES_PER_MINUTE_EXCEEDED_NAME = "proxy.process.http2.max_settings_frames_per_minute_exceeded";
const char* HTTP2_STAT_MAX_PING_FRAMES_PER_MINUTE_EXCEEDED_NAME = "proxy.process.http2.max_ping_frames_per_minute_exceeded";
const char* HTTP2_STAT_MAX_PRIORITY_FRAMES_PER_MINUTE_EXCEEDED_NAME = "proxy.process.http2.max_priority_frames_per_minute_exceeded";
const char* HTTP2_STAT_MAX_RST_STREAM_FRAMES_PER_MINUTE_EXCEEDED_NAME = "proxy.process.http2.max_rst_stream_frames_per_minute_exceeded";
const char* HTTP2_STAT_INSUFFICIENT_AVG_WINDOW_UPDATE_NAME = "proxy.process.http2.insufficient_avg_window_update";
const char* HTTP2_STAT_MAX_CONCURRENT_STREAMS_EXCEEDED_IN_NAME = "proxy.process.http2.max_concurrent_streams_exceeded_in";
const char* HTTP2_STAT_MAX_CONCURRENT_STREAMS_EXCEEDED_OUT_NAME = "proxy.process.http2.max_concurrent_streams_exceeded_out";

bool http2_settings_parameter_is_valid(Http2SettingsParameter param);
void http2_init();
void ink_release_assert(bool condition);
void REC_EstablishStaticConfigInt32U(uint32_t& var, const char* name);
void REC_EstablishStaticConfigFloat(float& var, const char* name);
int RecAllocateRawStatBlock(int size);
void RecRegisterRawStat(int block, int type, const char* name, int data_type, int persist_type, int offset, void (*sync_func)(int));
void RecSetRawStatSum(int block, int stat, int64_t value);
void RecSetRawStatCount(int block, int stat, int64_t value);
void RecRawStatSyncSum(int stat);
void RecRawStatSyncCount(int stat);