#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int guint;

typedef enum {
    PK_EXIT_ENUM_SUCCESS = 0,
    PK_EXIT_ENUM_FAILED = 1,
    PK_EXIT_ENUM_CANCELLED = 2
} PkExitEnum;

typedef struct {
    bool emitted_finished;
    void *connection;
    char *tid;
} PkTransactionPrivate;

typedef struct {
    PkTransactionPrivate *priv;
} PkTransaction;

#define PK_DBUS_INTERFACE_TRANSACTION "org.freedesktop.PackageKit.Transaction"
#define SIGNAL_FINISHED 0

const char *pk_exit_enum_to_string(PkExitEnum exit_enum);
extern uint32_t signals[];