#include <stdbool.h>
#include <stdio.h>

typedef struct IsoConnection* IsoConnection;

typedef enum {
    TPKT_ERROR,
    TPKT_PACKET_COMPLETE
} TpktState;

typedef enum {
    COTP_MORE_FRAGMENTS_FOLLOW,
    COTP_CONNECT_INDICATION,
    COTP_DATA_INDICATION,
    COTP_ERROR
} CotpIndication;

typedef enum {
    SESSION_CONNECT,
    SESSION_DATA,
    SESSION_FINISH,
    SESSION_ABORT,
    SESSION_ERROR
} IsoSessionIndication;

typedef enum {
    ACSE_ASSOCIATE,
    ACSE_RESULT_ACCEPT
} AcseIndication;

typedef enum {
    ISO_CON_STATE_STOPPED
} IsoConnectionState;

typedef struct {
    int size;
    unsigned char* buffer;
} ByteBuffer;

typedef struct sBufferChain {
    unsigned char* buffer;
    int partMaxLength;
    int length;
    struct sBufferChain* next;
} *BufferChain;

typedef struct {
    ByteBuffer nextPayload;
    int mmsContextId;
    int nextContextId;
} IsoPresentation;

typedef struct {
    unsigned char* userDataBuffer;
    int userDataBufferSize;
} AcseConnection;

typedef struct {
    IsoPresentation* presentation;
    AcseConnection* acseConnection;
    ByteBuffer* userData;
} IsoSession;

typedef struct IsoConnection {
    IsoSession* session;
    IsoPresentation* presentation;
    AcseConnection* acseConnection;
    void* handlerParameter;
    void (*tickHandler)(void*);
    void (*msgRcvdHandler)(void*, ByteBuffer*, ByteBuffer*);
    void* handleSet;
    unsigned char* sendBuffer;
    IsoConnectionState state;
    int cotpConnection;
} *IsoConnection;

#define CONFIG_MMS_SINGLE_THREADED 0
#define CONFIG_MMS_THREADLESS_STACK 0
#define DEBUG_ISO_SERVER 0
#define SEND_BUF_SIZE 1024

int Handleset_waitReady(void*, int);
void IsoConnection_lock(IsoConnection);
void IsoConnection_unlock(IsoConnection);
TpktState CotpConnection_readToTpktBuffer(int);
CotpIndication CotpConnection_parseIncomingMessage(int);
ByteBuffer* CotpConnection_getPayload(int);
void CotpConnection_resetPayload(int);
void CotpConnection_sendConnectionResponseMessage(int);
void CotpConnection_sendDataMessage(int, BufferChain);
bool IsoPresentation_parseConnect(IsoPresentation*, ByteBuffer*);
void IsoPresentation_createCpaMessage(IsoPresentation*, BufferChain, BufferChain);
bool IsoPresentation_parseUserData(IsoPresentation*, ByteBuffer*);
void IsoPresentation_createUserData(IsoPresentation*, BufferChain, BufferChain);
void IsoPresentation_createUserDataACSE(IsoPresentation*, BufferChain, BufferChain);
IsoSessionIndication IsoSession_parseMessage(IsoSession*, ByteBuffer*);
ByteBuffer* IsoSession_getUserData(IsoSession*);
void IsoSession_createAcceptSpdu(IsoSession*, BufferChain, BufferChain);
void IsoSession_createDataSpdu(IsoSession*, BufferChain, BufferChain);
void IsoSession_createDisconnectSpdu(IsoSession*, BufferChain, BufferChain);
AcseIndication AcseConnection_parseMessage(AcseConnection*, ByteBuffer*);
void AcseConnection_createAssociateResponseMessage(AcseConnection*, int, BufferChain, BufferChain);
void AcseConnection_createReleaseResponseMessage(AcseConnection*, BufferChain);
void ByteBuffer_wrap(ByteBuffer*, unsigned char*, int, int);
void BufferChain_init(BufferChain, int, int, void*, unsigned char*);