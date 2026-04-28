#include <sys/types.h>
#include <stddef.h>

typedef struct caca_canvas caca_canvas_t;

int caca_set_canvas_size(caca_canvas_t *cv, unsigned int width, unsigned int height);
int caca_put_char(caca_canvas_t *cv, unsigned int x, unsigned int y, unsigned char ch);