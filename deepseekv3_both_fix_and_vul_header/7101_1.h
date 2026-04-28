#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    bool ThumbnailAtEnd;
    unsigned int ThumbnailOffset;
    float CCDWidth;
    float FocalLength;
    int FocalLength35mmEquiv;
} ExifInfo_t;

class CExifParse {
private:
    ExifInfo_t* m_ExifInfo;
    bool m_MotorolaOrder;
    unsigned long m_LargestExifOffset;
    float m_FocalPlaneXRes;
    unsigned int m_ExifImageWidth;
    float m_FocalPlaneUnits;

    unsigned short Get16(const void* pos, bool motorolaOrder);
    unsigned long Get32(const void* pos, bool motorolaOrder);
    void ProcessDir(const unsigned char* dirStart, const unsigned char* offsetBase, unsigned length, unsigned nesting);
    void ErrNonfatal(const char* msg, unsigned arg1, unsigned arg2);
public:
    bool Process(const unsigned char* const ExifSection, const unsigned short length, ExifInfo_t* info);
};