#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CA_UNINITIALIZED,
    CA_DISCONNECTED
} connstate_t;

typedef enum {
    qfalse,
    qtrue
} qboolean;

typedef struct {
    connstate_t state;
} clientConnection_t;

typedef struct {
    int realtime;
} clientStatic_t;

typedef struct {
    qboolean oldGameSet;
} clientState_t;

typedef struct {
    int integer;
    char* string;
} cvar_t;

#define CVAR_TEMP 0
#define CVAR_ARCHIVE (1 << 0)
#define CVAR_USERINFO (1 << 1)
#define CVAR_SERVERINFO (1 << 2)
#define CVAR_ROM (1 << 3)
#define CVAR_LATCH (1 << 4)

#define MAX_JOYSTICK_AXIS 16
#define DEFAULT_CURL_LIB "libcurl.so"

extern clientConnection_t clc;
extern clientStatic_t cls;
extern clientState_t cl;
extern qboolean com_fullyInitialized;
extern qboolean cl_oldGameSet;
extern cvar_t *com_dedicated;

extern cvar_t *cl_noprint;
extern cvar_t *cl_motd;
extern cvar_t *cl_timeout;
extern cvar_t *cl_timeNudge;
extern cvar_t *cl_shownet;
extern cvar_t *cl_showSend;
extern cvar_t *cl_showTimeDelta;
extern cvar_t *cl_freezeDemo;
extern cvar_t *rcon_client_password;
extern cvar_t *cl_activeAction;
extern cvar_t *cl_timedemo;
extern cvar_t *cl_timedemoLog;
extern cvar_t *cl_autoRecordDemo;
extern cvar_t *cl_aviFrameRate;
extern cvar_t *cl_aviMotionJpeg;
extern cvar_t *cl_forceavidemo;
extern cvar_t *rconAddress;
extern cvar_t *cl_yawspeed;
extern cvar_t *cl_pitchspeed;
extern cvar_t *cl_anglespeedkey;
extern cvar_t *cl_maxpackets;
extern cvar_t *cl_packetdup;
extern cvar_t *cl_run;
extern cvar_t *cl_sensitivity;
extern cvar_t *cl_mouseAccel;
extern cvar_t *cl_freelook;
extern cvar_t *cl_mouseAccelStyle;
extern cvar_t *cl_mouseAccelOffset;
extern cvar_t *cl_showMouseRate;
extern cvar_t *cl_allowDownload;
extern cvar_t *cl_cURLLib;
extern cvar_t *cl_conXOffset;
extern cvar_t *cl_inGameVideo;
extern cvar_t *cl_serverStatusResendTime;
extern cvar_t *m_pitch;
extern cvar_t *m_yaw;
extern cvar_t *m_forward;
extern cvar_t *m_side;
extern cvar_t *m_filter;
extern cvar_t *j_pitch;
extern cvar_t *j_yaw;
extern cvar_t *j_forward;
extern cvar_t *j_side;
extern cvar_t *j_up;
extern cvar_t *j_pitch_axis;
extern cvar_t *j_yaw_axis;
extern cvar_t *j_forward_axis;
extern cvar_t *j_side_axis;
extern cvar_t *j_up_axis;
extern cvar_t *cl_motdString;
extern cvar_t *cl_lanForcePackets;
extern cvar_t *cl_guidServerUniq;
extern cvar_t *cl_consoleKeys;
extern cvar_t *cl_rate;
extern cvar_t *cl_useMumble;
extern cvar_t *cl_mumbleScale;
extern cvar_t *cl_voipSend;
extern cvar_t *cl_voipSendTarget;
extern cvar_t *cl_voipGainDuringCapture;
extern cvar_t *cl_voipCaptureMult;
extern cvar_t *cl_voipUseVAD;
extern cvar_t *cl_voipVADThreshold;
extern cvar_t *cl_voipShowMeter;
extern cvar_t *cl_voip;
extern cvar_t *cl_voipProtocol;

void Com_Printf(const char *fmt, ...);
void Con_Init(void);
void CL_ClearState(void);
void CL_InitInput(void);
cvar_t *Cvar_Get(const char *var_name, const char *var_value, int flags);
void Cvar_CheckRange(cvar_t *var, float min, float max, qboolean integral);
void Cvar_Set(const char *var_name, const char *value);
void Cmd_AddCommand(const char *cmd_name, void (*function)(void));
void Cmd_SetCommandCompletionFunc(const char *cmd, void (*complete)(char *args, int argNum));
void CL_InitRef(void);
void SCR_Init(void);
void CL_GenerateQKey(void);
void CL_UpdateGUID(const char *p, int len);

void CL_ForwardToServer_f(void);
void CL_Configstrings_f(void);
void CL_Clientinfo_f(void);
void CL_Snd_Restart_f(void);
void CL_Vid_Restart_f(void);
void CL_Disconnect_f(void);
void CL_Record_f(void);
void CL_PlayDemo_f(void);
void CL_CompleteDemoName(char *args, int argNum);
void CL_PlayCinematic_f(void);
void CL_StopRecord_f(void);
void CL_Connect_f(void);
void CL_Reconnect_f(void);
void CL_LocalServers_f(void);
void CL_GlobalServers_f(void);
void CL_Rcon_f(void);
void CL_CompleteRcon(char *args, int argNum);
void CL_Ping_f(void);
void CL_ServerStatus_f(void);
void CL_ShowIP_f(void);
void CL_OpenedPK3List_f(void);
void CL_ReferencedPK3List_f(void);
void CL_SetModel_f(void);
void CL_Video_f(void);
void CL_StopVideo_f(void);
void CL_Sayto_f(void);
void CL_CompletePlayerName(char *args, int argNum);