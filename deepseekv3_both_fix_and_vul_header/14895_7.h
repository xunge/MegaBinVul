#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

struct iax_ie_data {
    char buf[1024];
    int pos;
};

struct create_addr_info {
    int sockfd;
};

struct iax_session {
    int autoid;
};

struct sched_context;

extern int option_debug;
extern struct iax_session **iaxs;
extern pthread_mutex_t *iaxsl;
extern struct sched_context *sched;

#define LOG_DEBUG 0
#define IAX_IE_PROVISIONING 0
#define NEW_FORCE 0
#define IAX_PROVISION 0
#define AST_FRAME_IAX 0
#define IAX_COMMAND_PROVISION 0

void ast_log(int level, const char *format, ...);
int iax_provision_build(struct iax_ie_data *data, unsigned int *sig, const char *template, int force);
int create_addr(char *dest, void *arg, struct sockaddr_in *sin, struct create_addr_info *cai);
void iax_ie_append_raw(struct iax_ie_data *ied, int type, char *buf, int pos);
int find_callno_locked(int a, int b, struct sockaddr_in *sin, int flag, int sockfd, ...);
void AST_SCHED_DEL(struct sched_context *sched, int id);
int iax2_sched_add(struct sched_context *sched, int timeout, void (*callback)(void *), void *data);
void auto_hangup(void *data);
void ast_set_flag(struct iax_session *session, int flag);
void send_command(struct iax_session *session, int frame_type, int command, int seqno, char *buf, int len, int timestamp);
void ast_mutex_unlock(pthread_mutex_t *mutex);