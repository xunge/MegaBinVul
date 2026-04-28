#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct {
    int is_worker;
    pid_t parent;
    size_t max_protocol_fd;
} fio_data_t;

typedef struct {
    void *protocol;
    int open;
} fd_data_t;

extern fio_data_t *fio_data;

#define FIO_LOG_INFO(...)
#define FIO_CALL_ON_SHUTDOWN 0
#define FIO_CALL_ON_FINISH 0

void fio_state_callback_force(int);
void fio_defer_push_task(void (*)(void *, void *), void *, void *);
void fio_defer_perform(void);
void fio_force_close(void *);
void fio_cluster_signal_children(void);
void fio_signal_handler_reset(void);
void deferred_on_shutdown(void *, void *);
void fio_cycle_unwind(void *, void *);
void *fd2uuid(size_t);
fd_data_t fd_data(size_t);