#include <stdio.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char Bool;

typedef struct GF_ISOFile GF_ISOFile;

const char *gf_isom_sdp_get(GF_ISOFile *file, const char **sdp, u32 *size);
u32 gf_isom_get_track_count(GF_ISOFile *file);
u32 gf_isom_get_media_type(GF_ISOFile *file, u32 trackNumber);
const char *gf_isom_sdp_track_get(GF_ISOFile *file, u32 trackNumber, const char **sdp, u32 *size);
FILE *gf_fopen(const char *filename, const char *mode);
int gf_fclose(FILE *stream);

#define GF_ISOM_MEDIA_HINT 0