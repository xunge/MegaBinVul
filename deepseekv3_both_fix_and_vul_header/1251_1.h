#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct RCore RCore;
typedef uint32_t ut32;

struct JavaCmd {
    const char *name;
    size_t name_len;
    int (*handler)(RCore *, const char *);
};

#define END_CMDS 0
#define IFDBG if(0)
#define JAVA_CMDS ((struct JavaCmd[]){0})

int r_cmd_java_handle_help(RCore *core, const char *input);
int r_cons_printf(const char *format, ...);