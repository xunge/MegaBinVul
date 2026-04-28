#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef int gint;
typedef unsigned char guchar;
typedef char gchar;

void *wmem_packet_scope(void);
void *tvb_memdup(void *scope, tvbuff_t *tvb, gint offset, gint length);
void *wmem_alloc0(void *scope, size_t size);