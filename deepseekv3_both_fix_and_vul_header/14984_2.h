#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define IAX_IE_PROVISIONING 1
#define NEW_FORCE 1
#define IAX_PROVISION 1
#define AST_FRAME_IAX 1
#define IAX_COMMAND_PROVISION 1

struct iax_ie_data {
    char *buf;
    int pos;
};

struct iax_session {
    void *autoid;
    int flags;
};

struct create_addr_info {
    int sockfd;
};

extern struct iax_session *iaxs[];
extern pthread_mutex_t iaxsl[];
extern void *sched;

int iax_provision_build(struct iax_ie_data *provdata, unsigned int *sig, const char *template, int force);
int create_addr(char *dest, void *arg, struct sockaddr_in *sin, struct create_addr_info *cai);
int find_callno_locked(int arg1, int arg2, struct sockaddr_in *sin, int new_force, int sockfd, ...);
void *iax2_sched_replace(void *autoid, void *sched, int timeout, void (*callback)(void *), void *arg);
void ast_set_flag(struct iax_session *iax, int flag);
void send_command(struct iax_session *iax, int frame_type, int command, int arg1, char *buf, int pos, int arg2);
void ast_mutex_unlock(pthread_mutex_t *mutex);
void ast_debug(int level, const char *format, ...);
void auto_hangup(void *arg);
void iax_ie_append_raw(struct iax_ie_data *ied, int type, char *buf, int pos);