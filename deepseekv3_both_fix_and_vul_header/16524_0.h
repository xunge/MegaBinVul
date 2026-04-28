#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MYSOFA_EXPORT
#define MYSOFA_INVALID_ATTRIBUTES 1
#define MYSOFA_INVALID_DIMENSIONS 2
#define MYSOFA_INVALID_DIMENSION_LIST 3
#define MYSOFA_INVALID_FORMAT 4
#define MYSOFA_INVALID_COORDINATE_TYPE 5
#define MYSOFA_ONLY_EMITTER_WITH_ECI_SUPPORTED 6
#define MYSOFA_ONLY_DELAYS_WITH_IR_OR_MR_SUPPORTED 7
#define MYSOFA_ONLY_THE_SAME_SAMPLING_RATE_SUPPORTED 8
#define MYSOFA_RECEIVERS_WITH_RCI_SUPPORTED 9
#define MYSOFA_RECEIVERS_WITH_CARTESIAN_SUPPORTED 10
#define MYSOFA_INVALID_RECEIVER_POSITIONS 11
#define MYSOFA_ONLY_SOURCES_WITH_MC_SUPPORTED 12
#define MYSOFA_OK 0

struct MYSOFA_HRTF {
    int C;
    int I;
    int E;
    int R;
    int M;
    struct {
        char **attributes;
        double *values;
    } ListenerView, ListenerUp, ListenerPosition, EmitterPosition, DataDelay, DataSamplingRate, ReceiverPosition, SourcePosition;
    char **attributes;
};

int verifyAttribute(char **attributes, const char *name, const char *value);
int compareValues(struct { double *values; } *view, double *array, int size, int m);
int fequals(double a, double b);
const char *mysofa_getAttribute(char **attributes, const char *name);
void mylog(const char *format, ...);

double array100[] = {1, 0, 0};
double array001[] = {0, 0, 1};
double array000[] = {0, 0, 0};
double array0901[] = {0, 90, 1};