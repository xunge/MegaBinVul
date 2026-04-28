#include <stdlib.h>

#define MAX_WRITERS 256

struct pktcdvd_device;
static struct pktcdvd_device *pkt_devs[MAX_WRITERS];