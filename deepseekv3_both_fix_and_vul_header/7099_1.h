#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define DIR_ENTRY_ADDR(DirStart, de) ((DirStart) + 2 + 12 * (de))
#define NUM_FORMATS 12
#define TAG_GPS_LAT_REF 0x0001
#define TAG_GPS_LONG_REF 0x0003
#define TAG_GPS_LAT 0x0002
#define TAG_GPS_LONG 0x0004
#define TAG_GPS_ALT_REF 0x0005
#define TAG_GPS_ALT 0x0006

extern unsigned Get16(const unsigned char* buf, bool moto);
extern unsigned Get32(const unsigned char* buf, bool moto);
extern void ErrNonfatal(const char* msg, unsigned a, unsigned b);
extern void GetLatLong(unsigned format, const unsigned char* valuePtr, unsigned componentSize, char* output);
extern double ConvertAnyFormat(const unsigned char* valuePtr, unsigned format);

struct ExifInfo {
    char GpsLat[2];
    char GpsLong[2];
    char GpsAlt[18];
};

class CExifParse {
public:
    bool m_MotorolaOrder;
    ExifInfo* m_ExifInfo;
    static const unsigned BytesPerFormat[NUM_FORMATS];
    void ProcessGpsInfo(const unsigned char* const DirStart, int ByteCountUnused, const unsigned char* const OffsetBase, unsigned ExifLength);
};