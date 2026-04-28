#include <stdint.h>
#include <string.h>

struct iwgifrcontext {
    void *ctx;
};

struct lzwdeccontext {
    unsigned int ct_used;
    unsigned int last_code_added;
    unsigned int current_codesize;
    struct {
        uint16_t parent;
        unsigned int length;
        uint8_t firstchar;
        uint8_t lastchar;
    } ct[4096];
};

typedef uint8_t iw_byte;
typedef uint16_t iw_uint16;

static void iw_set_error(void *ctx, const char *msg) {
    // Empty implementation since we can't know the actual implementation
}