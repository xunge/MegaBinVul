#include <stdint.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options netdissect_options;

extern int request;
extern const char *tstr;
extern int unicodestr;

#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_LE_16BITS(p) ((uint16_t)((p)[0] | ((p)[1] << 8)))

void smb_fdata(netdissect_options *, const u_char *, const char *, const u_char *, int);
void print_browse(netdissect_options *, const u_char *, int, const u_char *, int);
void print_ipc(netdissect_options *, const u_char *, int, const u_char *, int);

#define min(a, b) ((a) < (b) ? (a) : (b))