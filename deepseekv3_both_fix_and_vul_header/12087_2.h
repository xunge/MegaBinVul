#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int uInt;
typedef unsigned long uLong;
typedef void* voidpf;
typedef long long ZPOS64_T;
typedef unsigned char Bytef;

#define ZEXPORT
#define ZIP_OK 0
#define ZIP_PARAMERROR -1
#define ZIP_INTERNALERROR -2
#define ZIP_ERRNO -3
#define Z_DEFLATED 8
#define Z_BZIP2ED 12
#define Z_BINARY 0
#define Z_OK 0
#define BZ_OK 0
#define Z_BUFSIZE 16384
#define RAND_HEAD_LEN 12
#define SIZECENTRALHEADER 46
#define CENTRALHEADERMAGIC 0x02014b50
#define HAVE_BZIP2

typedef struct tm tmz_time;

typedef struct {
    tmz_time tmz_date;
    uLong dosDate;
    uLong internal_fa;
    uLong external_fa;
} zip_fileinfo;

typedef void* (*alloc_func)(void*, uInt, uInt);
typedef void (*free_func)(void*, void*);

typedef struct {
    alloc_func zalloc;
    free_func zfree;
    voidpf opaque;
    int data_type;
    uLong adler;
    uLong reserved;
    uInt avail_in;
    uInt avail_out;
    char* next_out;
    uLong total_in;
    uLong total_out;
} z_stream;

typedef struct {
    unsigned int avail_in;
    unsigned int avail_out;
    char* next_out;
    unsigned long total_in_hi32;
    unsigned long total_in_lo32;
    unsigned long total_out_hi32;
    unsigned long total_out_lo32;
    void* bzalloc;
    void* bzfree;
    void* opaque;
} bz_stream;

typedef struct {
    uLong crc32;
    uLong dosDate;
    uLong flag;
    int method;
    int encrypt;
    int stream_initialised;
    int pos_in_buffered_data;
    int raw;
    ZPOS64_T pos_local_header;
    uLong size_centralheader;
    uLong size_centralExtra;
    uLong size_centralExtraFree;
    char* central_header;
    ZPOS64_T totalCompressedData;
    ZPOS64_T totalUncompressedData;
    ZPOS64_T pos_zip64extrainfo;
    int zip64;
#ifdef HAVE_BZIP2
    bz_stream bstream;
#endif
    z_stream stream;
    char* buffered_data;
    uLong crypt_header_size;
    uLong* pcrc_32_tab;
    int keys[3];
} zip64_fileinfo;

typedef voidpf (*open64_file_func)(voidpf, const void*, int);
typedef uLong (*read_file_func)(voidpf, voidpf, uLong);
typedef uLong (*write_file_func)(voidpf, voidpf, uLong);
typedef ZPOS64_T (*tell64_file_func)(voidpf);
typedef long (*seek64_file_func)(voidpf, ZPOS64_T, int);
typedef int (*close_file_func)(voidpf);
typedef int (*testerror_file_func)(voidpf);

typedef struct {
    open64_file_func zopen64_file;
    read_file_func zread_file;
    write_file_func zwrite_file;
    tell64_file_func ztell64_file;
    seek64_file_func zseek64_file;
    close_file_func zclose_file;
    testerror_file_func zerror_file;
    voidpf opaque;
} zlib_filefunc64_def;

typedef struct {
    voidpf filestream;
    int in_opened_file_inzip;
    zip64_fileinfo ci;
    ZPOS64_T add_position_when_writing_offset;
    zlib_filefunc64_def z_filefunc;
} zip64_internal;

typedef void* zipFile;

extern uLong* get_crc_table(void);
extern unsigned int crypthead(const char*, unsigned char*, unsigned int, int*, uLong*, uLong);
extern int deflateInit2(z_stream*, int, int, int, int, int);
extern int BZ2_bzCompressInit(bz_stream*, int, int, int);
extern int zipCloseFileInZip(zipFile);
extern int Write_LocalFileHeader(zip64_internal*, const char*, uInt, const void*);
extern void zip64local_putValue_inmemory(char*, uLong, int);
extern ZPOS64_T ZTELL64(zlib_filefunc64_def, voidpf);
extern uLong ZWRITE64(zlib_filefunc64_def, voidpf, const void*, uLong);
extern void* ALLOC(uInt);
extern uLong zip64local_TmzDateToDosDate(const tmz_time*);