#include <signal.h>
#include <unistd.h>

typedef struct {
    size_t len;
} fio_str_info_s;

pid_t fio_parent_pid(void);
void fio_stop(void);
void fio_cluster_server_sender(void *, int);
void *fio_msg_internal_create(int, int, fio_str_info_s, fio_str_info_s, int, int);

#define FIO_CLUSTER_MSG_SHUTDOWN 0