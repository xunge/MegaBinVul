#include <stdio.h>

struct SWF_GRADIENTRECORD {
    // Define the fields of SWF_GRADIENTRECORD here
    // (content not provided in original code)
};

struct SWF_GRADIENT {
    int SpreadMode;
    int InterpolationMode;
    int NumGradients;
    struct SWF_GRADIENTRECORD GradientRecords[16];
};

int readBits(FILE *f, int n);
void parseSWF_GRADIENTRECORD(FILE *f, struct SWF_GRADIENTRECORD *record, int level);