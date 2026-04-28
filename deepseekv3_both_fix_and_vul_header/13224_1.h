#include <time.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define BUFSIZE 256
#define GET_BE_U_4(cp) ((time_t)ntohl(*(const uint32_t *)(cp)))
#define ND_PRINT(fmt, ...)
#define ND_TCHECK_LEN(cp, len) 
#define nd_print_invalid(ndo)

typedef struct netdissect_options netdissect_options;
typedef unsigned char u_char;