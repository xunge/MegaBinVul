#include <stddef.h>
#include <string.h>

typedef enum { qfalse, qtrue } qboolean;
#define MAX_RAW_STREAMS 32

typedef struct {
    void (*Shutdown)(void);
    void (*StartSound)(void);
    void (*StartLocalSound)(void);
    void (*StartBackgroundTrack)(void);
    void (*StopBackgroundTrack)(void);
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

extern int streamSourceHandles[MAX_RAW_STREAMS];
extern qboolean streamPlaying[MAX_RAW_STREAMS];
extern unsigned int streamSources[MAX_RAW_STREAMS];
extern int streamNumBuffers[MAX_RAW_STREAMS];
extern int streamBufIndex[MAX_RAW_STREAMS];

extern void* alDevice;
extern void* alContext;
extern void* alCaptureDevice;
extern qboolean enumeration_ext;
extern qboolean enumeration_all_ext;
extern qboolean capture_ext;

#define ALDRIVER_DEFAULT "openal32.dll"
#define VOIP_MAX_PACKET_SAMPLES 1024

#define CVAR_ARCHIVE 0
#define CVAR_CHEAT 0
#define CVAR_LATCH 0
#define CVAR_NORESTART 0
#define CVAR_ROM 0

typedef struct cvar_s {
    char *string;
    float value;
    int integer;
} cvar_t;

extern cvar_t *s_alPrecache;
extern cvar_t *s_alGain;
extern cvar_t *s_alSources;
extern cvar_t *s_alDopplerFactor;
extern cvar_t *s_alDopplerSpeed;
extern cvar_t *s_alMinDistance;
extern cvar_t *s_alMaxDistance;
extern cvar_t *s_alRolloff;
extern cvar_t *s_alGraceDistance;
extern cvar_t *s_alDriver;
extern cvar_t *s_alInputDevice;
extern cvar_t *s_alDevice;
extern cvar_t *s_alAvailableDevices;
extern cvar_t *s_alAvailableInputDevices;
extern cvar_t *s_alCapture;
extern cvar_t *cl_useMumble;

extern cvar_t *Cvar_Get(const char *name, const char *value, int flags);
extern void Com_Printf(const char *fmt, ...);
extern int Q_stricmp(const char *s1, const char *s2);
extern void Q_strcat(char *dest, int size, const char *src);

extern qboolean QAL_Init(const char *libname);
extern void QAL_Shutdown(void);

#define ALC_ALL_DEVICES_SPECIFIER 0
#define ALC_DEFAULT_ALL_DEVICES_SPECIFIER 0
#define ALC_DEVICE_SPECIFIER 0
#define ALC_DEFAULT_DEVICE_SPECIFIER 0
#define ALC_CAPTURE_DEVICE_SPECIFIER 0
#define ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER 0

extern qboolean qalcIsExtensionPresent(void *device, const char *extname);
extern const char *qalcGetString(void *device, int param);
extern void *qalcOpenDevice(const char *devicename);
extern void *qalcCreateContext(void *device, const int *attrlist);
extern qboolean qalcMakeContextCurrent(void *context);
extern void qalcCloseDevice(void *device);
extern void qalDistanceModel(int value);
extern void qalDopplerFactor(float value);
extern void qalSpeedOfSound(float value);
extern void *qalcCaptureOpenDevice(const char *devicename, unsigned int frequency, int format, int buffersize);

extern void S_AL_BufferInit(void);
extern void S_AL_SrcInit(void);
extern void S_AL_Shutdown(void);
extern void S_AL_StartSound(void);
extern void S_AL_StartLocalSound(void);
extern void S_AL_StartBackgroundTrack(void);
extern void S_AL_StopBackgroundTrack(void);
extern void S_AL_RawSamples(void);
extern void S_AL_StopAllSounds(void);
extern void S_AL_ClearLoopingSounds(void);
extern void S_AL_AddLoopingSound(void);
extern void S_AL_AddRealLoopingSound(void);
extern void S_AL_StopLoopingSound(void);
extern void S_AL_Respatialize(void);
extern void S_AL_UpdateEntityPosition(void);
extern void S_AL_Update(void);
extern void S_AL_DisableSounds(void);
extern void S_AL_BeginRegistration(void);
extern void S_AL_RegisterSound(void);
extern void S_AL_ClearSoundBuffer(void);
extern void S_AL_SoundInfo(void);
extern void S_AL_SoundList(void);
#ifdef USE_VOIP
extern void S_AL_StartCapture(void);
extern void S_AL_AvailableCaptureSamples(void);
extern void S_AL_Capture(void);
extern void S_AL_StopCapture(void);
extern void S_AL_MasterGain(void);
#endif