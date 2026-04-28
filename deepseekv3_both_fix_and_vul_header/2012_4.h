#include <stdatomic.h>

struct fsnotify_group;
struct user_struct {
    atomic_int inotify_devs;
};

struct inotify_data {
    struct user_struct *user;
    int idr;
};

struct fsnotify_group {
    struct inotify_data inotify_data;
};

typedef void (*idr_callback_t)(int id, void *ptr, void *data);
static void idr_callback(int id, void *ptr, void *data) {}

void idr_for_each(int *idr, idr_callback_t callback, void *data);
void idr_remove_all(int *idr);
void idr_destroy(int *idr);
void free_uid(struct user_struct *user);