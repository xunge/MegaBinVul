#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

typedef enum {
    RIL_SOCKET_1,
    RIL_SOCKET_2,
    RIL_SOCKET_3,
    RIL_SOCKET_4
} RIL_SOCKET_ID;

typedef struct {
    int fdCommand;
} RIL_Socket;

typedef struct {
    int clir;
    char* address;
} RIL_Dial;

#define SIM_COUNT 1
#define RLOGI(...)
#define RLOGE(...)
#define RIL_UNSOL_RESPONSE(x, y, z, w)
#define RIL_REQUEST_RESET_RADIO 0
#define RIL_REQUEST_RADIO_POWER 0
#define RIL_REQUEST_OEM_HOOK_RAW 0
#define RIL_REQUEST_SET_NETWORK_SELECTION_AUTOMATIC 0
#define RIL_REQUEST_SETUP_DATA_CALL 0
#define RIL_REQUEST_DEACTIVATE_DATA_CALL 0
#define RIL_REQUEST_DIAL 0
#define RIL_REQUEST_ANSWER 0
#define RIL_REQUEST_HANGUP 0
#define RIL_UNSOL_RESPONSE_VOICE_NETWORK_STATE_CHANGED 0

static RIL_Socket s_ril_param_socket;
#if (SIM_COUNT >= 2)
static RIL_Socket s_ril_param_socket2;
#endif

static const char* rilSocketIdToString(RIL_SOCKET_ID socket_id) { return ""; }
static void freeDebugCallbackArgs(int i, char** args) {}
static void issueLocalRequest(int request, void* data, size_t len, RIL_SOCKET_ID socket_id) {}