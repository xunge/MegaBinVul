#include <stdio.h>

#define CLASS

extern FILE *ifp;
extern int order;
extern int raw_height;
extern int raw_width;

int get2(void);
int get4(void);
int parse_ciff(int offset, int length, int depth);
int parse_tiff(int offset);
void apply_tiff(void);

#ifdef LIBRAW_LIBRARY_BUILD
struct {
    struct {
        struct {
            int CameraMount;
            int LensMount;
        } makernotes;
    } lens;
} imgdata;
#endif