#include <stdint.h>

typedef struct {
    uint8_t ActionCode;
} SWF_ACTIONRECORD;

typedef struct {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
} SWF_ACTION;

#define SWFACTION_LOGICALNOT 1
#define SWFACTION_PUSHDUP 2
#define SWFACTION_IF 3