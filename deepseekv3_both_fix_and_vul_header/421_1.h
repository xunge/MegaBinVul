#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <limits.h>
#include <sys/select.h>
#include <stdint.h>

typedef void (*callback_remove_handler)(int);
typedef enum {
    UV_DEBUG_TRANSFILE,
    UV_DEBUG_ALL,
    UV_DEBUG_PROCESS,
    UV_DEBUG_ERROR
} univention_debug_level_t;

typedef enum network_protocol {
    PROTOCOL_UNKNOWN,
    PROTOCOL_3,
    PROTOCOL_LAST
} network_protocol;

extern fd_set readfds;
extern int sem_id;
extern unsigned long SCHEMA_ID;
extern network_protocol network_procotol_version;
extern struct {
    unsigned long id;
} notify_last_id;

void univention_debug(univention_debug_level_t, univention_debug_level_t, const char *, ...);
network_protocol network_client_get_version(int);
void network_client_set_version(int, network_protocol);
void network_client_set_next_id(int, unsigned long);
void network_client_set_msg_id(int, unsigned long);
void network_client_dump(void);
int get_network_line(char *, char *);
char *notifier_cache_get(unsigned long);
char *notify_transcation_get_one_dn(unsigned long);
void p_sem(int);
void v_sem(int);