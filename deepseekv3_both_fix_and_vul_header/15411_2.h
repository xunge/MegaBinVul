#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct SERVER_INFORMATION {
    char* rtspSessionUrl;
    int serverCodecModeSupport;
} SERVER_INFORMATION, *PSERVER_INFORMATION;

typedef struct RTSP_MESSAGE {
    struct {
        struct {
            int statusCode;
        } response;
    } message;
    char* payload;
    void* options;
} RTSP_MESSAGE;

typedef struct {
    int capabilities;
} AUDIO_CALLBACKS;

typedef struct {
    int streamingRemotely;
    int audioConfiguration;
    int supportedVideoFormats;
    int bitrate;
    int width;
    int height;
    int av1BitratePercentageMultiplier;
    int hevcBitratePercentageMultiplier;
} STREAM_CONFIG;

typedef struct {
    char payload[256];
} PING_PAYLOAD;

typedef struct {
    int type;
} ENetEvent;

typedef struct {
    void* peer;
} ENetHost;

typedef struct {
    void* host;
} ENetPeer;

typedef struct {
    int family;
} ENetAddress;

// Constants
#define STREAM_CFG_AUTO 0
#define STREAM_CFG_REMOTE 1
#define HIGH_AUDIO_BITRATE_THRESHOLD 15000000
#define CAPABILITY_SLOW_OPUS_DECODER 1
#define RTSP_CONNECT_TIMEOUT_SEC 5
#define VIDEO_FORMAT_MASK_AV1 0x01
#define VIDEO_FORMAT_AV1_MAIN10 0x02
#define VIDEO_FORMAT_AV1_MAIN8 0x04
#define VIDEO_FORMAT_MASK_H265 0x08
#define VIDEO_FORMAT_H265_MAIN10 0x10
#define VIDEO_FORMAT_H265 0x20
#define VIDEO_FORMAT_H264 0x40
#define SCM_AV1_MAIN10 0x01
#define SCM_HEVC_MAIN10 0x02
#define ENET_EVENT_TYPE_CONNECT 1

// Global variables
extern int RtspPortNumber;
extern bool useEnet;
extern int currentSeqNumber;
extern bool hasSessionId;
extern char* controlStreamId;
extern bool AudioEncryptionEnabled;
extern int OriginalVideoBitrate;
extern AUDIO_CALLBACKS AudioCallbacks;
extern STREAM_CONFIG StreamConfig;
extern char rtspTargetUrl[256];
extern char urlAddr[256];
extern int AppVersionQuad[4];
extern int rtspClientVersion;
extern ENetHost* client;
extern ENetPeer* peer;
extern struct sockaddr_storage RemoteAddr;
extern size_t RemoteAddrLen;
extern char* sessionIdString;
extern unsigned short AudioPortNumber;
extern unsigned short VideoPortNumber;
extern unsigned short ControlPortNumber;
extern PING_PAYLOAD AudioPingPayload;
extern PING_PAYLOAD VideoPingPayload;
extern int NegotiatedVideoFormat;
extern bool ReferenceFrameInvalidationSupported;
extern unsigned int SunshineFeatureFlags;

// Function declarations
bool requestOptions(RTSP_MESSAGE* response, int* error);
bool requestDescribe(RTSP_MESSAGE* response, int* error);
bool setupStream(RTSP_MESSAGE* response, const char* streamId, int* error);
bool playStream(RTSP_MESSAGE* response, const char* streamId, int* error);
bool sendVideoAnnounce(RTSP_MESSAGE* response, int* error);
void freeMessage(RTSP_MESSAGE* message);
char* getOptionContent(void* options, const char* optionName);
bool parseUrlAddrFromRtspUrlString(const char* url, char* addr, size_t addrLen);
void addrToUrlSafeString(const struct sockaddr_storage* addr, char* str, size_t strLen);
void PltSafeStrcpy(char* dest, size_t destSize, const char* src);
int parseOpusConfigurations(RTSP_MESSAGE* response);
void notifyAudioPortNegotiationComplete(void);
bool parseServerPortFromTransport(RTSP_MESSAGE* response, unsigned short* port);
bool parseSdpAttributeToUInt(const char* sdp, const char* attribute, unsigned int* value);
int serviceEnetHost(ENetHost* host, ENetEvent* event, int timeoutMs);
void Limelog(const char* format, ...);
void enet_address_set_address(ENetAddress* address, struct sockaddr* sa, size_t sa_len);
void enet_address_set_port(ENetAddress* address, unsigned short port);
ENetHost* enet_host_create(int family, void* unused1, int unused2, int unused3, int unused4, int unused5);
ENetPeer* enet_host_connect(ENetHost* host, ENetAddress* address, int unused1, int unused2);
void enet_peer_reset(ENetPeer* peer);
void enet_host_destroy(ENetHost* host);
void enet_host_flush(ENetHost* host);
void enet_peer_disconnect_now(ENetPeer* peer, int unused);

#define LC_ASSERT(cond) ((void)0)
#define APP_VERSION_AT_LEAST(a, b, c) (0)
#define CHANNEL_COUNT_FROM_AUDIO_CONFIGURATION(config) (0)