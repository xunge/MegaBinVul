#include <stdlib.h>
#include <assert.h>

typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint;

#define g_new0(type, count) calloc(count, sizeof(type))
#define g_free free
#define g_assert_not_reached() assert(0)