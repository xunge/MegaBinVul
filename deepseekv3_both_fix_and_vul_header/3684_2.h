#include <string.h>
#include <pthread.h>

struct snd_kcontrol {
    void *private_data;
};

struct snd_ctl_elem_value {
    char value[256];  // Assuming a reasonable size for the value field
};

struct user_element {
    void *elem_data;
    size_t elem_data_size;
    struct {
        pthread_mutex_t user_ctl_lock;
    } *card;
};

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock