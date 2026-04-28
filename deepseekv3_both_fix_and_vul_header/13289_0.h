#include <stdbool.h>

enum spectre_v2_mitigation {
    SPECTRE_V2_IBRS,
    SPECTRE_V2_EIBRS,
    SPECTRE_V2_EIBRS_RETPOLINE,
    SPECTRE_V2_EIBRS_LFENCE
};