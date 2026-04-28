#include <stdint.h>
#include <stdio.h>

typedef int64_t sf_count_t;

#define SF_FALSE 0
#define SF_TRUE 1
#define SF_ENDIAN_LITTLE 0
#define SFE_UNIMPLEMENTED (-1)
#define SFE_INTERNAL (-2)
#define SF_FORMAT_WAV 0
#define SF_FORMAT_WAVEX 1
#define SF_STR_LOCATE_START 0
#define SF_PEAK_START 0
#define SF_LOOP_FORWARD 0
#define SF_LOOP_BACKWARD 1
#define SF_LOOP_ALTERNATING 2

#define RIFF_MARKER 0
#define RIFX_MARKER 0
#define WAVE_MARKER 0
#define fmt_MARKER 0
#define cue_MARKER 0
#define smpl_MARKER 0
#define PAD_MARKER 0
#define data_MARKER 0

#define BHWm(x) (x)
#define BHW4(x) (x)
#define BHW8(x) (x)
#define BHWz(x) (x)

#define SF_CONTAINER(x) (x)

typedef struct {
    int format;
    int seekable;
    int channels;
    sf_count_t frames;
    double samplerate;
} SF_INFO;

typedef struct {
    int flags;
} SF_STRINGS;

typedef struct {
    int peak_loc;
} SF_PEAK_INFO;

typedef struct {
    int cue_count;
    struct {
        uint32_t indx;
        uint32_t position;
        uint32_t fcc_chunk;
        uint32_t chunk_start;
        uint32_t block_start;
        uint32_t sample_offset;
    } *cue_points;
} SF_CUES;

typedef struct {
    int loop_count;
    int basenote;
    double detune;
    struct {
        int mode;
        sf_count_t start;
        sf_count_t end;
        int count;
    } *loops;
} SF_INSTRUMENT;

typedef struct {
    size_t used;
} SF_WCHUNKS;

typedef struct {
    char *ptr;
    size_t indx;
} SF_HEADER;

typedef struct {
    sf_count_t filelength;
    sf_count_t datalength;
    sf_count_t dataoffset;
    sf_count_t dataend;
    int bytewidth;
    int endian;
    SF_INFO sf;
    SF_HEADER header;
    SF_STRINGS strings;
    SF_PEAK_INFO *peak_info;
    void *broadcast_16k;
    void *cart_16k;
    SF_CUES *cues;
    SF_INSTRUMENT *instrument;
    SF_WCHUNKS wchunks;
    int error;
} SF_PRIVATE;

extern sf_count_t psf_ftell(SF_PRIVATE *);
extern sf_count_t psf_get_filelen(SF_PRIVATE *);
extern int psf_fseek(SF_PRIVATE *, sf_count_t, int);
extern int psf_fwrite(const void *, sf_count_t, sf_count_t, SF_PRIVATE *);
extern void psf_log_printf(SF_PRIVATE *, const char *);
extern int psf_binheader_writef(SF_PRIVATE *, const char *, ...);
extern int wav_write_fmt_chunk(SF_PRIVATE *);
extern int wavex_write_fmt_chunk(SF_PRIVATE *);
extern void wavlike_write_strings(SF_PRIVATE *, int);
extern void wavlike_write_peak_chunk(SF_PRIVATE *);
extern void wavlike_write_bext_chunk(SF_PRIVATE *);
extern void wavlike_write_cart_chunk(SF_PRIVATE *);
extern void wavlike_write_custom_chunks(SF_PRIVATE *);