#include <stdio.h>
#include <stdint.h>

typedef uint8_t u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    // Dummy structure since we can't include the real one
    int dummy;
} netdissect_options;

#define ND_PRINT(args) printf args

void isakmp_print(netdissect_options *, const u_char *, u_int, const u_char *);
int esp_print(netdissect_options *, const u_char *, u_int, const u_char *, int *, int *);
void ip_print_inner(netdissect_options *, const u_char *, u_int, int, const u_char *);