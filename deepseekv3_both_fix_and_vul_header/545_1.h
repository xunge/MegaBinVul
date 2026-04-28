#include <stddef.h>
#include <linux/types.h>

#define UAC_VERSION_1 0x00
#define UAC_VERSION_2 0x20
#define UAC_VERSION_3 0x30
#define EINVAL 22

struct mixer_build {
    struct {
        int protocol;
    } *mixer;
};

struct uac_mixer_unit_descriptor {
    unsigned char bLength;
    unsigned char bNrInPins;
};

static int uac_mixer_unit_bNrChannels(struct uac_mixer_unit_descriptor *desc) { return 0; }
static int get_cluster_channels_v3(struct mixer_build *state, int cluster_id) { return 0; }
static int uac3_mixer_unit_wClusterDescrID(struct uac_mixer_unit_descriptor *desc) { return 0; }
static void *uac_mixer_unit_bmControls(struct uac_mixer_unit_descriptor *desc, int protocol) { return NULL; }