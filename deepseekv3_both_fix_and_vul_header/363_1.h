#include <stddef.h>

typedef unsigned short Quantum;
typedef size_t PixelChannel;

typedef struct _ChannelMap
{
  size_t offset;
  int traits;
} ChannelMap;

typedef struct _Image
{
  ChannelMap *channel_map;
} Image;

#define UndefinedPixelTrait 0
#define magick_restrict restrict