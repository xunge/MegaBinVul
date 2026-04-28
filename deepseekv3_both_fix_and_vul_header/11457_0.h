#include <stdlib.h>

typedef struct TABLE {
    char** Data;
    int nSamples;
    int nPatches;
} TABLE;

typedef struct cmsIT8 cmsIT8;
typedef unsigned int cmsUInt32Number;

static TABLE* GetTable(cmsIT8* it8);
static char* cmsIT8GetProperty(cmsIT8* it8, const char* prop);
static void* AllocChunk(cmsIT8* it8, cmsUInt32Number size);
static void SynError(cmsIT8* it8, const char* msg);