#include <time.h>
#include <stdio.h>

typedef struct netdissect_options netdissect_options;
#define ND_PRINT(...) printf(__VA_ARGS__)

enum date_flag { WITH_DATE, WITHOUT_DATE };
enum time_flag { LOCAL_TIME, GMT_TIME };

static void ts_frac_print(netdissect_options *ndo, long usec);