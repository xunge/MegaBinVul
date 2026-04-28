#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t tui32;
typedef uint16_t tui16;
typedef uint8_t tui8;

enum SCP_SERVER_STATES_E
{
    SCP_SERVER_STATE_OK,
    SCP_SERVER_STATE_VERSION_ERR,
    SCP_SERVER_STATE_NETWORK_ERR,
    SCP_SERVER_STATE_INTERNAL_ERR,
    SCP_SERVER_STATE_SEQUENCE_ERR
};

enum SCP_SESSION_TYPE_E
{
    SCP_SESSION_TYPE_XVNC,
    SCP_SESSION_TYPE_XRDP,
    SCP_SESSION_TYPE_XORG,
    SCP_GW_AUTHENTICATION
};

struct SCP_CONNECTION
{
    int in_sck;
    struct stream *in_s;
};

struct SCP_SESSION;

struct stream
{
    char *data;
    char *end;
};

void in_uint32_be(struct stream *s, tui32 v);
void in_uint16_be(struct stream *s, tui16 v);
void in_uint8a(struct stream *s, char *buf, int len);
int s_check_rem(struct stream *s, int len);
void init_stream(struct stream *s, int size);
int scp_tcp_force_recv(int sock, char *data, int len);
struct SCP_SESSION *scp_session_create(void);
void scp_session_destroy(struct SCP_SESSION *s);
void scp_session_set_version(struct SCP_SESSION *s, tui32 version);
void scp_session_set_type(struct SCP_SESSION *s, enum SCP_SESSION_TYPE_E type);
int scp_session_set_username(struct SCP_SESSION *s, const char *username);
int scp_session_set_password(struct SCP_SESSION *s, const char *password);
void scp_session_set_width(struct SCP_SESSION *s, tui16 width);
void scp_session_set_height(struct SCP_SESSION *s, tui16 height);
int scp_session_set_bpp(struct SCP_SESSION *s, tui8 bpp);
void scp_session_set_domain(struct SCP_SESSION *s, const char *domain);
void scp_session_set_program(struct SCP_SESSION *s, const char *program);
void scp_session_set_directory(struct SCP_SESSION *s, const char *directory);
void scp_session_set_client_ip(struct SCP_SESSION *s, const char *client_ip);
#define g_new0(type, size) calloc(1, (size) * sizeof(type))
#define g_free(ptr) free(ptr)
void log_message(int level, const char *format, ...);
#define LOG_LEVEL_WARNING 1
#define LOG_DBG(fmt, ...) log_message(LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)