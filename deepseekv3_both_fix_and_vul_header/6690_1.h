#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MY_REALM "Transmission"
#define HTTP_MOVEPERM 301
#define HTTP_NOTFOUND 404
#define TR_RPC_SESSION_ID_HEADER "X-Transmission-Session-Id"

struct evhttp_request {
    void* evcon;
    void* input_headers;
    void* output_headers;
    const char* uri;
    const char* remote_host;
};

struct tr_rpc_server {
    int loginattempts;
    const char* url;
    const char* username;
    const char* password;
    int isPasswordEnabled;
};

void evhttp_add_header(void* headers, const char* key, const char* value);
const char* evhttp_find_header(void* headers, const char* key);
int evutil_ascii_strncasecmp(const char* s1, const char* s2, size_t n);
void send_simple_response(struct evhttp_request* req, int code, const char* text);
int isAddressAllowed(struct tr_rpc_server* server, const char* host);
char* tr_base64_decode_str(const char* input, size_t* plen);
int tr_ssha1_matches(const char* ssha1, const char* pass);
char* tr_strdup_printf(const char* fmt, ...);
void tr_free(void* p);
void handle_web_client(struct evhttp_request* req, struct tr_rpc_server* server);
void handle_upload(struct evhttp_request* req, struct tr_rpc_server* server);
void handle_rpc(struct evhttp_request* req, struct tr_rpc_server* server);
#ifdef REQUIRE_SESSION_ID
int test_session_id(struct tr_rpc_server* server, struct evhttp_request* req);
const char* get_current_session_id(struct tr_rpc_server* server);
#endif