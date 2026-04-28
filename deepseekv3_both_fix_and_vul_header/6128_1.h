#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct {
    double seconds;
    double simple_bitrate_calc;
    uint64_t creation_time;
    uint64_t modified_time;
    bool contains_iods;
} MovieInfo;

typedef struct {
    uint32_t track_type;
    uint32_t track_codec;
    uint32_t protected_codec;
    uint32_t type_of_track;
    char track_hdlr_name[256];
    char unpacked_lang[4];
    char encoder_name[256];
    uint64_t sample_aggregate;
    uint64_t creation_time;
    uint64_t modified_time;
    bool contains_esds;
} TrackInfo;

typedef struct {
    uint32_t track_num;
    uint32_t total_tracks;
} Trackage;

typedef enum {
    VERSIONED_ATOM
} AtomType;

typedef struct {
    // Define necessary fields for AtomicInfo
} AtomicInfo;

#define SHOW_DATE_INFO 1
#define SHOW_TRACK_INFO 2
#define DRM_PROTECTED_TRACK 4
#define VIDEO_TRACK 8
#define AUDIO_TRACK 16

extern MovieInfo movie_info;

AtomicInfo* APar_FindAtom(const char* path, bool exact_match, AtomType type, uint32_t flags);
void APar_ExtractMovieDetails(char* buffer, FILE* file, AtomicInfo* atom);
char* secsTOtime(double seconds);
char* APar_extract_UTC(uint64_t time);
void APar_Extract_iods_Info(FILE* file, AtomicInfo* atom);
void APar_TrackLevelInfo(Trackage* track, uint32_t* track_num);
void APar_ExtractTrackDetails(char* buffer, FILE* file, Trackage* track, TrackInfo* info);
uint16_t purge_extraneous_characters(char* str);
char* uint32tochar4(uint32_t num, char* buffer);
void APar_Print_TrackDetails(TrackInfo* info);