#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct {
    /* dummy structure since we can't see actual definition */
    int dummy;
} netdissect_options;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(args)

#define IAC 255
#define TELCMD_FIRST 0
#define NTELOPTS 256
#define TELOPT_AUTHENTICATION 37
#define TELOPT_ENCRYPT 38
#define SE 240
#define DONT 254
#define DO 253
#define WONT 252
#define WILL 251
#define SB 250

extern const char *telcmds[];
extern const char *telopts[];
extern const char *authcmd[];
extern const char *authtype[];
extern const char *enccmd[];
extern const char *enctype[];
extern const char *cmds[];
extern const char *tstr;

#define STR_OR_ID(x, arr) ((x) < (sizeof(arr)/sizeof(arr[0])) ? arr[x] : "?"