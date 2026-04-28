#include <stdbool.h>

typedef struct RTSP_MESSAGE {
    int dummy;  // 占位成员，实际使用时需要替换为真实结构体成员
} RTSP_MESSAGE;
typedef RTSP_MESSAGE* PRTSP_MESSAGE;

extern bool hasSessionId;
extern char sessionIdString[];
extern int AppVersionQuad[4];
extern int ServerMajorVersion;

int initializeRtspRequest(RTSP_MESSAGE* request, const char* method, const char* target);
bool addOption(RTSP_MESSAGE* request, const char* name, const char* value);
int transactRtspMessage(RTSP_MESSAGE* request, PRTSP_MESSAGE response, int flags, int* error);
void freeMessage(RTSP_MESSAGE* message);