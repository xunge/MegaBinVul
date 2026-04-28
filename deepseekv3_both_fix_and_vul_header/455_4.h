#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_SUPPORTED_TV_TIMING 16
#define MAX_SUPPORTED_TV_TIMING_V1_2 32

#define DATA 0
#define AnalogTV_Info 0

#define ATOM_VSYNC_POLARITY (1 << 0)
#define ATOM_HSYNC_POLARITY (1 << 1)
#define ATOM_COMPOSITESYNC (1 << 2)
#define ATOM_INTERLACE (1 << 3)
#define ATOM_DOUBLE_CLOCK_MODE (1 << 4)

#define DRM_MODE_FLAG_NVSYNC (1 << 0)
#define DRM_MODE_FLAG_NHSYNC (1 << 1)
#define DRM_MODE_FLAG_CSYNC (1 << 2)
#define DRM_MODE_FLAG_INTERLACE (1 << 3)
#define DRM_MODE_FLAG_DBLSCAN (1 << 4)

typedef uint8_t u8;
typedef uint16_t u16;

struct atom_context {
    uint8_t *bios;
};

struct radeon_mode_info {
    struct atom_context *atom_context;
};

struct radeon_device {
    struct radeon_mode_info mode_info;
};

struct drm_display_mode {
    uint16_t crtc_htotal;
    uint16_t crtc_hdisplay;
    uint16_t crtc_hsync_start;
    uint16_t crtc_hsync_end;
    uint16_t crtc_vtotal;
    uint16_t crtc_vdisplay;
    uint16_t crtc_vsync_start;
    uint16_t crtc_vsync_end;
    uint32_t flags;
    uint32_t clock;
};

struct ATOM_DTD_FORMAT {
    uint16_t usHActive;
    uint16_t usHBlanking_Time;
    uint16_t usHSyncOffset;
    uint16_t usHSyncWidth;
    uint16_t usVActive;
    uint16_t usVBlanking_Time;
    uint16_t usVSyncOffset;
    uint16_t usVSyncWidth;
    struct {
        uint16_t usAccess;
    } susModeMiscInfo;
    uint16_t usPixClk;
};

struct ATOM_ANALOG_TV_INFO {
    struct {
        uint16_t usCRTC_H_Total;
        uint16_t usCRTC_H_Disp;
        uint16_t usCRTC_H_SyncStart;
        uint16_t usCRTC_H_SyncWidth;
        uint16_t usCRTC_V_Total;
        uint16_t usCRTC_V_Disp;
        uint16_t usCRTC_V_SyncStart;
        uint16_t usCRTC_V_SyncWidth;
        struct {
            uint16_t usAccess;
        } susModeMiscInfo;
        uint16_t usPixelClock;
    } aModeTimings[MAX_SUPPORTED_TV_TIMING];
};

struct ATOM_ANALOG_TV_INFO_V1_2 {
    struct ATOM_DTD_FORMAT aModeTimings[MAX_SUPPORTED_TV_TIMING_V1_2];
};

typedef struct ATOM_ANALOG_TV_INFO ATOM_ANALOG_TV_INFO;
typedef struct ATOM_ANALOG_TV_INFO_V1_2 ATOM_ANALOG_TV_INFO_V1_2;
typedef struct ATOM_DTD_FORMAT ATOM_DTD_FORMAT;

static inline uint16_t le16_to_cpu(uint16_t val) {
    return val;
}

int GetIndexIntoMasterTable(int type, int index);
bool atom_parse_data_header(struct atom_context *ctx, int index, uint16_t *size, uint8_t *frev, uint8_t *crev, uint16_t *data_offset);