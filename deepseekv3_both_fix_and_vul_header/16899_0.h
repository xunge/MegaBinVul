#include <stdint.h>

#define ERR_FAIL -1

typedef struct {
    uint32_t firstchunk;
    uint32_t samplesperchunk;
} MapEntry;

typedef struct {
    uint32_t offset;
    uint32_t len;
} SampleInfo;

typedef struct {
    uint32_t nsamples;
    uint32_t nsclices;
    MapEntry *map;
    SampleInfo *info;
} FrameConfig;

typedef struct {
    FrameConfig frame;
} MP4Config;

extern MP4Config mp4config;
extern uint32_t u32in(void);
extern void freeMem(void *ptr);