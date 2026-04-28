#include <string.h>

#define initial_n 128
#define initial_bias 72
#define delimiter '-'
#define base 36
#define tmin 1
#define tmax 26
#define maxint ((unsigned int)-1)

static int is_basic(unsigned int ch);
static int digit_decoded(char c);
static unsigned int adapt(unsigned int delta, unsigned int numpoints, int first);