#include <ctype.h>
#include <string.h>

static const char *month_names[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static int xtoupper(int c) { return toupper(c); }
static int xtolower(int c) { return tolower(c); }