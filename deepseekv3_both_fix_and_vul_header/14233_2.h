#include <stdint.h>
#include <string.h>

typedef uint8_t guchar;
typedef uint32_t guint32;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define NULL ((void*)0)

typedef struct {
    const guchar **element;
    const guint32 *length;
    const guint32 *allocated;
    gboolean required;
    gboolean addtag;
    gboolean truncate;
    guchar tag;
} TOP_ELEMENT_CONTROL;

extern const TOP_ELEMENT_CONTROL canonifyTable[];

guint32 encode_ber_len(guchar *buff, guint32 len, guint32 size);
guint32 get_ber_len_size(guint32 len);