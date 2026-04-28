#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define AVC1_TRACK 1
#define S_AMR_TRACK 2
#define EVRC_TRACK 3
#define QCELP_TRACK 4
#define S263_TRACK 5
#define AUDIO_TRACK 6

typedef struct {
    uint8_t contains_esds;
    uint8_t ObjectTypeIndication;
    uint8_t descriptor_object_typeID;
    uint8_t profile;
    uint8_t level;
    uint32_t track_codec;
    uint16_t amr_modes;
    char* encoder_name;
    uint8_t channels;
    uint8_t section5_length;
} TrackInfo;

typedef struct {
    uint8_t contains_iods;
} MovieInfo;

typedef struct {
    uint8_t audio_profile;
} IODSInfo;

extern MovieInfo movie_info;
extern IODSInfo iods_info;

void APar_ShowMPEG4VisualProfileInfo(TrackInfo *track_info);
void APar_ShowMPEG4AACProfileInfo(TrackInfo *track_info);
void mem_append(const char *src, char *dest);