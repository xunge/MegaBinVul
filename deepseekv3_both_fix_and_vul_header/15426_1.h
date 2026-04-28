#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STAGE_PLATFORM_INIT 0
#define STAGE_NAME_RESOLUTION 1
#define STAGE_RTSP_HANDSHAKE 2
#define STAGE_CONTROL_STREAM_INIT 3
#define STAGE_VIDEO_STREAM_INIT 4
#define STAGE_AUDIO_STREAM_INIT 5
#define STAGE_INPUT_STREAM_INIT 6
#define STAGE_CONTROL_STREAM_START 7
#define STAGE_VIDEO_STREAM_START 8
#define STAGE_AUDIO_STREAM_START 9
#define STAGE_INPUT_STREAM_START 10

#define LC_ASSERT(cond) ((void)0)

typedef struct SERVER_INFORMATION {
    char* address;
    char* serverInfoAppVersion;
} SERVER_INFORMATION, *PSERVER_INFORMATION;

typedef struct STREAM_CONFIGURATION {
    // Add necessary fields
} STREAM_CONFIGURATION, *PSTREAM_CONFIGURATION;

typedef struct CONNECTION_LISTENER_CALLBACKS {
    void (*connectionTerminated)(int);
    void (*stageStarting)(int);
    void (*stageComplete)(int);
    void (*stageFailed)(int, int);
    void (*connectionStarted)(void);
} CONNECTION_LISTENER_CALLBACKS, *PCONNECTION_LISTENER_CALLBACKS;

typedef struct DECODER_RENDERER_CALLBACKS {
    // Add necessary fields
} DECODER_RENDERER_CALLBACKS, *PDECODER_RENDERER_CALLBACKS;

typedef struct AUDIO_RENDERER_CALLBACKS {
    // Add necessary fields
} AUDIO_RENDERER_CALLBACKS, *PAUDIO_RENDERER_CALLBACKS;

extern int NegotiatedVideoFormat;
extern STREAM_CONFIGURATION StreamConfig;
extern char* RemoteAddrString;
extern int AppVersionQuad[4];
extern DECODER_RENDERER_CALLBACKS VideoCallbacks;
extern AUDIO_RENDERER_CALLBACKS AudioCallbacks;
extern CONNECTION_LISTENER_CALLBACKS ListenerCallbacks;
extern void (*originalTerminationCallback)(int);
extern int alreadyTerminated;
extern int stage;
extern int ServerMajorVersion;

int extractVersionQuadFromString(const char* str, int* quad);
void Limelog(const char* fmt, ...);
void fixupMissingCallbacks(PDECODER_RENDERER_CALLBACKS* drCallbacks, PAUDIO_RENDERER_CALLBACKS* arCallbacks, PCONNECTION_LISTENER_CALLBACKS* clCallbacks);
void ClInternalConnectionTerminated(int errorCode);
int initializePlatform();
int resolveHostName(const char* host);
int performRtspHandshake();
int initializeControlStream();
void initializeVideoStream();
void initializeAudioStream();
void initializeInputStream();
int startControlStream();
int startVideoStream(void* renderContext, int drFlags);
int startAudioStream();
int startInputStream();