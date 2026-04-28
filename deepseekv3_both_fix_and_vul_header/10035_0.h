#include <stddef.h>

typedef enum { FALSE, TRUE } boolean;

static int is_alpha_underscore(const char *c);
static int is_digit(const char *c);