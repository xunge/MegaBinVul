#include <float.h>
#include <math.h>

#define MYSOFA_EXPORT

struct MYSOFA_HRTF {
    struct {
        char **attributes;
        float *values;
        int elements;
    } SourcePosition;
    struct {
        float *values;
        int elements;
    } DataIR;
    int N;
    int R;
    int C;
};

int verifyAttribute(char **attributes, const char *type, const char *value);
void mysofa_c2s(float *c);
float loudness(float *values, int size);
int fequals(float a, float b);
void scaleArray(float *values, int size, float factor);