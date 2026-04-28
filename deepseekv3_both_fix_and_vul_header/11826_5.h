#define CLASS 

#include <stdint.h>

extern int raw_height, raw_width, width, height;
extern int pana_bits(int);
extern void derror(void);
extern uint16_t *RAW(int, int);
extern void RAW_set(int, int, uint16_t);
#ifdef LIBRAW_LIBRARY_BUILD
extern void checkCancel(void);
#endif

#define RAW(row, col) (*RAW(row, col))