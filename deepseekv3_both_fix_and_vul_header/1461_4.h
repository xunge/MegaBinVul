#include <stdint.h>

typedef unsigned char uchar;

class LibRaw {
public:
    void parseSonySR2(uchar *cbuf_SR2, unsigned int SR2SubIFDOffset,
                     unsigned int SR2SubIFDLength, unsigned int dng_writer);
};

#define FORC4 for (unsigned c = 0; c < 4; c++)
#define FORC3 for (unsigned c = 0; c < 3; c++)
#define INT64 int64_t

enum { nonDNG };
enum { LIBRAW_WBI_Auto, LIBRAW_WBI_StudioTungsten };

struct {
    float MaxAp4MaxFocal;
    float MaxAp4MinFocal;
    float MaxFocal;
    float MinFocal;
} ilm;

struct {
    struct {
        float ccm[3][3];
        float linear_max[4];
    } color;
} imgdata;

extern unsigned short sget2(const uchar *s);
extern float sgetreal(int type, const uchar *s);
extern int tiff_sget(unsigned SR2SubIFDOffset, uchar *cbuf_SR2, unsigned SR2SubIFDLength, INT64 *tag_offset, unsigned *tag_id, unsigned *tag_type, INT64 *tag_dataoffset, unsigned *tag_datalen, int *tag_dataunitlen);
extern int GRBG_2_RGBG(int c);
extern int RGGB_2_RGBG(int c);

extern int cblack[4];
extern float cam_mul[4];
extern int black;
extern int icWBC[256][4];
extern int icWBCCTC[256][5];
extern int Sony_SR2_wb_list[7];
extern int Sony_SR2_wb_list1[14];