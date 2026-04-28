#include <stdio.h>
#include <stdlib.h>

typedef struct SDP_OPTION *PSDP_OPTION;

struct StreamConfig {
    int width;
    int height;
    int fps;
    int packetSize;
    int bitrate;
    int streamingRemotely;
    int audioConfiguration;
};

struct VideoCallbacks {
    unsigned int capabilities;
};

extern struct StreamConfig StreamConfig;
extern struct VideoCallbacks VideoCallbacks;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern int NegotiatedVideoFormat;
extern int VIDEO_FORMAT_H265;
extern int AUDIO_CONFIGURATION_51_SURROUND;
extern int CHANNEL_COUNT_51_SURROUND;
extern int CHANNEL_MASK_51_SURROUND;
extern int CHANNEL_COUNT_STEREO;
extern int CHANNEL_MASK_STEREO;

int addAttributeString(PSDP_OPTION* option, const char* name, const char* value);
int addGen3Options(PSDP_OPTION* option, char* urlSafeAddr);
int addGen4Options(PSDP_OPTION* option, char* urlSafeAddr);
int addGen5Options(PSDP_OPTION* option);
void freeAttributeList(PSDP_OPTION option);