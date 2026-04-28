#include <stdio.h>
#include <string.h>

typedef struct {
	char *data;
	size_t data_len;
} libgdbr_t;

static int send_ack(libgdbr_t *g);
static int send_msg(libgdbr_t *g, const char *msg);
static int eprintf(const char *format, ...);