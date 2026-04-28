#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>

struct list_head {
    struct list_head *next, *prev;
};

struct TCP_Server_Info {
    struct {
        struct sockaddr_in sockAddr;
        struct sockaddr_in6 sockAddr6;
    } addr;
    struct list_head smb_ses_list;
};

struct smb_vol {
    char *username;
    char *password;
    char *domainname;
    uid_t linux_uid;
    unsigned int secFlg;
    void *local_nls;
};

struct cifsSesInfo {
    struct TCP_Server_Info *server;
    char serverName[64];
    char userName[256];
    char *password;
    char *domainName;
    uid_t linux_uid;
    unsigned int overrideSecFlg;
    pthread_mutex_t session_mutex;
    int status;
    int need_reconnect;
    struct list_head smb_ses_list;
};

pthread_mutex_t cifs_tcp_ses_lock = PTHREAD_MUTEX_INITIALIZER;
#define MAX_USERNAME_SIZE 256
#define ENOMEM 12
#define GFP_KERNEL 0

static inline void *ERR_PTR(long error) { return (void *)error; }
static inline int GetXid(void) { return 0; }
static inline void FreeXid(int xid) {}
static inline void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline void write_lock(pthread_mutex_t *lock) { pthread_mutex_lock(lock); }
static inline void write_unlock(pthread_mutex_t *lock) { pthread_mutex_unlock(lock); }
static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}