#include <stddef.h>

#define SF_MAX_CHANNELS   128
#define SFE_INTERNAL      1

#define SF_ENDIAN_BIG     0x1000
#define SF_ENDIAN_LITTLE  0x2000

#define DOUBLE_CAN_RW_BE  0x10
#define DOUBLE_CAN_RW_LE  0x20
#define DOUBLE_BROKEN_BE  0x40
#define DOUBLE_BROKEN_LE  0x80

#define SF_FALSE         0
#define SF_TRUE          1

#define SFM_READ         0
#define SFM_WRITE        1
#define SFM_RDWR         2

typedef struct {
    int mode;
    long filelength;
    long dataoffset;
    long dataend;
} SF_FILE;

typedef struct {
    int channels;
    long frames;
} SF_INFO;

typedef struct {
    SF_FILE file;
    SF_INFO sf;
    int endian;
    int blockwidth;
    int data_endswap;
    long datalength;
    long filelength;
    long dataoffset;
    long dataend;
    void (*read_short)(void);
    void (*read_int)(void);
    void (*read_float)(void);
    void (*read_double)(void);
    void (*write_short)(void);
    void (*write_int)(void);
    void (*write_float)(void);
    void (*write_double)(void);
} SF_PRIVATE;

void psf_log_printf(SF_PRIVATE *psf, const char *format, ...);
int double64_get_capability(SF_PRIVATE *psf);

void host_read_d2s(void);
void host_read_d2i(void);
void host_read_d2f(void);
void host_read_d(void);
void replace_read_d2s(void);
void replace_read_d2i(void);
void replace_read_d2f(void);
void replace_read_d(void);
void host_write_s2d(void);
void host_write_i2d(void);
void host_write_f2d(void);
void host_write_d(void);
void replace_write_s2d(void);
void replace_write_i2d(void);
void replace_write_f2d(void);
void replace_write_d(void);