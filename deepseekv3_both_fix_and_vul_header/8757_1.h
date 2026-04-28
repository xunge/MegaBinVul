#include <stddef.h>

typedef struct XAnyClass {
    int class;
    int length;
} XAnyClass;

typedef struct XKeyInfo {
    XAnyClass any;
} XKeyInfo;

typedef struct XButtonInfo {
    XAnyClass any;
} XButtonInfo;

typedef struct XAxisInfo {
    int dummy;
} XAxisInfo;

typedef struct XValuatorInfo {
    XAnyClass any;
    int num_axes;
    XAxisInfo* axes;
} XValuatorInfo;

typedef XAnyClass* xAnyClassPtr;
typedef XValuatorInfo* xValuatorInfoPtr;

#define KeyClass 0
#define ButtonClass 1
#define ValuatorClass 2

static size_t pad_to_xid(size_t size) {
    return size;
}