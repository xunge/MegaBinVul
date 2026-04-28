#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void* AFfilehandle;
typedef long long AFframecount;
#define AF_DEFAULT_TRACK 0

int afGetVirtualFrameSize(AFfilehandle, int, int);
AFframecount afGetFrameCount(AFfilehandle, int);
AFframecount afReadFrames(AFfilehandle, int, void*, AFframecount);
AFframecount afWriteFrames(AFfilehandle, int, void*, AFframecount);