#include <stddef.h>

typedef struct HTTPSessionStats HTTPSessionStats;
typedef struct {
    HTTPSessionStats* httpSessionStats;
} ResetControlMessages;
typedef struct {
    HTTPSessionStats* httpSessionStats;
} ResetHeaders;

extern HTTPSessionStats* httpSessionStats_;
extern ResetControlMessages resetControlMessages_;
extern ResetHeaders resetHeaders_;