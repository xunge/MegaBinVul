#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t uint_t;
typedef float smpl_t;

typedef struct {
    smpl_t *data;
    uint_t length;
} fvec_t;

typedef struct {
    fvec_t *winput;
    void *fft;
    fvec_t *fftout;
    fvec_t *sqrmag;
    fvec_t *yinfft;
    smpl_t tol;
    uint_t peak_pos;
    void *win;
    fvec_t *weight;
    uint_t short_period;
} aubio_pitchyinfft_t;

#define AUBIO_NEW(type) ((type *)malloc(sizeof(type)))
#define AUBIO_FREE(ptr) free(ptr)
#define DB2LIN(x) (pow(10.0, (x) / 20.0))
#define ROUND(x) ((uint_t)((x) + 0.5))

extern fvec_t *new_fvec(uint_t length);
extern void del_fvec(fvec_t *vec);
extern void *new_aubio_fft(uint_t size);
extern void *new_aubio_window(const char *type, uint_t size);

extern smpl_t freqs[];
extern smpl_t weight[];