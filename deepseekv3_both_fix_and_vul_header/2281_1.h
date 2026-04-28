#include <stdlib.h>

#define NUM_BUFFER 10
#define BUFFER_SIZE 1024

struct textBuffer {
    char *buffer;
    unsigned size;
};

static struct textBuffer textBufferArray[NUM_BUFFER];
static unsigned textBufferIndex;
static char textBuffer[BUFFER_SIZE];
static unsigned tbNext;