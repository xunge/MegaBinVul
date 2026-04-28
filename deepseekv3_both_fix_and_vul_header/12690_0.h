#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct caca_canvas caca_canvas_t;
typedef struct caca_font caca_font_t;

extern char const * const *caca_get_font_list(void);
extern caca_font_t *caca_load_font(char const *, int);
extern int caca_get_canvas_width(caca_canvas_t const *);
extern int caca_get_canvas_height(caca_canvas_t const *);
extern int caca_get_font_width(caca_font_t *);
extern int caca_get_font_height(caca_font_t *);
extern void caca_render_canvas(caca_canvas_t const *, caca_font_t *, char *, int, int, int);
extern void caca_free_font(caca_font_t *);