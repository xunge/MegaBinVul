#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#define GEMSAFE_MAX_OBJLEN 2048
#define GEMSAFE_READ_QUANTUM 256
#define GEMSAFE_PATH "3F00"
#define SC_SUCCESS 0
#define SC_ERROR_INTERNAL -1
#define SC_ERROR_INVALID_DATA -2
#define SC_FORMAT_LEN_SIZE_T "z"

typedef uint8_t u8;

struct sc_card {
    void *ctx;
};
typedef struct sc_card sc_card_t;

struct sc_path {
    char value[16];
};

struct sc_file {
    // minimal definition
};

struct {
    int ref;
    char *label;
} gemsafe_prkeys[10];

struct {
    char *label;
    size_t index;
    size_t count;
} gemsafe_cert[10];

static int gemsafe_cert_max = 10;

static void sc_format_path(const char *path, struct sc_path *out);
static int sc_select_file(sc_card_t *card, struct sc_path *path, struct sc_file **file);
static int sc_read_binary(sc_card_t *card, size_t offset, uint8_t *buf, size_t len, int flags);
static void sc_log(void *ctx, const char *fmt, ...);

#define MIN(a, b) ((a) < (b) ? (a) : (b))