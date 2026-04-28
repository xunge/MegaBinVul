#include <stdint.h>
#include <stddef.h>

typedef struct CDrcChannelData {
    int drcDataType;
    int bandTop[1];
} CDrcChannelData;

typedef struct CDrcPayload {
    CDrcChannelData channelData;
    int pceInstanceTag;
    int excludedChnsMask;
    int progRefLevel;
    int presMode;
} CDrcPayload;

typedef struct CDrcParams {
    int targetRefLevel;
    int expiryFrame;
    int applyHeavyCompression;
} CDrcParams;

typedef struct AAC_DRC {
    CDrcParams params;
    int numThreads;
    int numPayloads;
    int drcPayloadPosition[1];
    int dvbAncDataAvailable;
    int dvbAncDataPosition;
    int progRefLevel;
    int progRefLevelPresent;
    int prlExpiryCount;
    int presMode;
} AAC_DRC;

typedef struct CAacDecoderStaticChannelInfo {
    CDrcChannelData drcData;
} CAacDecoderStaticChannelInfo;

typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef int INT;

#define MAX_DRC_THREADS 1

typedef enum {
    MPEG_DRC_EXT_DATA,
    DVB_DRC_ANC_DATA
} AACDEC_DRC_PAYLOAD_TYPE;

typedef AAC_DRC* HANDLE_AAC_DRC;
typedef void* HANDLE_FDK_BITSTREAM;

void FDK_ASSERT(int);
unsigned int FDKgetValidBits(HANDLE_FDK_BITSTREAM);
void FDKmemclear(void*, unsigned int);
void FDKpushBiDirectional(HANDLE_FDK_BITSTREAM, int);
int aacDecoder_drcParse(HANDLE_FDK_BITSTREAM, CDrcPayload*, int);
int aacDecoder_drcReadCompression(HANDLE_FDK_BITSTREAM, CDrcPayload*, int);