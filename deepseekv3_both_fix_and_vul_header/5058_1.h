#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

typedef char gchar;
typedef unsigned char bdaddr_t[6];

typedef enum {
    BT_IO_SEC_LOW,
    BT_IO_SEC_MEDIUM,
    BT_IO_SEC_HIGH
} BtIOSecLevel;

typedef struct {
    pthread_t thread;
    void *loop;
    int ref;
} gattlib_thread_t;

typedef struct gattlib_context {
    void *io;
} gattlib_context_t;

typedef struct gatt_connection {
    gattlib_context_t *context;
} gatt_connection_t;

typedef void (*gatt_connect_cb_t)(void *user_data);

typedef struct {
    char *message;
} GError;

typedef struct {
    gatt_connection_t *conn;
    gatt_connect_cb_t connect_cb;
    int connected;
    int timeout;
    GError *error;
} io_connect_arg_t;

#define BDADDR_LE_PUBLIC 0
#define BDADDR_LE_RANDOM 1
static const bdaddr_t BDADDR_ANY = {0, 0, 0, 0, 0, 0};
#define ATT_CID 4
#define CONNECTION_TIMEOUT 30
#define FALSE 0
#define BLUEZ_VERSION_MAJOR 5
#define BT_IO_L2CAP 0
#define BT_IO_OPT_SOURCE_BDADDR 0
#define BT_IO_OPT_SOURCE_TYPE 0
#define BT_IO_OPT_DEST_BDADDR 0
#define BT_IO_OPT_DEST_TYPE 0
#define BT_IO_OPT_CID 0
#define BT_IO_OPT_SEC_LEVEL 0
#define BT_IO_OPT_TIMEOUT 0
#define BT_IO_OPT_INVALID 0
#define BT_IO_OPT_PSM 0
#define BT_IO_OPT_IMTU 0

static gattlib_thread_t g_gattlib_thread;

void *connection_thread(void *arg);
void io_connect_cb(void *io, GError *err, void *user_data);
void *bt_io_connect(void *type, void *cb, void *arg, void *null, GError **err, ...);
int str2ba(const char *str, bdaddr_t *ba);
void bacpy(bdaddr_t *dst, const bdaddr_t *src);
int hci_devba(int dev_id, bdaddr_t *ba);
int g_main_loop_is_running(void *loop);
void g_error_free(GError *error);