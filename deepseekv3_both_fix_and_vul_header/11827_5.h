#include <stdint.h>

#define CLASS

extern int raw_height, raw_width, width, height;
extern int pana_bits(int);
extern void derror(void);
extern void checkCancel(void);
extern uint16_t *raw_image;
#define RAW(row,col) raw_image[(row)*raw_width+(col)]