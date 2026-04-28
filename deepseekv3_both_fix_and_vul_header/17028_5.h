#include <assert.h>
#include <stdint.h>
#include <stddef.h>

typedef long tmsize_t;
typedef uint16_t uint16;

struct tiff_directory {
    int td_planarconfig;
    int td_samplesperpixel;
    tmsize_t td_imagewidth;
    tmsize_t td_rowsperstrip;
    int td_bitspersample;
};

struct z_stream_s {
    char* msg;
};

struct pixarlog_state {
    tmsize_t stride;
    tmsize_t tbuf_size;
    uint16_t* tbuf;
    int user_datafmt;
    struct z_stream_s stream;
    int state;
};

struct tiff {
    struct tiff_directory tif_dir;
    void (*tif_postdecode)(struct tiff*);
    void* tif_clientdata;
};

typedef struct tiff TIFF;
typedef struct tiff_directory TIFFDirectory;
typedef struct pixarlog_state PixarLogState;

#define PLANARCONFIG_CONTIG 1
#define PIXARLOGDATAFMT_UNKNOWN 0
#define PLSTATE_INIT 1
#define Z_OK 0

extern uint16_t* _TIFFmalloc(tmsize_t size);
extern tmsize_t multiply_ms(tmsize_t a, tmsize_t b);
extern tmsize_t add_ms(tmsize_t a, tmsize_t b);
extern void _TIFFNoPostDecode(TIFF* tif);
extern PixarLogState* DecoderState(TIFF* tif);
extern int PixarLogGuessDataFmt(TIFFDirectory* td);
extern void TIFFErrorExt(void* clientdata, const char* module, const char* fmt, ...);
extern int inflateInit(struct z_stream_s* strm);