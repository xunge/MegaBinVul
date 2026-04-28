#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*opj_msg_callback)(const char *msg, void *client_data);

typedef struct opj_event_mgr_t {
    opj_msg_callback error_handler;
    opj_msg_callback warning_handler;
    opj_msg_callback info_handler;
} opj_event_mgr_t;

typedef struct opj_dinfo_t {
    void* mj2_handle;
} opj_dinfo_t;

typedef void* opj_common_ptr;

typedef struct mj2_sample_t {
    unsigned int sample_size;
    unsigned int offset;
} mj2_sample_t;

typedef struct mj2_tk_t {
    int track_type;
    unsigned int num_samples;
    struct mj2_sample_t* sample;
} mj2_tk_t;

typedef struct opj_mj2_t {
    struct mj2_tk_t* tk;
} opj_mj2_t;

typedef struct mj2_dparameters_t {
    int dummy;
} mj2_dparameters_t;

void error_callback(const char *msg, void *client_data);
void warning_callback(const char *msg, void *client_data);
void info_callback(const char *msg, void *client_data);

opj_dinfo_t* mj2_create_decompress(void);
void opj_set_event_mgr(opj_common_ptr cinfo, opj_event_mgr_t *event_mgr, void *context);
void mj2_setup_decoder(opj_mj2_t *movie, mj2_dparameters_t *parameters);
int mj2_read_struct(FILE *file, opj_mj2_t *movie);
void mj2_destroy_decompress(opj_mj2_t *movie);