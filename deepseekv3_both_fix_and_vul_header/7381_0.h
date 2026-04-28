#include <assert.h>
#include <stddef.h>

#define COMPRESSION_JBIG 0
#define TIFF_NOBITREV 0
#define TIFF_MAPPED 0
#define TIFF_BUFFERMMAP 0
#define TIFF_MYBUFFER 0

typedef struct {
    int tif_flags;
    void* tif_rawdata;
    size_t tif_rawdatasize;
    void (*tif_setupdecode)(void);
    void (*tif_decodestrip)(void);
    void (*tif_setupencode)(void);
    void (*tif_encodestrip)(void);
} TIFF;

void JBIGSetupDecode(void);
void JBIGDecode(void);
void JBIGSetupEncode(void);
void JBIGEncode(void);