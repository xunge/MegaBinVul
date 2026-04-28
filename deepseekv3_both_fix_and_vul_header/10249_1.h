#include <stdio.h>
#include <stdint.h>

struct SWF_GRADIENTRECORD {
    uint8_t Ratio;
    uint8_t Color[4];
};

struct SWF_FOCALGRADIENT {
    uint8_t SpreadMode;
    uint8_t InterpolationMode;
    uint8_t NumGradients;
    struct SWF_GRADIENTRECORD GradientRecords[15];
    uint16_t FocalPoint;
};

uint8_t readBits(FILE *f, int numBits);
uint16_t readUInt16(FILE *f);
void parseSWF_GRADIENTRECORD(FILE *f, struct SWF_GRADIENTRECORD *record, int level);