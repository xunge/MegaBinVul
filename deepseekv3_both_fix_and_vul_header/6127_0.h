#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <algorithm>

typedef struct {
    int track_atom;
} Trackage;

typedef struct {
    bool track_enabled;
    uint64_t creation_time;
    uint64_t modified_time;
    uint64_t duration;
    char unpacked_lang[4];
    uint32_t track_type;
    int type_of_track;
    char track_hdlr_name[256];
    uint32_t track_codec;
    uint16_t video_width;
    uint16_t video_height;
    uint32_t macroblocks;
    bool contains_esds;
    uint8_t avc_version;
    uint8_t profile;
    uint8_t level;
    uint32_t avg_bitrate;
    uint16_t channels;
    uint64_t sample_aggregate;
    uint32_t protected_codec;
    char encoder_name[256];
} TrackInfo;

typedef struct {
    uint64_t AtomicStart;
    uint64_t AtomicLength;
    char AtomicName[5];
} Atom;

extern Atom parsedAtoms[];
extern uint8_t APar_read8(FILE *isofile, uint64_t offset);
extern uint16_t APar_read16(char *buffer, FILE *isofile, uint64_t offset);
extern uint32_t APar_read32(char *buffer, FILE *isofile, uint64_t offset);
extern uint64_t APar_read64(char *buffer, FILE *isofile, uint64_t offset);
extern void APar_readX(char *buffer, FILE *isofile, uint64_t offset, uint64_t length);
extern void APar_TrackLevelInfo(Trackage *track, const char *atom_name);
extern void APar_UnpackLanguage(char *unpacked_lang, uint16_t packed_language);
extern uint64_t APar_FindValueInAtom(char *buffer, FILE *isofile, int atom_num, uint64_t offset, uint32_t value);
extern void APar_Extract_d263_Info(char *buffer, FILE *isofile, int atom_num, TrackInfo *track_info);
extern void APar_Extract_esds_Info(char *buffer, FILE *isofile, int atom_num, TrackInfo *track_info);
extern void APar_Extract_AMR_Info(char *buffer, FILE *isofile, int atom_num, TrackInfo *track_info);
extern void APar_Extract_devc_Info(FILE *isofile, int atom_num, TrackInfo *track_info);
extern uint64_t calcuate_sample_size(char *buffer, FILE *isofile, int atom_num);

#define AUDIO_TRACK 1
#define VIDEO_TRACK 2
#define OTHER_TRACK 4
#define DRM_PROTECTED_TRACK 8