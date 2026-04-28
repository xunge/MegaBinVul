#include <stdlib.h>

extern int stopping;
extern int idrFrameRequired;
extern int lastGoodFrame;
extern int lastSeenFrame;
extern int lossCountSinceLastReport;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern short* packetTypes;
extern short* payloadLengths;
extern char** preconstructedPayloads;
extern short packetTypesGen3[];
extern short payloadLengthsGen3[];
extern char* preconstructedPayloadsGen3[];
extern short packetTypesGen4[];
extern short payloadLengthsGen4[];
extern char* preconstructedPayloadsGen4[];
extern short packetTypesGen5[];
extern short payloadLengthsGen5[];
extern char* preconstructedPayloadsGen5[];
extern short packetTypesGen7[];
extern short payloadLengthsGen7[];
extern char* preconstructedPayloadsGen7[];

typedef struct {
    void* event;
} PltEvent;

typedef struct {
    void* queue;
} LbqLinkedBlockingQueue;

extern PltEvent invalidateRefFramesEvent;
extern LbqLinkedBlockingQueue invalidReferenceFrameTuples;

void PltCreateEvent(PltEvent* event);
void LbqInitializeLinkedBlockingQueue(LbqLinkedBlockingQueue* queue, int capacity);