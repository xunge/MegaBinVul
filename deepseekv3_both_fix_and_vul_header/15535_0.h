#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    int active;
} fio_data_t;

extern fio_data_t *fio_data;

extern uint8_t fio_is_master(void);
extern void fio_on_fork(void);
extern void fio_defer_perform(void);
extern void fio_state_callback_force(int);
extern void fio_state_callback_clear_all(void);
extern void fio_poll_close(void);
extern void fio_timer_clear_all(void);
extern void fio_free(void *);
extern void fio_mem_destroy(void);

#define FIO_CALL_AT_EXIT 0
#define FIO_LOG_DEBUG(...)