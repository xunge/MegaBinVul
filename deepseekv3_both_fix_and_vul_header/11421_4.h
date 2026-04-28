#include <cstddef>
#include <cstdlib>
#include <cstring>

struct HttpConfigCont {
    void handleEvent(int, void*);
};

struct HttpConfigParams;
struct HttpForwarded;
struct HttpConfig;

const int http_stat_count = 0;
const int SessionSharingMatchStrings = 0;
const int SessionSharingPoolStrings = 0;

typedef void (*RecConfigUpdateCb)(const char*, void*, void*);

extern void* RecAllocateRawStatBlock(int);
extern void register_stat_callbacks();
extern void HttpEstablishStaticConfigStringAlloc(char*&, const char*);
extern void HttpEstablishStaticConfigLongLong(long long&, const char*);
extern void HttpEstablishStaticConfigByte(unsigned char&, const char*);
extern void HttpEstablishStaticConfigFloat(float&, const char*);
extern void RecHttpLoadIp(const char*, void*, void*);
extern void RecRegisterConfigUpdateCb(const char*, RecConfigUpdateCb, void*);
extern void http_config_enum_read(const char*, int, int&);
extern int REC_ERR_OKAY;
extern int RecGetRecordString(const char*, char*, int);
extern void Error(const char*, ...);
extern char* ats_malloc(size_t);

void http_server_session_sharing_cb(const char*, void*, void*);
void http_insert_forwarded_cb(const char*, void*, void*);

namespace ts {
    template<size_t>
    class LocalBufferWriter {
    public:
        LocalBufferWriter() {}
        size_t size() { return 0; }
        char* data() { return nullptr; }
    };
    class string_view {
    public:
        string_view(const char*) {}
    };
}

struct HttpForwarded {
    struct OptionBitSet {};
    static OptionBitSet optStrToBitset(ts::string_view, ts::LocalBufferWriter<1024>&) { return OptionBitSet(); }
};

