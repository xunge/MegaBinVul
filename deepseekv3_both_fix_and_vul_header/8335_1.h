#include <ctype.h>

#define MAX_OUTHDR_VALUES 10

typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint;

static guint outhdr_values[MAX_OUTHDR_VALUES];
static guint outhdr_values_found;