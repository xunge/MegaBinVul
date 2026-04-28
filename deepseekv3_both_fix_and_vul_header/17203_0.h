#include <stdlib.h>
#include <stdio.h>

extern char *outbuf;
extern char *mbf;
extern size_t outbufsz;
extern int outft;

void error(int status, const char *format, ...);
void draw_sym_near(void);
float draw_systems(float indent);
void a2b(const char *format, ...);