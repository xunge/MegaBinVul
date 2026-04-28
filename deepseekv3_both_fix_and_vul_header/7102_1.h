#include <stdio.h>
#include <string.h>

class CExifParse {
public:
    void ProcessGpsInfo(const unsigned char* const DirStart,
                        int ByteCountUnused,
                        const unsigned char* const OffsetBase,
                        unsigned ExifLength);
private:
    bool m_MotorolaOrder;
};

#define NUM_FORMATS 12
#define DIR_ENTRY_ADDR(start, entry) ((start) + 2 + 12 * (entry))
#define TAG_GPS_LAT_REF 0x0001
#define TAG_GPS_LONG_REF 0x0003
#define TAG_GPS_LAT 0x0002
#define TAG_GPS_LONG 0x0004
#define TAG_GPS_ALT_REF 0x0005
#define TAG_GPS_ALT 0x0006

extern unsigned BytesPerFormat[NUM_FORMATS];

struct ExifInfo {
    char GpsLat[2];
    char GpsLong[2];
    char GpsAlt[32];
};

extern ExifInfo* m_ExifInfo;

unsigned Get16(const unsigned char* buf, bool motorolaOrder);
unsigned Get32(const unsigned char* buf, bool motorolaOrder);
void ErrNonfatal(const char* msg, ...);
void GetLatLong(unsigned format, const unsigned char* valuePtr, unsigned componentSize, char* output);
double ConvertAnyFormat(const unsigned char* valuePtr, unsigned format);