#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CLASS
static size_t meta_offset = 0;
static size_t meta_length = 0;
static char *meta_data = NULL;
static FILE *ifp = NULL;
static const char *ifname = "";

static inline unsigned get4() { return 0; }
static inline void getbits(int x) {}
static inline void merror(void *p, const char *s) {}
#define _(x) x
static inline void foveon_huff(unsigned short *x) {}
static inline unsigned ljpeg_diff(unsigned short *x) { return 0; }

typedef unsigned short ushort;
typedef int64_t INT64;