#include <stddef.h>

#define FALSE 0
typedef int gboolean;
typedef void* gpointer;
typedef int gint;
typedef int b_input_condition;

struct im_connection;
struct file_transfer;

struct PurpleXfer {
    void* account;
    char* who;
    char* filename;
    size_t size;
    void* ui_data;
};

struct PurpleBuddy {
    const char* (*get_name)(struct PurpleBuddy*);
};

struct prpl_xfer_data {
    struct file_transfer *ft;
};

struct file_transfer {
    void *data;
    void (*accept)(struct file_transfer *ft);
    void (*canceled)(struct file_transfer *ft);
    void (*free)(struct file_transfer *ft);
    void (*write_request)(struct file_transfer *ft);
};

void prpl_xfer_accept(struct file_transfer *ft);
void prpl_xfer_canceled(struct file_transfer *ft);
void prpl_xfer_free(struct file_transfer *ft);
void prpl_xfer_write_request(struct file_transfer *ft);

struct im_connection* purple_ic_by_pa(void* account);
struct PurpleBuddy* purple_find_buddy(void* account, const char* who);
const char* purple_buddy_get_name(struct PurpleBuddy* buddy);
struct file_transfer* imcb_file_send_start(struct im_connection* ic, char* who, char* filename, size_t size);

typedef struct PurpleXfer PurpleXfer;
typedef struct PurpleBuddy PurpleBuddy;