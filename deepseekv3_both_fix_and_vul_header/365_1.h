#include <stddef.h>

#define magick_restrict

typedef unsigned short Quantum;
typedef size_t PixelChannel;

typedef struct _ChannelMap {
    int traits;
    size_t offset;
} ChannelMap;

typedef struct _Image {
    ChannelMap *channel_map;
} Image;

enum {
    UndefinedPixelTrait
};