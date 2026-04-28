#include <stddef.h>
#include <stdint.h>

extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern void* enetMutex;

int sendMessageEnet(short ptype, short paylen, const void* payload);
int sendMessageTcp(short ptype, short paylen, const void* payload);

void PltLockMutex(void* mutex);
void PltUnlockMutex(void* mutex);