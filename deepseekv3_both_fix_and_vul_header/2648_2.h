#include <stddef.h>

#define BUFFER_LEN 8192
typedef long long sf_count_t;

typedef struct SNDFILE SNDFILE;

#define SFC_CALC_SIGNAL_MAX 0x1000
#define SFC_SET_NORM_DOUBLE 0x1001
#define SF_FALSE 0

int sf_command(SNDFILE *sndfile, int command, void *data, int datasize);
sf_count_t sf_readf_double(SNDFILE *sndfile, double *ptr, sf_count_t frames);
sf_count_t sf_writef_double(SNDFILE *sndfile, const double *ptr, sf_count_t frames);