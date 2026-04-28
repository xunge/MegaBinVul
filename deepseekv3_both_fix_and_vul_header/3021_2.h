#include <string.h>
#include <pthread.h>
#include <stddef.h>

#define MAX_USERNAME_SIZE 256
#define MAX_PASSWORD_SIZE 256

enum securityEnum {
    Kerberos
};

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))

struct TCP_Server_Info {
    enum securityEnum secType;
    struct list_head smb_ses_list;
};

struct smb_vol {
    unsigned int linux_uid;
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
};

struct cifsSesInfo {
    unsigned int linux_uid;
    char userName[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
    int ses_count;
    struct list_head smb_ses_list;
};

pthread_rwlock_t cifs_tcp_ses_lock;

#define write_lock(lock) pthread_rwlock_wrlock(lock)
#define write_unlock(lock) pthread_rwlock_unlock(lock)