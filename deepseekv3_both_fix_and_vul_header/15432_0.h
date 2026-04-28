#include <stdint.h>

#define LC_ASSERT(expr) ((void)0)

extern int ServerMajorVersion;
extern unsigned char* packetTypes[];
extern int sendMessageAndForget(uint8_t type, int length, unsigned char* data);

#define IDX_INPUT_DATA 0