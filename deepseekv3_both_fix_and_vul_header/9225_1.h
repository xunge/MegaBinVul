#include <stdio.h>
#include <stdint.h>

#define ITEM_LABEL_LENGTH 256
typedef char gchar;
typedef uint32_t guint32;

char* udp_port_to_display(void* scope, guint32 port);
void* wmem_packet_scope(void);