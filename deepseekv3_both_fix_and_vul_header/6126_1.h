#include <stdio.h>
#include <stdlib.h>
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
    uint32_t track_num;
    uint32_t total_tracks;
} Trackage;

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
    char atom_name[32];
    bool versioned;
    uint32_t type;
    uint32_t offset;
} AtomicInfo;

#define VERSIONED_ATOM 1
#define SHOW_DATE_INFO 1
#define SHOW_TRACK_INFO 2
#define DRM_PROTECTED_TRACK 1
#define VIDEO_TRACK 2
#define AUDIO_TRACK 4

extern MovieInfo movie_info;
extern char* APar_extract_UTC(uint64_t time);
extern AtomicInfo* APar_FindAtom(const char* path, bool exact_match, uint32_t type, uint32_t offset);
extern void APar_ExtractMovieDetails(char* buffer, FILE* file, AtomicInfo* atom);
extern void APar_Extract_iods_Info(FILE* file, AtomicInfo* atom);
extern void APar_TrackLevelInfo(Trackage* track, uint32_t* track_num);
extern void APar_ExtractTrackDetails(char* buffer, FILE* file, Trackage* track, TrackInfo* track_info);
extern void APar_Print_TrackDetails(TrackInfo* track_info);
extern char* uint32tochar4(uint32_t value, char* buffer);
extern uint16_t purge_extraneous_characters(char* str);
extern char* secsTOtime(double seconds);