#include <string.h>

#define FALSE 0
#define TRUE 1
#define cmsMAXCHANNELS 16
#define cmsMAX_PATH 256

typedef int cmsBool;
#define CMSEXPORT

typedef unsigned short cmsUInt16Number;
typedef unsigned int cmsUInt32Number;

typedef struct {
    char Name[cmsMAX_PATH];
    cmsUInt16Number PCS[3];
    cmsUInt16Number DeviceColorant[cmsMAXCHANNELS];
} _cmsNAMEDCOLOR;

typedef struct {
    cmsUInt32Number nColors;
    cmsUInt32Number Allocated;
    cmsUInt32Number ColorantCount;
    _cmsNAMEDCOLOR* List;
} cmsNAMEDCOLORLIST;

static cmsBool GrowNamedColorList(cmsNAMEDCOLORLIST* NamedColorList);