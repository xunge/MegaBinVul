#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>

#define FORWARD_REMOTE 0x1
#define SSH2_MSG_REQUEST_SUCCESS 81
#define SSH2_MSG_REQUEST_FAILURE 82

struct Forward {
    char *listen_host;
    u_short listen_port;
    char *listen_path;
};

struct sshbuf;
struct Authctxt {
    struct passwd *pw;
    int valid;
};

extern struct Authctxt *the_authctxt;
extern int no_port_forwarding_flag;
extern int no_more_sessions;
extern int use_privsep;

struct ssh;
extern struct ssh *active_state;

struct sshbuf *sshbuf_new(void);
void sshbuf_free(struct sshbuf *buf);
int sshbuf_put_u32(struct sshbuf *buf, u_int32_t val);
const u_char *sshbuf_ptr(const struct sshbuf *buf);
size_t sshbuf_len(const struct sshbuf *buf);
char *ssh_err(int);

struct options {
    int allow_tcp_forwarding;
    int allow_streamlocal_forwarding;
    int disable_forwarding;
    struct {
        /* forward options fields */
    } fwd_opts;
};
extern struct options options;

char *packet_get_string(size_t *length_ptr);
int packet_get_char(void);
int packet_get_int(void);
void packet_start(int type);
void packet_send(void);
void packet_write_wait(void);
void packet_send_debug(const char *msg);
void ssh_packet_put_raw(struct ssh *ssh, const u_char *data, size_t len);

void debug(const char *fmt, ...);
void fatal(const char *fmt, ...);

int bind_permitted(u_short port, uid_t uid);
int channel_setup_remote_fwd_listener(struct Forward *fwd, int *allocated_port, void *opts);
int channel_cancel_rport_listener(struct Forward *fwd);
int server_input_hostkeys_prove(struct sshbuf **resp);