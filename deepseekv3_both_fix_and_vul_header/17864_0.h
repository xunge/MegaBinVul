#include <stddef.h>

struct ndpi_packet_struct {
    int parsed_lines;
    int empty_line_position_set;
    struct {
        const char *ptr;
        size_t len;
    } host_line, referer_line, content_line, accept_line, user_agent_line, http_url_name, http_encoding, http_transfer_encoding, http_contentlen, content_disposition_line, http_cookie, http_origin, http_x_session_type, server_line, http_method, http_response;
    int http_num_headers;
};