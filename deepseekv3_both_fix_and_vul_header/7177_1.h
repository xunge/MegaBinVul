#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {qfalse, qtrue} qboolean;

#define MAX_QPATH 64
#define MAX_SCRIPT_EVENTS 128
#define AICAST_MAX_SCRIPT_STACK_ITEMS 32
#define AIFL_CORPSESIGHTING (1 << 0)

typedef struct {
    int entityNum;
    int aiFlags;
    int numCastScriptEvents;
    struct cast_script_event_t *castScriptEvents;
    struct {
        int castScriptEventIndex;
    } castScriptStatus;
} cast_state_t;

typedef struct {
    char *aiName;
} gentity_t;

typedef struct {
    char *scriptAI;
    char nextMap[MAX_QPATH];
} level_locals_t;

typedef struct {
    char *actionString;
} cast_script_stack_action_t;

typedef struct {
    int eventNum;
    char *params;
    struct {
        int numItems;
        struct {
            cast_script_stack_action_t *action;
            char *params;
        } items[AICAST_MAX_SCRIPT_STACK_ITEMS];
    } stack;
} cast_script_event_t;

typedef struct gitem_s {
    // item definition fields
} gitem_t;

extern level_locals_t level;
extern gentity_t g_entities[];
extern cast_script_event_t cast_temp_events[MAX_SCRIPT_EVENTS];
extern const char *animStateStr[];

extern void COM_BeginParseSession(const char *);
extern char *COM_Parse(char **);
extern char *COM_ParseExt(char **, qboolean);
extern int COM_GetCurrentParseLine(void);
extern void G_Error(const char *, ...);
extern int Q_strcasecmp(const char *, const char *);
extern int Q_stricmp(const char *, const char *);
extern void Q_strcat(char *, int, const char *);
extern void Q_strncpyz(char *, const char *, int);
extern void *G_Alloc(int);
extern void trap_SendServerCommand(int, const char *);
extern void trap_Cvar_Set(const char *, const char *);
extern void G_SoundIndex(const char *);
extern int AICast_EventForString(const char *);
extern cast_script_stack_action_t *AICast_ActionForString(cast_state_t *, const char *);
extern void AICast_CheckLevelAttributes(cast_state_t *, gentity_t *, char **);
extern int BG_IndexForString(const char *, const char **, qboolean);
extern gitem_t *BG_FindItem2(const char *);
extern void RegisterItem(gitem_t *);
extern char *va(const char *fmt, ...);