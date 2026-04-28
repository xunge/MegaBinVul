#include <typeinfo>

enum TSOverridableConfigKey {
    TS_CONFIG_NULL,
    TS_CONFIG_URL_REMAP_PRISTINE_HOST_HDR,
    TS_CONFIG_HTTP_CHUNKING_ENABLED,
    TS_CONFIG_HTTP_NEGATIVE_CACHING_ENABLED,
    TS_CONFIG_HTTP_NEGATIVE_CACHING_LIFETIME,
    TS_CONFIG_HTTP_CACHE_WHEN_TO_REVALIDATE,
    TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_IN,
    TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_OUT,
    TS_CONFIG_HTTP_KEEP_ALIVE_POST_OUT,
    TS_CONFIG_HTTP_SERVER_SESSION_SHARING_MATCH,
    TS_CONFIG_NET_SOCK_RECV_BUFFER_SIZE_OUT,
    TS_CONFIG_NET_SOCK_SEND_BUFFER_SIZE_OUT,
    TS_CONFIG_NET_SOCK_OPTION_FLAG_OUT,
    TS_CONFIG_HTTP_FORWARD_PROXY_AUTH_TO_PARENT,
    TS_CONFIG_HTTP_ANONYMIZE_REMOVE_FROM,
    TS_CONFIG_HTTP_ANONYMIZE_REMOVE_REFERER,
    TS_CONFIG_HTTP_ANONYMIZE_REMOVE_USER_AGENT,
    TS_CONFIG_HTTP_ANONYMIZE_REMOVE_COOKIE,
    TS_CONFIG_HTTP_ANONYMIZE_REMOVE_CLIENT_IP,
    TS_CONFIG_HTTP_ANONYMIZE_INSERT_CLIENT_IP,
    TS_CONFIG_HTTP_RESPONSE_SERVER_ENABLED,
    TS_CONFIG_HTTP_INSERT_SQUID_X_FORWARDED_FOR,
    TS_CONFIG_HTTP_INSERT_FORWARDED,
    TS_CONFIG_HTTP_SERVER_TCP_INIT_CWND,
    TS_CONFIG_HTTP_SEND_HTTP11_REQUESTS,
    TS_CONFIG_HTTP_CACHE_HTTP,
    TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_NO_CACHE,
    TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_CC_MAX_AGE,
    TS_CONFIG_HTTP_CACHE_IMS_ON_CLIENT_NO_CACHE,
    TS_CONFIG_HTTP_CACHE_IGNORE_SERVER_NO_CACHE,
    TS_CONFIG_HTTP_CACHE_CACHE_RESPONSES_TO_COOKIES,
    TS_CONFIG_HTTP_CACHE_IGNORE_AUTHENTICATION,
    TS_CONFIG_HTTP_CACHE_CACHE_URLS_THAT_LOOK_DYNAMIC,
    TS_CONFIG_HTTP_CACHE_REQUIRED_HEADERS,
    TS_CONFIG_HTTP_INSERT_REQUEST_VIA_STR,
    TS_CONFIG_HTTP_INSERT_RESPONSE_VIA_STR,
    TS_CONFIG_HTTP_CACHE_HEURISTIC_MIN_LIFETIME,
    TS_CONFIG_HTTP_CACHE_HEURISTIC_MAX_LIFETIME,
    TS_CONFIG_HTTP_CACHE_GUARANTEED_MIN_LIFETIME,
    TS_CONFIG_HTTP_CACHE_GUARANTEED_MAX_LIFETIME,
    TS_CONFIG_HTTP_CACHE_MAX_STALE_AGE,
    TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_IN,
    TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_OUT,
    TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_IN,
    TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_OUT,
    TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_OUT,
    TS_CONFIG_HTTP_ORIGIN_MAX_CONNECTIONS,
    TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES,
    TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES_DEAD_SERVER,
    TS_CONFIG_HTTP_CONNECT_ATTEMPTS_RR_RETRIES,
    TS_CONFIG_HTTP_CONNECT_ATTEMPTS_TIMEOUT,
    TS_CONFIG_HTTP_POST_CONNECT_ATTEMPTS_TIMEOUT,
    TS_CONFIG_HTTP_DOWN_SERVER_CACHE_TIME,
    TS_CONFIG_HTTP_DOWN_SERVER_ABORT_THRESHOLD,
    TS_CONFIG_HTTP_DOC_IN_CACHE_SKIP_DNS,
    TS_CONFIG_HTTP_BACKGROUND_FILL_ACTIVE_TIMEOUT,
    TS_CONFIG_HTTP_RESPONSE_SERVER_STR,
    TS_CONFIG_HTTP_CACHE_HEURISTIC_LM_FACTOR,
    TS_CONFIG_HTTP_BACKGROUND_FILL_COMPLETED_THRESHOLD,
    TS_CONFIG_NET_SOCK_PACKET_MARK_OUT,
    TS_CONFIG_NET_SOCK_PACKET_TOS_OUT,
    TS_CONFIG_HTTP_INSERT_AGE_IN_RESPONSE,
    TS_CONFIG_HTTP_CHUNKING_SIZE,
    TS_CONFIG_HTTP_FLOW_CONTROL_ENABLED,
    TS_CONFIG_HTTP_FLOW_CONTROL_LOW_WATER_MARK,
    TS_CONFIG_HTTP_FLOW_CONTROL_HIGH_WATER_MARK,
    TS_CONFIG_HTTP_CACHE_RANGE_LOOKUP,
    TS_CONFIG_HTTP_NORMALIZE_AE,
    TS_CONFIG_HTTP_DEFAULT_BUFFER_SIZE,
    TS_CONFIG_HTTP_DEFAULT_BUFFER_WATER_MARK,
    TS_CONFIG_HTTP_REQUEST_HEADER_MAX_SIZE,
    TS_CONFIG_HTTP_RESPONSE_HEADER_MAX_SIZE,
    TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_ENABLED,
    TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_LIFETIME,
    TS_CONFIG_SSL_HSTS_MAX_AGE,
    TS_CONFIG_SSL_HSTS_INCLUDE_SUBDOMAINS,
    TS_CONFIG_HTTP_CACHE_OPEN_READ_RETRY_TIME,
    TS_CONFIG_HTTP_CACHE_MAX_OPEN_READ_RETRIES,
    TS_CONFIG_HTTP_CACHE_RANGE_WRITE,
    TS_CONFIG_HTTP_POST_CHECK_CONTENT_LENGTH_ENABLED,
    TS_CONFIG_HTTP_GLOBAL_USER_AGENT_HEADER,
    TS_CONFIG_HTTP_AUTH_SERVER_SESSION_PRIVATE,
    TS_CONFIG_HTTP_SLOW_LOG_THRESHOLD,
    TS_CONFIG_HTTP_CACHE_GENERATION,
    TS_CONFIG_BODY_FACTORY_TEMPLATE_BASE,
    TS_CONFIG_HTTP_CACHE_OPEN_WRITE_FAIL_ACTION,
    TS_CONFIG_HTTP_NUMBER_OF_REDIRECTIONS,
    TS_CONFIG_HTTP_CACHE_MAX_OPEN_WRITE_RETRIES,
    TS_CONFIG_HTTP_REDIRECT_USE_ORIG_CACHE_KEY,
    TS_CONFIG_HTTP_ATTACH_SERVER_SESSION_TO_CLIENT,
    TS_CONFIG_HTTP_ORIGIN_MAX_CONNECTIONS_QUEUE,
    TS_CONFIG_WEBSOCKET_NO_ACTIVITY_TIMEOUT,
    TS_CONFIG_WEBSOCKET_ACTIVE_TIMEOUT,
    TS_CONFIG_HTTP_UNCACHEABLE_REQUESTS_BYPASS_PARENT,
    TS_CONFIG_HTTP_PARENT_PROXY_TOTAL_CONNECT_ATTEMPTS,
    TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_IN,
    TS_CONFIG_SRV_ENABLED,
    TS_CONFIG_HTTP_FORWARD_CONNECT_METHOD,
    TS_CONFIG_SSL_CERT_FILENAME,
    TS_CONFIG_SSL_CERT_FILEPATH,
    TS_CONFIG_PARENT_FAILURES_UPDATE_HOSTDB,
    TS_CONFIG_SSL_CLIENT_VERIFY_SERVER,
    TS_CONFIG_HTTP_CACHE_ENABLE_DEFAULT_VARY_HEADER,
    TS_CONFIG_HTTP_CACHE_VARY_DEFAULT_TEXT,
    TS_CONFIG_HTTP_CACHE_VARY_DEFAULT_IMAGES,
    TS_CONFIG_HTTP_CACHE_VARY_DEFAULT_OTHER,
    TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_MISMATCH,
    TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_LANGUAGE_MISMATCH,
    TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_ENCODING_MISMATCH,
    TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_CHARSET_MISMATCH,
    TS_CONFIG_HTTP_PARENT_PROXY_FAIL_THRESHOLD,
    TS_CONFIG_HTTP_PARENT_PROXY_RETRY_TIME,
    TS_CONFIG_HTTP_PER_PARENT_CONNECT_ATTEMPTS,
    TS_CONFIG_HTTP_PARENT_CONNECT_ATTEMPT_TIMEOUT,
    TS_CONFIG_HTTP_ALLOW_MULTI_RANGE,
    TS_CONFIG_LAST_ENTRY
};

