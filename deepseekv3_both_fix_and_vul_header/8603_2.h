#include <stddef.h>
#include <pthread.h>

struct tty_struct {
    pthread_rwlock_t termios_rwsem;
    struct {
        int c_line;
    } termios;
    void *disc_data;
    int receive_room;
};

void down_write(pthread_rwlock_t *lock);
void up_write(pthread_rwlock_t *lock);