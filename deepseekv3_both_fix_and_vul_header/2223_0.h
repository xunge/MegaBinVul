#include <stdlib.h>

static int xmlDictInitialized = 0;
static void *xmlDictMutex = NULL;

static void *xmlNewRMutex(void) {
    return malloc(sizeof(int));
}