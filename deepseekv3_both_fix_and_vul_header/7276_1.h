#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct ok_jpg ok_jpg;

typedef struct ok_jpg_decoder {
    ok_jpg *jpg;
    bool eoi_found;
    int next_marker;
    bool progressive;
    bool info_only;
    int num_components;
    struct {
        bool complete;
    } components[4];
} ok_jpg_decoder;

enum {
    OK_JPG_ERROR_INVALID
};

static bool ok_read(ok_jpg_decoder *decoder, uint8_t *buffer, size_t length);
static void ok_jpg_error(ok_jpg *jpg, int error, const char *message);
static bool ok_jpg_read_sof(ok_jpg_decoder *decoder);
static bool ok_jpg_skip_segment(ok_jpg_decoder *decoder);
static bool ok_jpg_read_dht(ok_jpg_decoder *decoder);
static bool ok_jpg_decode_restart_if_needed(ok_jpg_decoder *decoder);
static bool ok_jpg_scan_to_next_marker(ok_jpg_decoder *decoder);
static void ok_jpg_progressive_finish(ok_jpg_decoder *decoder);
static bool ok_jpg_read_sos(ok_jpg_decoder *decoder);
static bool ok_jpg_read_dqt(ok_jpg_decoder *decoder);
static bool ok_jpg_read_dri(ok_jpg_decoder *decoder);
static bool ok_jpg_read_exif(ok_jpg_decoder *decoder);