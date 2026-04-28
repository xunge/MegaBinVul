#include <stdlib.h>
#include <string.h>

typedef struct {
    char *addr;
    char *ifname;
} virPCIVirtualFunction;

typedef struct {
    virPCIVirtualFunction *functions;
    size_t nfunctions;
} virPCIVirtualFunctionList;

#define g_free free