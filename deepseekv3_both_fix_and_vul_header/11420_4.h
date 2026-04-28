#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <cinttypes>

struct HttpConfigParams {
    int inbound_ip4;
    int inbound_ip6;
    int outbound_ip4;
    int outbound_ip6;
    char *proxy_hostname;
    size_t proxy_hostname_len;
    int no_dns_forward_to_parent;
    int no_origin_server_dns;
    struct {
        int uncacheable_requests_bypass_parent;
        int maintain_pristine_host_hdr;
        int forward_connect_method;
        int server_tcp_init_cwnd;
        int origin_max_connections;
        int origin_max_connections_queue;
        int attach_server_session_to_client;
        int insert_request_via_string;
        int insert_response_via_string;
        int proxy_response_hsts_max_age;
        int proxy_response_hsts_include_subdomains;
        int keep_alive_enabled_in;
        int keep_alive_enabled_out;
        int chunking_enabled;
        int auth_server_session_private;
        int http_chunking_size;
        int post_check_content_length_enabled;
        int flow_control_enabled;
        int flow_high_water_mark;
        int flow_low_water_mark;
        int server_session_sharing_match;
        int keep_alive_post_out;
        int keep_alive_no_activity_timeout_in;
        int keep_alive_no_activity_timeout_out;
        int transaction_no_activity_timeout_in;
        int transaction_no_activity_timeout_out;
        int transaction_active_timeout_in;
        int transaction_active_timeout_out;
        int websocket_active_timeout;
        int websocket_inactive_timeout;
        int background_fill_active_timeout;
        int background_fill_threshold;
        int connect_attempts_max_retries;
        int connect_attempts_max_retries_dead_server;
        int connect_attempts_rr_retries;
        int connect_attempts_timeout;
        int post_connect_attempts_timeout;
        int parent_connect_attempts;
        int parent_retry_time;
        int parent_fail_threshold;
        int per_parent_connect_attempts;
        int parent_connect_timeout;
        int parent_failures_update_hostdb;
        int sock_recv_buffer_size_out;
        int sock_send_buffer_size_out;
        int sock_packet_mark_out;
        int sock_packet_tos_out;
        int sock_option_flag_out;
        int fwd_proxy_auth_to_parent;
        int anonymize_remove_from;
        int anonymize_remove_referer;
        int anonymize_remove_user_agent;
        int anonymize_remove_cookie;
        int anonymize_remove_client_ip;
        int anonymize_insert_client_ip;
        char *global_user_agent_header;
        size_t global_user_agent_header_size;
        char *proxy_response_server_string;
        size_t proxy_response_server_string_len;
        int proxy_response_server_enabled;
        int insert_squid_x_forwarded_for;
        int insert_forwarded;
        int insert_age_in_response;
        int normalize_ae;
        int cache_heuristic_min_lifetime;
        int cache_heuristic_max_lifetime;
        float cache_heuristic_lm_factor;
        int cache_guaranteed_min_lifetime;
        int cache_guaranteed_max_lifetime;
        int cache_max_stale_age;
        char *cache_vary_default_text;
        char *cache_vary_default_images;
        char *cache_vary_default_other;
        int srv_enabled;
        int max_cache_open_read_retries;
        int cache_open_read_retry_time;
        int cache_generation_number;
        int max_cache_open_write_retries;
        int cache_http;
        int cache_ignore_client_no_cache;
        int cache_ignore_client_cc_max_age;
        int cache_ims_on_client_no_cache;
        int cache_ignore_server_no_cache;
        int cache_responses_to_cookies;
        int cache_ignore_auth;
        int cache_urls_that_look_dynamic;
        int cache_enable_default_vary_headers;
        int ignore_accept_mismatch;
        int ignore_accept_language_mismatch;
        int ignore_accept_encoding_mismatch;
        int ignore_accept_charset_mismatch;
        int cache_open_write_fail_action;
        int cache_when_to_revalidate;
        int cache_required_headers;
        int cache_range_lookup;
        int cache_range_write;
        int allow_multi_range;
        int request_hdr_max_size;
        int response_hdr_max_size;
        int slow_log_threshold;
        int ssl_client_verify_server;
        int send_http11_requests;
        int doc_in_cache_skip_dns;
        int default_buffer_size_index;
        int default_buffer_water_mark;
        char *body_factory_template_base;
        size_t body_factory_template_base_len;
        int down_server_timeout;
        int client_abort_threshold;
        int negative_caching_enabled;
        int negative_caching_lifetime;
        int negative_revalidating_enabled;
        int negative_revalidating_lifetime;
        int redirect_use_orig_cache_key;
        int number_of_redirections;
        char *client_cert_filename;
        char *client_cert_filepath;
    } oride;
    int use_client_target_addr;
    int use_client_source_port;
    int disable_ssl_parenting;
    int server_max_connections;
    int max_websocket_connections;
    int origin_min_keep_alive_connections;
    char *proxy_request_via_string;
    size_t proxy_request_via_string_len;
    char *proxy_response_via_string;
    size_t proxy_response_via_string_len;
    int server_session_sharing_pool;
    int accept_no_activity_timeout;
    char *anonymize_other_header_list;
    int enable_http_stats;
    int cache_post_method;
    int send_100_continue_response;
    int disallow_post_100_continue;
    int parser_allow_non_http;
    int keepalive_internal_vc;
    int max_post_size;
    char *connect_ports_string;
    int *connect_ports;
    int push_method_enabled;
    int reverse_proxy_enabled;
    int url_remap_required;
    int errors_log_error_pages;
    int record_cop_page;
    int enable_http_info;
    int body_factory_response_max_size;
    char *reverse_proxy_no_host_redirect;
    size_t reverse_proxy_no_host_redirect_len;
    int referer_filter_enabled;
    int referer_format_redirect;
    int strict_uri_parsing;
    int redirection_host_no_port;
    int post_copy_size;
    int synthetic_port;
};

class HttpConfig {
public:
    void reconfigure();
    HttpConfigParams m_master;
    int m_id;
};

class ConfigProcessor {
public:
    static int set(int id, HttpConfigParams *params);
};

class SocketManager {
public:
    static bool fastopen_supported();
};

class NetVCOptions {
public:
    static const int SOCK_OPT_TCP_FAST_OPEN;
};

class Warning {
public:
    Warning(const char *msg, ...);
};

class Status {
public:
    Status(const char *msg);
};

char *ats_strdup(const char *str);
int *parse_ports_list(const char *str);

extern ConfigProcessor configProcessor;