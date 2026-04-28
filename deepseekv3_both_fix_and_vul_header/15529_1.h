#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define FIO_SLOWLORIS_LIMIT 1024

typedef struct {
    const char *data;
    size_t len;
} fio_str_info_s;

typedef struct {
    int (*write_func)(int, const void *);
} fio_packet_s;

typedef struct {
    int sock_lock;
    fio_packet_s *packet;
    size_t sent;
    size_t packet_count;
    int close;
    int open;
    struct {
        ssize_t (*flush)(intptr_t, void *);
    } *rw_hooks;
    void *rw_udata;
} uuid_data_t;

extern uuid_data_t *uuid_data_ptr(intptr_t uuid);
#define uuid_data(uuid) (*uuid_data_ptr(uuid))

extern int fio_trylock(int *lock);
extern void fio_unlock(int *lock);
extern int fio_uuid2fd(intptr_t uuid);
extern void touchfd(int fd);
extern void fio_force_close(intptr_t uuid);
extern void fio_clear_fd(int fd, int flags);
extern fio_str_info_s fio_peer_addr(intptr_t uuid);
extern int uuid_is_valid(intptr_t uuid);

#define FIO_LOG_ERROR(...)
#define FIO_LOG_WARNING(...)