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
    void (*StartCapture)(void);
    void (*AvailableCaptureSamples)(void);
    void (*Capture)(void);
    void (*StopCapture)(void);
    void (*MasterGain)(void);
} soundInterface_t;

extern int streamSourceHandles[MAX_RAW_STREAMS];
extern qboolean streamPlaying[MAX_RAW_STREAMS];
extern unsigned int streamSources[MAX_RAW_STREAMS];
extern int streamNumBuffers[MAX_RAW_STREAMS];
extern int streamBufIndex[MAX_RAW_STREAMS];
extern qboolean enumeration_all_ext;
extern qboolean enumeration_ext;
extern qboolean capture_ext;
extern int srcCount;

#define ALDRIVER_DEFAULT "OpenAL32.dll"
#define VOIP_MAX_PACKET_SAMPLES 1024

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

extern void *alDevice;
extern void *alContext;
extern void *alCaptureDevice;

#define CVAR_ARCHIVE 0
#define CVAR_LATCH 0
#define CVAR_CHEAT 0
#define CVAR_ROM 0
#define CVAR_NORESTART 0

extern cvar_t *Cvar_Get(const char *name, const char *value, int flags);
extern void Com_Printf(const char *fmt, ...);
extern void Q_strcat(char *dest, size_t size, const char *src);
extern int Q_stricmp(const char *s1, const char *s2);
extern qboolean QAL_Init(const char *libname);
extern void QAL_Shutdown(void);
extern int qalcIsExtensionPresent(void *device, const char *extname);
extern const char *qalcGetString(void *device, int param);
extern void *qalcOpenDevice(const char *devicename);
extern void *qalcCreateContext(void *device, const int *attrlist);
extern int qalcMakeContextCurrent(void *context);
extern void qalDistanceModel(int value);
extern void qalDopplerFactor(float value);
extern void qalSpeedOfSound(float value);
extern void *qalcCaptureOpenDevice(const char *devicename, unsigned int frequency, int format, int buffersize);
extern void S_AL_BufferInit(void);
extern void S_AL_SrcInit(void);