#include <string.h>
#include <stdio.h>
#include <sys/types.h>

typedef int tcpr_dir_t;
#define TCPR_DIR_S2C 0
#define TCPR_DIR_C2S 1

#define MAC_FORMAT "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_STR(mac) (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]

extern char *safe_strdup(const char *);
extern void safe_free(void *);
extern void mac2hex(const char *, unsigned char *, int);
extern void dbg(int level, const char *fmt, ...);
extern void dbgx(int level, const char *fmt, ...);