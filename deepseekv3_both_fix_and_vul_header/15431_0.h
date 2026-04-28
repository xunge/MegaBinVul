#include <stdint.h>

extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern long long lastSeenFrame;
extern int IDX_INVALIDATE_REF_FRAMES;
extern int IDX_REQUEST_IDR_FRAME;
extern int* packetTypes;
extern int* payloadLengths;
extern long long** preconstructedPayloads;
extern int LastSocketError(void);
extern int sendMessageAndDiscardReply(int, int, long long*);
extern void Limelog(const char*, ...);

struct {
    void (*connectionTerminated)(int);
} ListenerCallbacks;