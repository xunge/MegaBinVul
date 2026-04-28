#include <stdint.h>
#include <stddef.h>

#define MAX_WIN_BUF_LEN 4096
#define MAX_WCP_BUF_LEN 65536

typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct {
    guint8 *buffer;
    guint16 initialized;
} wcp_window_t;