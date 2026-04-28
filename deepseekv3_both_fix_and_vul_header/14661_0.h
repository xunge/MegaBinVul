#include <string.h>
#include <math.h>

static void coeff_filter(double *mat_freq, int n, const double *kernel);
static void coeff_blur121(double *vec_freq, int n);
static void calc_gauss(double *vec_freq, int n, double r2);
static void calc_matrix(double mat[4][4], const double *mat_freq, const int index[4]);

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))