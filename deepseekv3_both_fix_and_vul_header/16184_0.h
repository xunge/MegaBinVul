#include <stddef.h>

struct att_send_op {
    void *user_data;
    void (*callback)(void);
    void (*destroy)(void *);
};