struct HttpConfigParams {
    struct {
        long long server_tcp_init_cwnd;
        long long origin_max_connections;
        long long origin_max_connections_queue;
        unsigned char attach_server_session_to_client;
        unsigned char forward_connect_method;
        unsigned char uncacheable_requests_bypass_parent;
        unsigned char doc_in_cache_skip_dns;
        unsigned char maintain_pristine_host_hdr;
        unsigned char insert_request_via_string;
        unsigned char insert_response_via_string;
        long long proxy_response_hsts_max_age;
        unsigned char proxy_response_hsts_include_subdomains;
        char* client_cert_filename;
        char* client_cert_filepath;
        unsigned char keep_alive_enabled_in;
        unsigned char keep_alive_enabled_out;
        unsigned char chunking_enabled;
        long long http_chunking_size;
        unsigned char flow_control_enabled;
        long long flow_high_water_mark;
        long long flow_low_water_mark;
        unsigned char post_check_content_length_enabled;
        int server_session_sharing_match;
        unsigned char auth_server_session_private;
        unsigned char keep_alive_post_out;
        long long keep_alive_no_activity_timeout_in;
        long long keep_alive_no_activity_timeout_out;
        long long transaction_no_activity_timeout_in;
        long long transaction_no_activity_timeout_out;
        long long websocket_active_timeout;
        long long websocket_inactive_timeout;
        long long transaction_active_timeout_in;
        long long transaction_active_timeout_out;
        long long background_fill_active_timeout;
        float background_fill_threshold;
        long long connect_attempts_max_retries;
        long long connect_attempts_max_retries_dead_server;
        long long connect_attempts_rr_retries;
        long long connect_attempts_timeout;
        long long post_connect_attempts_timeout;
        long long parent_connect_attempts;
        long long parent_retry_time;
        long long parent_fail_threshold;
        long long per_parent_connect_attempts;
        long long parent_connect_timeout;
        unsigned char parent_failures_update_hostdb;
        long long sock_recv_buffer_size_out;
        long long sock_send_buffer_size_out;
        long long sock_option_flag_out;
        long long sock_packet_mark_out;
        long long sock_packet_tos_out;
        unsigned char fwd_proxy_auth_to_parent;
        unsigned char anonymize_remove_from;
        unsigned char anonymize_remove_referer;
        unsigned char anonymize_remove_user_agent;
        unsigned char anonymize_remove_cookie;
        unsigned char anonymize_remove_client_ip;
        unsigned char anonymize_insert_client_ip;
        char* global_user_agent_header;
        size_t global_user_agent_header_size;
        unsigned char proxy_response_server_enabled;
        char* proxy_response_server_string;
        size_t proxy_response_server_string_len;
        unsigned char insert_squid_x_forwarded_for;
        unsigned char insert_age_in_response;
        unsigned char normalize_ae;
        long long cache_heuristic_min_lifetime;
        long long cache_heuristic_max_lifetime;
        float cache_heuristic_lm_factor;
        long long cache_guaranteed_min_lifetime;
        long long cache_guaranteed_max_lifetime;
        long long cache_max_stale_age;
        unsigned char srv_enabled;
        char* cache_vary_default_text;
        char* cache_vary_default_images;
        char* cache_vary_default_other;
        long long max_cache_open_read_retries;
        long long cache_open_read_retry_time;
        long long cache_generation_number;
        long long max_cache_open_write_retries;
        unsigned char cache_http;
        unsigned char cache_ignore_client_no_cache;
        unsigned char cache_ignore_client_cc_max_age;
        unsigned char cache_ims_on_client_no_cache;
        unsigned char cache_ignore_server_no_cache;
        unsigned char cache_responses_to_cookies;
        unsigned char cache_ignore_auth;
        unsigned char cache_urls_that_look_dynamic;
        unsigned char cache_enable_default_vary_headers;
        unsigned char ignore_accept_mismatch;
        unsigned char ignore_accept_language_mismatch;
        unsigned char ignore_accept_encoding_mismatch;
        unsigned char ignore_accept_charset_mismatch;
        unsigned char cache_open_write_fail_action;
        unsigned char cache_when_to_revalidate;
        unsigned char cache_required_headers;
        unsigned char cache_range_lookup;
        unsigned char cache_range_write;
        long long request_hdr_max_size;
        long long response_hdr_max_size;
        unsigned char ssl_client_verify_server;
        unsigned char send_http11_requests;
        unsigned char allow_multi_range;
        long long down_server_timeout;
        long long client_abort_threshold;
        unsigned char negative_caching_enabled;
        long long negative_caching_lifetime;
        unsigned char negative_revalidating_enabled;
        long long negative_revalidating_lifetime;
        long long default_buffer_size_index;
        long long default_buffer_water_mark;
        unsigned char redirect_use_orig_cache_key;
        HttpForwarded::OptionBitSet insert_forwarded;
        char* body_factory_template_base;
        size_t body_factory_template_base_len;
        long long slow_log_threshold;
        long long number_of_redirections;
    } oride;
    char* proxy_hostname;
    int proxy_hostname_len;
    void* inbound_ip4;
    void* inbound_ip6;
    void* outbound_ip4;
    void* outbound_ip6;
    long long server_max_connections;
    long long max_websocket_connections;
    long long origin_min_keep_alive_connections;
    unsigned char disable_ssl_parenting;
    unsigned char no_dns_forward_to_parent;
    unsigned char no_origin_server_dns;
    unsigned char use_client_target_addr;
    unsigned char use_client_source_port;
    char* proxy_request_via_string;
    int proxy_request_via_string_len;
    char* proxy_response_via_string;
    int proxy_response_via_string_len;
    unsigned char strict_uri_parsing;
    int server_session_sharing_pool;
    unsigned char cache_post_method;
    unsigned char send_100_continue_response;
    unsigned char disallow_post_100_continue;
    unsigned char parser_allow_non_http;
    unsigned char keepalive_internal_vc;
    char* connect_ports_string;
    unsigned char push_method_enabled;
    unsigned char reverse_proxy_enabled;
    unsigned char url_remap_required;
    char* reverse_proxy_no_host_redirect;
    int reverse_proxy_no_host_redirect_len;
    long long body_factory_response_max_size;
    unsigned char errors_log_error_pages;
    unsigned char record_cop_page;
    unsigned char referer_filter_enabled;
    unsigned char referer_format_redirect;
    unsigned char enable_http_stats;
    unsigned char enable_http_info;
    long long max_post_size;
    unsigned char redirection_host_no_port;
    long long post_copy_size;
    long long synthetic_port;
    long long accept_no_activity_timeout;
    char* anonymize_other_header_list;
};

struct HttpConfig {
    HttpConfigParams m_master;
    void* http_rsb;
    HttpConfigCont* http_config_cont;
    void startup();
};

const int EVENT_NONE = 0;