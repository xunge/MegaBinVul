#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <strings.h>

#define NUM_EQ_BANDS 10
#define ALOGV(...)

#define EQ_PARAM_NUM_BANDS 0
#define EQ_PARAM_CUR_PRESET 1
#define EQ_PARAM_GET_NUM_OF_PRESETS 2
#define EQ_PARAM_BAND_LEVEL 3
#define EQ_PARAM_GET_BAND 4
#define EQ_PARAM_LEVEL_RANGE 5
#define EQ_PARAM_BAND_FREQ_RANGE 6
#define EQ_PARAM_CENTER_FREQ 7
#define EQ_PARAM_GET_PRESET_NAME 8
#define EQ_PARAM_PROPERTIES 9

typedef struct effect_context_s {
    // dummy structure
} effect_context_t;

typedef struct equalizer_context_s {
    // dummy structure
} equalizer_context_t;

typedef struct effect_param_s {
    int status;
    uint32_t psize;
    uint32_t vsize;
    void *data;
} effect_param_t;

// Function prototypes
int equalizer_get_band_level(equalizer_context_t *eq_ctxt, int band);
int equalizer_get_center_frequency(equalizer_context_t *eq_ctxt, int band);
void equalizer_get_band_freq_range(equalizer_context_t *eq_ctxt, int band, uint32_t *low, uint32_t *high);
int equalizer_get_band(equalizer_context_t *eq_ctxt, uint32_t freq);
int equalizer_get_preset(equalizer_context_t *eq_ctxt);
int equalizer_get_num_presets(equalizer_context_t *eq_ctxt);
const char *equalizer_get_preset_name(equalizer_context_t *eq_ctxt, int preset);

// strlcpy implementation for systems that don't have it
size_t strlcpy(char *dst, const char *src, size_t size);