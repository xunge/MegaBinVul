#include <stddef.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define FAIL 0
#define OK 1

typedef struct {
    int overstrike;
    int cmdfirstc;
    int cmdindent;
    char *cmdbuff;
    int cmdlen;
    int cmdpos;
    int cmdspos;
} CmdLineInfo;

static CmdLineInfo ccline;
static int exmode_active;

void alloc_cmdbuff(int size);
void sb_text_start_cmdline(void);
void vim_memset(void *s, int c, size_t n);