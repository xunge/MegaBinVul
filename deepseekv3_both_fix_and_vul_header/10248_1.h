#include <stdio.h>
#include <stdint.h>

struct SWF_MORPHGRADIENTRECORD {
    uint8_t StartRatio;
    uint8_t EndRatio;
    uint8_t StartColor[4];
    uint8_t EndColor[4];
};

struct SWF_MORPHGRADIENT {
    uint8_t NumGradients;
    struct SWF_MORPHGRADIENTRECORD GradientRecords[8];
};

uint8_t readUInt8(FILE *f);
void parseSWF_MORPHGRADIENTRECORD(FILE *f, struct SWF_MORPHGRADIENTRECORD *record);