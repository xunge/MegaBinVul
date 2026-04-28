#include <stdio.h>
#include <stdlib.h>

typedef long long INT64;
typedef unsigned char uchar;

class LibRaw {
public:
    FILE *ifp;
    int Sony_SRF_wb_list[10];
    float icWBC[10][4];
    float cam_mul[4];
    
    struct {
        float MaxAp4MaxFocal;
        float MaxAp4MinFocal;
        float MinFocal;
        float MaxFocal;
    } ilm;

    unsigned sget2(uchar *s);
    unsigned sget4(uchar *s);
    float sgetreal(int type, uchar *s);
    int tiff_sget(INT64 save, uchar *buf, unsigned len, INT64 *offset, unsigned *tag_id, unsigned *tag_type, INT64 *tag_dataoffset, unsigned *tag_datalen, int *tag_dataunitlen);
    void sony_decrypt(unsigned *data, unsigned len, int shift, unsigned key);
    void parseSonySRF(unsigned len);
};