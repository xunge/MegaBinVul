#include <stddef.h>

typedef struct file_transfer_t file_transfer_t;
typedef struct bee_user_t bee_user_t;
typedef struct bee_t bee_t;
typedef struct bee_ui bee_ui;
typedef struct im_connection im_connection;

struct bee_ui {
    file_transfer_t* (*ft_in_start)(bee_t *bee, bee_user_t *bu, char *file_name, size_t file_size);
};

struct bee_t {
    bee_ui *ui;
};

struct im_connection {
    bee_t *bee;
};

bee_user_t *bee_user_by_handle(bee_t *bee, im_connection *ic, char *handle);