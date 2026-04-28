#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct VncState VncState;
typedef struct VncDisplay VncDisplay;

#define VNC_MSG_CLIENT_SET_PIXEL_FORMAT 0
#define VNC_MSG_CLIENT_SET_ENCODINGS 2
#define VNC_MSG_CLIENT_FRAMEBUFFER_UPDATE_REQUEST 3
#define VNC_MSG_CLIENT_KEY_EVENT 4
#define VNC_MSG_CLIENT_POINTER_EVENT 5
#define VNC_MSG_CLIENT_CUT_TEXT 6
#define VNC_MSG_CLIENT_XVP 250
#define VNC_MSG_CLIENT_QEMU 255
#define VNC_MSG_CLIENT_SET_DESKTOP_SIZE 251

#define VNC_FEATURE_XVP (1 << 0)
#define VNC_XVP_ACTION_SHUTDOWN 0
#define VNC_XVP_ACTION_REBOOT 1
#define VNC_XVP_ACTION_RESET 2
#define VNC_XVP_CODE_FAIL 1

#define VNC_MSG_CLIENT_QEMU_EXT_KEY_EVENT 0
#define VNC_MSG_CLIENT_QEMU_AUDIO 1
#define VNC_MSG_CLIENT_QEMU_AUDIO_ENABLE 0
#define VNC_MSG_CLIENT_QEMU_AUDIO_DISABLE 1
#define VNC_MSG_CLIENT_QEMU_AUDIO_SET_FORMAT 2

#define VNC_REFRESH_INTERVAL_BASE 30

#define SHUTDOWN_CAUSE_HOST_QMP_SYSTEM_RESET 0

#define AUDIO_FORMAT_U8 0
#define AUDIO_FORMAT_S8 1
#define AUDIO_FORMAT_U16 2
#define AUDIO_FORMAT_S16 3
#define AUDIO_FORMAT_U32 4
#define AUDIO_FORMAT_S32 5

typedef struct {
    int con;
} DisplayChangeListener;

struct VncDisplay {
    DisplayChangeListener dcl;
};

struct VncState {
    VncDisplay *vd;
    unsigned int features;
    struct {
        int fmt;
        int nchannels;
        uint32_t freq;
    } as;
    void *ioc;
};

typedef struct {
    int width;
    int height;
} QemuUIInfo;

static inline uint8_t read_u8(const uint8_t *data, int offset) { return data[offset]; }
static inline uint16_t read_u16(const uint8_t *data, int offset) { return (data[offset] << 8) | data[offset+1]; }
static inline uint32_t read_u32(const uint8_t *data, int offset) { return (data[offset] << 24) | (data[offset+1] << 16) | (data[offset+2] << 8) | data[offset+3]; }
static inline int32_t read_s32(const uint8_t *data, int offset) { return (int32_t)read_u32(data, offset); }

static inline void update_displaychangelistener(DisplayChangeListener *dcl, int interval) {}
static inline void set_pixel_format(VncState *vs, uint8_t a, uint8_t b, uint8_t c, uint16_t d, uint16_t e, uint16_t f, uint8_t g, uint8_t h, uint8_t i) {}
static inline void set_encodings(VncState *vs, int32_t *encodings, uint16_t limit) {}
static inline void framebuffer_update_request(VncState *vs, uint8_t a, uint16_t b, uint16_t c, uint16_t d, uint16_t e) {}
static inline void key_event(VncState *vs, uint8_t a, uint32_t b) {}
static inline void pointer_event(VncState *vs, uint8_t a, uint16_t b, uint16_t c) {}
static inline void error_report(const char *fmt, ...) {}
static inline void vnc_client_error(VncState *vs) {}
static inline void vnc_client_cut_text_ext(VncState *vs, uint32_t a, uint32_t b, uint8_t *c) {}
static inline void vnc_client_cut_text(VncState *vs, uint32_t a, uint8_t *b) {}
static inline void qemu_system_powerdown_request(void) {}
static inline void send_xvp_message(VncState *vs, uint8_t code) {}
static inline void qemu_system_reset_request(int cause) {}
static inline void ext_key_event(VncState *vs, uint16_t a, uint32_t b, uint32_t c) {}
static inline void trace_vnc_msg_client_audio_enable(VncState *vs, void *ioc) {}
static inline void audio_add(VncState *vs) {}
static inline void trace_vnc_msg_client_audio_disable(VncState *vs, void *ioc) {}
static inline void audio_del(VncState *vs) {}
static inline void VNC_DEBUG(const char *fmt, ...) {}
static inline void trace_vnc_msg_client_audio_format(VncState *vs, void *ioc, int fmt, int nchannels, uint32_t freq) {}
static inline void trace_vnc_msg_client_set_desktop_size(VncState *vs, void *ioc, int w, int h, uint8_t screens) {}
static inline bool dpy_ui_info_supported(int con) { return false; }
static inline void dpy_set_ui_info(int con, QemuUIInfo *info, bool delay) {}
static inline void vnc_desktop_resize_ext(VncState *vs, int reason) {}
static inline void vnc_update_throttle_offset(VncState *vs) {}
static inline void vnc_read_when(VncState *vs, int (*func)(VncState*, uint8_t*, size_t), size_t len) {}