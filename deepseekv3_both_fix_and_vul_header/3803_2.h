#include <stdint.h>
#include <stdbool.h>

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct gx_device_bjc_printer {
    bool FloydSteinbergDirectionForward;
    int *FloydSteinbergErrorsC;
    int FloydSteinbergC;
    int FloydSteinbergM;
    int FloydSteinbergY;
    int *bjc_gamma_tableC;
    int *bjc_gamma_tableM;
    int *bjc_gamma_tableY;
    int *bjc_treshold;
    int (*bjc_rand)(struct gx_device_bjc_printer *);
} gx_device_bjc_printer;