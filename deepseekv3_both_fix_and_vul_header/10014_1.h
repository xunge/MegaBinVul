#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QPATH 64
#define MAX_JOYSTICK_AXIS 16
#define qfalse 0
#define qtrue 1

typedef int qboolean;

typedef enum {
    CA_UNINITIALIZED,
    CA_DISCONNECTED
} connstate_t;

typedef struct {
    connstate_t state;
    int realtime;
    char autoupdateServerNames[5][MAX_QPATH];
} clientStatic_t;

typedef struct {
    qboolean fullyInitialized;
} cvar_t;

typedef struct {
    connstate_t state;
    qboolean oldGameSet;
} clientConnection_t;

extern clientStatic_t cls;
extern clientConnection_t clc;
extern cvar_t *com_fullyInitialized;
extern cvar_t *cl_noprint;
extern cvar_t *cl_motd;
extern cvar_t *cl_autoupdate;
extern cvar_t *cl_timeout;
extern cvar_t *cl_wavefilerecord;
extern cvar_t *cl_timeNudge;
extern cvar_t *cl_shownet;
extern cvar_t *cl_shownuments;
extern cvar_t *cl_visibleClients;
extern cvar_t *cl_showServerCommands;
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
extern cvar_t *cl_avidemo;
extern cvar_t *cl_forceavidemo;
extern cvar_t *rconAddress;
extern cvar_t *cl_yawspeed;
extern cvar_t *cl_pitchspeed;
extern cvar_t *cl_anglespeedkey;
extern cvar_t *cl_maxpackets;
extern cvar_t *cl_packetdup;
extern cvar_t *cl_showPing;
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
extern cvar_t *cl_recoilPitch;
extern cvar_t *cl_bypassMouseInput;
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
extern cvar_t *cl_language;
extern cvar_t *cl_debugTranslation;
extern cvar_t *cl_updateavailable;
extern cvar_t *cl_updatefiles;
extern cvar_t *cl_guid;
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
extern cvar_t *cl_missionStats;
extern cvar_t *cl_waitForFire;
extern cvar_t *cl_lanForcePackets;

#define CVAR_ARCHIVE 1
#define CVAR_TEMP 2
#define CVAR_ROM 4
#define CVAR_USERINFO 8
#define CVAR_LATCH 16

#define DEFAULT_CURL_LIB "libcurl.so"

#define AUTOUPDATE_SERVER1_NAME "update1.quake3arena.com"
#define AUTOUPDATE_SERVER2_NAME "update2.quake3arena.com"
#define AUTOUPDATE_SERVER3_NAME "update3.quake3arena.com"
#define AUTOUPDATE_SERVER4_NAME "update4.quake3arena.com"
#define AUTOUPDATE_SERVER5_NAME "update5.quake3arena.com"

qboolean autoupdateChecked;
qboolean autoupdateStarted;
qboolean cl_oldGameSet;

void Com_Printf(const char *fmt, ...);
void Con_Init(void);
void CL_ClearState(void);
void CL_InitInput(void);
cvar_t *Cvar_Get(const char *var_name, const char *var_value, int flags);
void Cvar_CheckRange(cvar_t *var, float min, float max, qboolean integral);
void Cvar_Set(const char *var_name, const char *value);
void Cmd_AddCommand(const char *cmd_name, void (*function)(void));
void Cmd_SetCommandCompletionFunc(const char *cmd_name, void (*complete)(void));
void CL_InitRef(void);
void SCR_Init(void);
void SCR_UpdateScreen(void);
void CL_GenerateQKey(void);
void CL_UpdateGUID(const char *p, int len);
void CL_InitTranslation(void);
void Q_strncpyz(char *dest, const char *src, int destsize);

void CL_ForwardToServer_f(void);
void CL_Configstrings_f(void);
void CL_Clientinfo_f(void);
void CL_Snd_Restart_f(void);
void CL_Vid_Restart_f(void);
void CL_UI_Restart_f(void);
void CL_Disconnect_f(void);
void CL_Record_f(void);
void CL_PlayDemo_f(void);
void CL_CompleteDemoName(void);
void CL_PlayCinematic_f(void);
void CL_StopRecord_f(void);
void CL_Connect_f(void);
void CL_Reconnect_f(void);
void CL_LocalServers_f(void);
void CL_GlobalServers_f(void);
void CL_Rcon_f(void);
void CL_CompleteRcon(void);
void CL_Ping_f(void);
void CL_ServerStatus_f(void);
void CL_ShowIP_f(void);
void CL_OpenedPK3List_f(void);
void CL_ReferencedPK3List_f(void);
void CL_Video_f(void);
void CL_StopVideo_f(void);
void CL_Cache_StartGather_f(void);
void CL_Cache_UsedFile_f(void);
void CL_Cache_SetIndex_f(void);
void CL_Cache_MapChange_f(void);
void CL_Cache_EndGather_f(void);
void CL_UpdateLevelHunkUsage(void);
void CL_SaveTranslations_f(void);
void CL_SaveNewTranslations_f(void);
void CL_LoadTranslations_f(void);
void CL_startSingleplayer_f(void);
void CL_SetRecommended_f(void);