struct OverridableHttpConfigParams {
    int maintain_pristine_host_hdr;
    int chunking_enabled;
    int negative_caching_enabled;
    int negative_caching_lifetime;
    int cache_when_to_revalidate;
    int keep_alive_enabled_in;
    int keep_alive_enabled_out;
    int keep_alive_post_out;
    int server_session_sharing_match;
    int sock_recv_buffer_size_out;
    int sock_send_buffer_size_out;
    int sock_option_flag_out;
    int fwd_proxy_auth_to_parent;
    int anonymize_remove_from;
    int anonymize_remove_referer;
    int anonymize_remove_user_agent;
    int anonymize_remove_cookie;
    int anonymize_remove_client_ip;
    int anonymize_insert_client_ip;
    int proxy_response_server_enabled;
    int insert_squid_x_forwarded_for;
    int insert_forwarded;
    int server_tcp_init_cwnd;
    int send_http11_requests;
    int cache_http;
    int cache_ignore_client_no_cache;
    int cache_ignore_client_cc_max_age;
    int cache_ims_on_client_no_cache;
    int cache_ignore_server_no_cache;
    int cache_responses_to_cookies;
    int cache_ignore_auth;
    int cache_urls_that_look_dynamic;
    int cache_required_headers;
    int insert_request_via_string;
    int insert_response_via_string;
    int cache_heuristic_min_lifetime;
    int cache_heuristic_max_lifetime;
    int cache_guaranteed_min_lifetime;
    int cache_guaranteed_max_lifetime;
    int cache_max_stale_age;
    int keep_alive_no_activity_timeout_in;
    int keep_alive_no_activity_timeout_out;
    int transaction_no_activity_timeout_in;
    int transaction_no_activity_timeout_out;
    int transaction_active_timeout_out;
    int origin_max_connections;
    int connect_attempts_max_retries;
    int connect_attempts_max_retries_dead_server;
    int connect_attempts_rr_retries;
    int connect_attempts_timeout;
    int post_connect_attempts_timeout;
    int down_server_timeout;
    int client_abort_threshold;
    int doc_in_cache_skip_dns;
    int background_fill_active_timeout;
    int proxy_response_server_string;
    int cache_heuristic_lm_factor;
    int background_fill_threshold;
    int sock_packet_mark_out;
    int sock_packet_tos_out;
    int insert_age_in_response;
    int http_chunking_size;
    int flow_control_enabled;
    int flow_low_water_mark;
    int flow_high_water_mark;
    int cache_range_lookup;
    int normalize_ae;
    int default_buffer_size_index;
    int default_buffer_water_mark;
    int request_hdr_max_size;
    int response_hdr_max_size;
    int negative_revalidating_enabled;
    int negative_revalidating_lifetime;
    int proxy_response_hsts_max_age;
    int proxy_response_hsts_include_subdomains;
    int cache_open_read_retry_time;
    int max_cache_open_read_retries;
    int cache_range_write;
    int post_check_content_length_enabled;
    int global_user_agent_header;
    int auth_server_session_private;
    int slow_log_threshold;
    int cache_generation_number;
    int body_factory_template_base;
    int cache_open_write_fail_action;
    int number_of_redirections;
    int max_cache_open_write_retries;
    int redirect_use_orig_cache_key;
    int attach_server_session_to_client;
    int origin_max_connections_queue;
    int websocket_inactive_timeout;
    int websocket_active_timeout;
    int uncacheable_requests_bypass_parent;
    int parent_connect_attempts;
    int transaction_active_timeout_in;
    int srv_enabled;
    int forward_connect_method;
    int client_cert_filename;
    int client_cert_filepath;
    int parent_failures_update_hostdb;
    int ssl_client_verify_server;
    int cache_enable_default_vary_headers;
    int cache_vary_default_text;
    int cache_vary_default_images;
    int cache_vary_default_other;
    int ignore_accept_mismatch;
    int ignore_accept_language_mismatch;
    int ignore_accept_encoding_mismatch;
    int ignore_accept_charset_mismatch;
    int parent_fail_threshold;
    int parent_retry_time;
    int per_parent_connect_attempts;
    int parent_connect_timeout;
    int allow_multi_range;
};

static void* _memberp_to_generic(void* member, std::type_info const *&typep);