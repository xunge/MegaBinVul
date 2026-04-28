#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netdb.h>

#define LC_ASSERT(cond) ((void)0)

typedef struct SERVER_INFORMATION {
    char* address;
    char* rtspSessionUrl;
    char* serverInfoAppVersion;
} SERVER_INFORMATION, *PSERVER_INFORMATION;

typedef struct STREAM_CONFIGURATION {
    int bitrate;
    int packetSize;
    int width;
    int height;
    int audioConfiguration;
    int streamingRemotely;
    bool supportsHevc;
} STREAM_CONFIGURATION, *PSTREAM_CONFIGURATION;

typedef struct CONNECTION_LISTENER_CALLBACKS {
    void (*connectionTerminated)(int);
    void (*stageStarting)(int);
    void (*stageFailed)(int, int);
    void (*stageComplete)(int);
    void (*connectionStarted)(void);
} CONNECTION_LISTENER_CALLBACKS, *PCONNECTION_LISTENER_CALLBACKS;

typedef struct DECODER_RENDERER_CALLBACKS {
    unsigned int capabilities;
    void (*submitDecodeUnit)(void*);
} DECODER_RENDERER_CALLBACKS, *PDECODER_RENDERER_CALLBACKS;

typedef struct AUDIO_RENDERER_CALLBACKS {
    unsigned int capabilities;
} AUDIO_RENDERER_CALLBACKS, *PAUDIO_RENDERER_CALLBACKS;

#define CAPABILITY_PULL_RENDERER 0x01
#define CAPABILITY_DIRECT_SUBMIT 0x02
#define CAPABILITY_REFERENCE_FRAME_INVALIDATION_AVC 0x04

#define STREAM_CFG_AUTO 0
#define STREAM_CFG_LOCAL 1
#define STREAM_CFG_REMOTE 2

#define STAGE_PLATFORM_INIT 0
#define STAGE_NAME_RESOLUTION 1
#define STAGE_AUDIO_STREAM_INIT 2
#define STAGE_RTSP_HANDSHAKE 3
#define STAGE_CONTROL_STREAM_INIT 4
#define STAGE_VIDEO_STREAM_INIT 5
#define STAGE_INPUT_STREAM_INIT 6
#define STAGE_CONTROL_STREAM_START 7
#define STAGE_VIDEO_STREAM_START 8
#define STAGE_AUDIO_STREAM_START 9
#define STAGE_INPUT_STREAM_START 10

#define MAGIC_BYTE_FROM_AUDIO_CONFIG(x) ((x) >> 24)
#define CHANNEL_COUNT_FROM_AUDIO_CONFIGURATION(x) (((x) >> 16) & 0xFF)
#define AUDIO_CONFIGURATION_MAX_CHANNEL_COUNT 8

extern DECODER_RENDERER_CALLBACKS VideoCallbacks;
extern AUDIO_RENDERER_CALLBACKS AudioCallbacks;
extern CONNECTION_LISTENER_CALLBACKS ListenerCallbacks;
extern STREAM_CONFIGURATION StreamConfig;
extern int NegotiatedVideoFormat;
extern int OriginalVideoBitrate;
extern char* RemoteAddrString;
extern int VideoPortNumber;
extern int ControlPortNumber;
extern int AudioPortNumber;
extern int RtspPortNumber;
extern bool alreadyTerminated;
extern bool ConnectionInterrupted;
extern int AppVersionQuad[4];
extern void* RemoteAddr;
extern int RemoteAddrLen;
extern int stage;
extern void (*originalTerminationCallback)(int);

void Limelog(const char* fmt, ...);
void fixupMissingCallbacks(PDECODER_RENDERER_CALLBACKS*, PAUDIO_RENDERER_CALLBACKS*, PCONNECTION_LISTENER_CALLBACKS*);
void setRecorderCallbacks(PDECODER_RENDERER_CALLBACKS*, PAUDIO_RENDERER_CALLBACKS*);
void ClInternalConnectionTerminated(int);
bool parseRtspPortNumberFromUrl(const char*, int*);
int extractVersionQuadFromString(const char*, int*);
int initializePlatform();
int resolveHostName(const char*, int, int, void**, int*);
bool isPrivateNetworkAddress(void*);
int initializeAudioStream();
int performRtspHandshake();
int initializeControlStream();
void initializeVideoStream();
void initializeInputStream();
int startControlStream();
int startVideoStream(void*, int);
int startAudioStream(void*, int);
int startInputStream();
void LiSendMouseMoveEvent(int, int);
void PltSleepMs(int);
void LiStopConnection();