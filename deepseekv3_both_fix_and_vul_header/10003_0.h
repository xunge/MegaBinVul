#include <stddef.h>
#include <string.h>

typedef enum { qfalse, qtrue } qboolean;
#define MAX_RAW_STREAMS 32

typedef struct {
    void (*Shutdown)(void);
    void (*StartSound)(void);
    void (*StartSoundEx)(void);
    void (*StartLocalSound)(void);
    void (*StartBackgroundTrack)(void);
    void (*StopBackgroundTrack)(void);
    void (*StartStreamingSound)(void);
    void (*GetVoiceAmplitude)(void);
    void (*RawSamples)(void);
    void (*StopAllSounds)(void);
    void (*ClearLoopingSounds)(void);
    void (*AddLoopingSound)(void);
    void (*AddRealLoopingSound)(void);
    void (*StopLoopingSound)(void);
    void (*Respatialize)(void);
    void (*UpdateEntityPosition)(void);
    void (*Update)(void);
    void (*DisableSounds)(void);
    void (*BeginRegistration)(void);
    void (*RegisterSound)(void);
    void (*ClearSoundBuffer)(void);
    void (*SoundInfo)(void);
    void (*SoundList)(void);
#ifdef USE_VOIP
    void (*StartCapture)(void);
    void (*AvailableCaptureSamples)(void);
    void (*Capture)(void);
    void (*StopCapture)(void);
    void (*MasterGain)(void);
#endif
} soundInterface_t;

typedef struct cvar_s {
    char *string;
    float value;
    int integer;
} cvar_t;

extern cvar_t *Cvar_Get(const char *name, const char *value, int flags);
extern void Com_Printf(const char *fmt, ...);
extern void Q_strcat(char *dest, int size, const char *src);
extern int Q_stricmp(const char *s1, const char *s2);
extern qboolean QAL_Init(const char *libname);
extern void QAL_Shutdown(void);

#define CVAR_ARCHIVE 0
#define CVAR_CHEAT 0
#define CVAR_LATCH 0
#define CVAR_NORESTART 0
#define CVAR_ROM 0

#define ALDRIVER_DEFAULT "default"
#define VOIP_MAX_PACKET_SAMPLES 0

static int streamSourceHandles[MAX_RAW_STREAMS];
static qboolean streamPlaying[MAX_RAW_STREAMS];
static unsigned int streamSources[MAX_RAW_STREAMS];
static int streamNumBuffers[MAX_RAW_STREAMS];
static int streamBufIndex[MAX_RAW_STREAMS];
static cvar_t *s_alPrecache;
static cvar_t *s_alGain;
static cvar_t *s_alSources;
static cvar_t *s_alDopplerFactor;
static cvar_t *s_alDopplerSpeed;
static cvar_t *s_alMinDistance;
static cvar_t *s_alMaxDistance;
static cvar_t *s_alRolloff;
static cvar_t *s_alGraceDistance;
static cvar_t *s_alDriver;
static cvar_t *s_alInputDevice;
static cvar_t *s_alDevice;
static cvar_t *s_alAvailableDevices;
static cvar_t *s_alAvailableInputDevices;
static cvar_t *s_alCapture;
static int srcCount;
static qboolean enumeration_all_ext;
static qboolean enumeration_ext;
static qboolean capture_ext;
static void *alDevice;
static void *alContext;
static void *alCaptureDevice;

#define ALC_ALL_DEVICES_SPECIFIER 0
#define ALC_DEFAULT_ALL_DEVICES_SPECIFIER 0
#define ALC_DEVICE_SPECIFIER 0
#define ALC_DEFAULT_DEVICE_SPECIFIER 0
#define ALC_CAPTURE_DEVICE_SPECIFIER 0
#define ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER 0

extern int qalcIsExtensionPresent(void *device, const char *extname);
extern const char *qalcGetString(void *device, int param);
extern void *qalcOpenDevice(const char *devicename);
extern void *qalcCreateContext(void *device, const int *attrlist);
extern int qalcMakeContextCurrent(void *context);
extern void qalcCloseDevice(void *device);
extern void qalDistanceModel(int value);
extern void qalDopplerFactor(float value);
extern void qalSpeedOfSound(float value);
extern void *qalcCaptureOpenDevice(const char *devicename, unsigned int frequency, int format, int buffersize);

void S_AL_BufferInit(void);
void S_AL_SrcInit(void);
void S_AL_Shutdown(void);
void S_AL_StartSound(void);
void S_AL_StartSoundEx(void);
void S_AL_StartLocalSound(void);
void S_AL_StartBackgroundTrack(void);
void S_AL_StopBackgroundTrack(void);
void S_AL_StartStreamingSound(void);
void S_AL_GetVoiceAmplitude(void);
void S_AL_RawSamples(void);
void S_AL_StopAllSounds(void);
void S_AL_ClearLoopingSounds(void);
void S_AL_AddLoopingSound(void);
void S_AL_AddRealLoopingSound(void);
void S_AL_StopLoopingSound(void);
void S_AL_Respatialize(void);
void S_AL_UpdateEntityPosition(void);
void S_AL_Update(void);
void S_AL_DisableSounds(void);
void S_AL_BeginRegistration(void);
void S_AL_RegisterSound(void);
void S_AL_ClearSoundBuffer(void);
void S_AL_SoundInfo(void);
void S_AL_SoundList(void);
#ifdef USE_VOIP
void S_AL_StartCapture(void);
void S_AL_AvailableCaptureSamples(void);
void S_AL_Capture(void);
void S_AL_StopCapture(void);
void S_AL_MasterGain(void);
#endif