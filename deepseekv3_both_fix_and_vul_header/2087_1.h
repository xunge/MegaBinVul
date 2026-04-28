#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256
#define FALSE false
#define TRUE true

static int initialized = 0;
static void init_hex_table(void);
static int next_int(FILE *fstream);

typedef bool gboolean;
typedef unsigned char guchar;
typedef unsigned int guint;

#define g_free free
#define g_malloc malloc