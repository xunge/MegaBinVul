#include <stdbool.h>

typedef enum {
    JSNETWORKTYPE_CC3000,
    JSNETWORKTYPE_W5500,
    JSNETWORKTYPE_ESP8266_BOARD,
    JSNETWORKTYPE_ESP32,
    JSNETWORKTYPE_SOCKET,
    JSNETWORKTYPE_JS
} JsNetworkType;

typedef enum {
    JSET_INTERNALERROR
} JsExceptionType;

typedef struct JsNetworkData {
    JsNetworkType type;
    int recvBufferSize;
} JsNetworkData;

typedef struct JsNetwork {
    void *networkVar;
    JsNetworkData data;
    int chunkSize;
} JsNetwork;

typedef struct ExecInfo {
    void *hiddenRoot;
} ExecInfo;

extern ExecInfo execInfo;
extern JsNetwork *networkCurrentStruct;
extern const char *NETWORK_VAR_NAME;

void networkCreate(JsNetwork *net, JsNetworkType type);
void networkFree(JsNetwork *net);
void jsExceptionHere(JsExceptionType errorType, const char *format, ...);
void netSetCallbacks_cc3000(JsNetwork *net);
void netSetCallbacks_wiznet(JsNetwork *net);
void netSetCallbacks_esp8266_board(JsNetwork *net);
void netSetCallbacks_esp32(JsNetwork *net);
void netSetCallbacks_linux(JsNetwork *net);
void netSetCallbacks_js(JsNetwork *net);
void *jsvObjectGetChild(ExecInfo *execInfo, const char *name, int flags);
void jsvGetString(void *var, char *buf, int bufSize);