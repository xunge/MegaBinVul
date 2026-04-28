#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXDNAME 255
#define THROW(x) 

typedef struct tvbuff tvbuff_t;
typedef unsigned char guchar;

typedef struct wmem_allocator_t wmem_allocator_t;
wmem_allocator_t* wmem_packet_scope(void);
void* wmem_alloc(wmem_allocator_t* allocator, size_t size);

int tvb_reported_length_remaining(tvbuff_t* tvb, int offset);
uint8_t tvb_get_guint8(tvbuff_t* tvb, int offset);

int g_snprintf(char* str, size_t size, const char* format, ...);