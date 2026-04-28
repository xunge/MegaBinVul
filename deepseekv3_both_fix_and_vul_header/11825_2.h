#include <stdio.h>
#include <string.h>

#define CLASS
#define FORC(cnt) for (c=0; c < cnt; c++)
#define FORC4 FORC(4)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define fMAX(a,b) ((a) > (b) ? (a) : (b))

extern FILE *ifp;
extern int raw_height, raw_width;
extern int height, width;
extern int fuji_layout, fuji_width;
extern int filters;
extern int xtrans_abs[6][6];
extern int cam_mul[4];
extern int order;
extern char model[64];

#ifdef LIBRAW_LIBRARY_BUILD
struct libraw_data_t {
    struct {
        struct {
            float FujiExpoMidPointShift;
        } fuji;
    } makernotes;
    struct {
        float WB_Coeffs[8][4];
        float WBCT_Coeffs[256][5];
    } color;
};
extern struct libraw_data_t imgdata;

#define LIBRAW_WBI_Auto 0
#define LIBRAW_WBI_Custom1 1
#define LIBRAW_WBI_FineWeather 2
#define LIBRAW_WBI_Shade 3
#define LIBRAW_WBI_FL_D 4
#define LIBRAW_WBI_FL_N 5
#define LIBRAW_WBI_FL_WW 6
#define LIBRAW_WBI_FL_L 7
#define LIBRAW_WBI_Tungsten 8
#define LIBRAW_WBI_Flash 9

extern int nFuji_wb_list2;
extern int Fuji_wb_list2[];
extern struct {
    struct {
        unsigned posRAFData;
        unsigned lenRAFData;
    } unpacker_data;
} libraw_internal_data;
#endif

unsigned get4();
unsigned short get2();