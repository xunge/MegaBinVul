#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>

typedef struct {
    int uuid;
} cluster_data_t;

typedef struct {
    int active;
} fio_data_t;

typedef struct fio_protocol_s fio_protocol_s;

extern cluster_data_t cluster_data;
extern fio_data_t *fio_data;

pid_t fio_parent_pid(void);
void fio_stop(void);