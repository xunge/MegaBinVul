#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DHO_PAD 0
#define DHO_END 255
#define DHO_OPTIONSOVERLOADED 52

struct dhcp_message {
    uint8_t options[312];
    uint8_t bootfile[128];
    uint8_t servername[64];
};

static uint8_t *opt_buffer = NULL;

#ifdef DEBUG_MEMORY
static void free_option_buffer(void);
#endif

static int valid_length(uint8_t opt, int bl, int *type);
static void *xmalloc(size_t size);