#include <stdlib.h>
#include <math.h>

#define TBLN 65535

struct LibRaw {
    void exp_bef(float shift, float smooth);
};

struct imgdata_t {
    unsigned short (*image)[4];
};

struct imgdata_t imgdata;

struct {
    int height;
    int width;
} S;

struct {
    unsigned short data_maximum;
    unsigned short maximum;
} C;

typedef unsigned short ushort;