#include <stdint.h>

#define CLASS

extern int colors;
extern int thumb_misc;
extern int height;
extern int width;
extern uint16_t *image;
extern int maximum;

void read_shorts(uint16_t *pixel, int count);