#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int gint;
typedef unsigned int guint;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef unsigned char guchar;
typedef char gchar;
typedef int gboolean;
typedef size_t gsize;
typedef void* gpointer;
typedef const void* gconstpointer;

#define GUINT16_FROM_LE(x) (x)
#define GUINT32_FROM_LE(x) (x)

#define PSP_CRTR_FLD_TITLE 0
#define PSP_CRTR_FLD_ARTIST 1
#define PSP_CRTR_FLD_CPYRGHT 2
#define PSP_CRTR_FLD_DESC 3
#define PSP_CRTR_FLD_CRT_DATE 4
#define PSP_CRTR_FLD_MOD_DATE 5
#define PSP_CRTR_FLD_APP_ID 6
#define PSP_CRTR_FLD_APP_VER 7

#define GIMP_PARASITE_PERSISTENT 0
#define FALSE 0

struct _GString {
    gchar *str;
    gsize len;
};

typedef struct _GString GString;
typedef struct _GimpParasite GimpParasite;
typedef struct _PSPimage PSPimage;

static gint try_fseek(FILE *f, long offset, int whence);

GString* g_string_new(const gchar *init);
void g_string_append(GString *string, const gchar *val);
void g_string_free(GString *string, gboolean free_segment);

GimpParasite* gimp_parasite_new(const gchar *name, guint32 flags, guint32 size, gconstpointer data);
void gimp_parasite_free(GimpParasite *parasite);
void gimp_image_attach_parasite(gint image_ID, const GimpParasite *parasite);

void g_message(const gchar *format, ...);