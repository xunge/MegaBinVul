#include <stddef.h>
#include <errno.h>
#include <sys/types.h>

typedef ssize_t MagickOffsetType;

typedef struct _PhotoshopProfile
{
  MagickOffsetType offset;
  MagickOffsetType length;
} PhotoshopProfile;

#define SSIZE_MAX ((ssize_t)((size_t)-1 >> 1))
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2