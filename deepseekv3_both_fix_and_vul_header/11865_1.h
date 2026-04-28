#include <stdlib.h>

#define CLASS

unsigned short (*image)[4];
int width;
int height;
void read_shorts(unsigned short *buf, int len);
void merror(void *ptr, const char *where);
void checkCancel();