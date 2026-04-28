#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct DisplayChangeListener {
    // dummy structure
} DisplayChangeListener;

typedef struct VncState {
    struct VncDisplay *vd;
    struct {
        int fmt;
        int nchannels;
        uint32_t freq;
    } as;
} VncState;

typedef struct VncDisplay {
    DisplayChangeListener dcl;
} VncDisplay;

enum {
    VNC_MSG_CLIENT_SET_PIXEL_FORMAT = 0,
    VNC_MSG_CLIENT_SET_ENCODINGS = 2,
    VNC_MSG_CLIENT_FRAMEBUFFER_UPDATE_REQUEST = 3,
    VNC_MSG_CLIENT_KEY_EVENT = 4,
    VNC_MSG_CLIENT_POINTER_EVENT = 5,
    VNC_MSG_CLIENT_CUT_TEXT = 6,
    VNC_MSG_CLIENT_QEMU = 255
};

enum {
    VNC_MSG_CLIENT_QEMU_EXT_KEY_EVENT = 0,
    VNC_MSG_CLIENT_QEMU_AUDIO = 1
};

enum {
    VNC_MSG_CLIENT_QEMU_AUDIO_ENABLE = 0,
    VNC_MSG_CLIENT_QEMU_AUDIO_DISABLE = 1,
    VNC_MSG_CLIENT_QEMU_AUDIO_SET_FORMAT = 2
};

enum {
    AUD_FMT_U8,
    AUD_FMT_S8,
    AUD_FMT_U16,
    AUD_FMT_S16,
    AUD_FMT_U32,
    AUD_FMT_S32
};

#define VNC_REFRESH_INTERVAL_BASE 30

static inline uint8_t read_u8(const uint8_t *data, int offset) {
    return data[offset];
}

static inline uint16_t read_u16(const uint8_t *data, int offset) {
    return (data[offset] << 8) | data[offset + 1];
}

static inline uint32_t read_u32(const uint8_t *data, int offset) {
    return (data[offset] << 24) | (data[offset + 1] << 16) | 
           (data[offset + 2] << 8) | data[offset + 3];
}

static inline int32_t read_s32(const uint8_t *data, int offset) {
    return (int32_t)read_u32(data, offset);
}

static void update_displaychangelistener(DisplayChangeListener *dcl, int interval) {}
static void set_pixel_format(VncState *vs, uint8_t a, uint8_t b, uint8_t c, uint8_t d,
                           uint16_t e, uint16_t f, uint16_t g, uint8_t h, uint8_t i, uint8_t j) {}
static void set_encodings(VncState *vs, int32_t *encodings, uint16_t limit) {}
static void framebuffer_update_request(VncState *vs, uint8_t a, uint16_t b, uint16_t c,
                                     uint16_t d, uint16_t e) {}
static void key_event(VncState *vs, uint8_t a, uint32_t b) {}
static void pointer_event(VncState *vs, uint8_t a, uint16_t b, uint16_t c) {}
static void client_cut_text(VncState *vs, uint32_t len, uint8_t *data) {}
static void ext_key_event(VncState *vs, uint16_t a, uint32_t b, uint32_t c) {}
static void audio_add(VncState *vs) {}
static void audio_del(VncState *vs) {}
static void vnc_client_error(VncState *vs) {}
static void vnc_read_when(VncState *vs, int (*func)(VncState *, uint8_t *, size_t), int size) {}