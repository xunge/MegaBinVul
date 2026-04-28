#include <stdbool.h>
#include <stddef.h>

typedef unsigned char jboolean;
typedef void* JNIEnv;
typedef void* jobject;

#define ALOGV(...)
#define JNI_FALSE 0
#define JNI_TRUE 1

typedef enum {
    BT_STATUS_SUCCESS,
    BT_STATUS_DONE
} bt_status_t;

typedef struct {
    int (*enable)();
} BluetoothInterface;

static BluetoothInterface* sBluetoothInterface = NULL;