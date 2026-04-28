#include <stdlib.h>
#include <string.h>

typedef struct SF_PRIVATE SF_PRIVATE;
typedef struct AIFF_CAF_CHANNEL_MAP AIFF_CAF_CHANNEL_MAP;

struct AIFF_CAF_CHANNEL_MAP {
    const char *name;
    const int *channel_map;
};

struct SF_PRIVATE {
    struct {
        unsigned int channels;
    } sf;
    int *channel_map;
};

extern unsigned int psf_binheader_readf(SF_PRIVATE *psf, const char *format, ...);
extern void psf_log_printf(SF_PRIVATE *psf, const char *format, ...);
extern const AIFF_CAF_CHANNEL_MAP *aiff_caf_of_channel_layout_tag(int layout_tag);

#define SFE_MALLOC_FAILED 1