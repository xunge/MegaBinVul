#include <stdint.h>

typedef struct RTSP_MESSAGE *PRTSP_MESSAGE;
extern int transactRtspMessageEnet(PRTSP_MESSAGE, PRTSP_MESSAGE, int, int*);
extern int transactRtspMessageTcp(PRTSP_MESSAGE, PRTSP_MESSAGE, int, int*);
extern int ServerMajorVersion;
extern int AppVersionQuad[4];