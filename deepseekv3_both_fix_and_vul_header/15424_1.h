#include <stdint.h>

#define FLAG_CONTAINS_PIC_DATA 0x01
#define FLAG_EOF 0x02

typedef struct {
    char* data;
    int offset;
    int length;
} BUFFER_DESC;

typedef struct {
    int streamPacketIndex;
    int frameIndex;
    char flags;
} NV_VIDEO_PACKET;
typedef NV_VIDEO_PACKET* PNV_VIDEO_PACKET;

extern int lastPacketInStream;
extern int nextFrameNumber;
extern int decodingFrame;
extern int waitingForNextSuccessfulFrame;
extern int nominalPacketDataLength;
extern int waitingForIdrFrame;
extern int startFrameNumber;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;

int isFirstPacket(char flags);
int isBeforeSignedInt(short a, short b, int c);
void connectionSawFrame(int frameIndex);
void Limelog(const char* message);
void dropFrameState();
void connectionLostPackets(int last, int current);
void connectionDetectedFrameLoss(int start, int end);
int isIdrFrameStart(BUFFER_DESC* pos);
void processRtpPayloadSlow(PNV_VIDEO_PACKET packet, BUFFER_DESC* pos);
void processRtpPayloadFast(BUFFER_DESC pos);
void reassembleFrame(int frameIndex);