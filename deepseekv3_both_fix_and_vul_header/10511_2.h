#include <stdint.h>
#include <string.h>

typedef enum {
    PV_FAIL,
    PV_SUCCESS,
    PV_END_OF_VOP
} PV_STATUS;

typedef enum {
    PV_FALSE,
    PV_TRUE
} Bool;

typedef int32_t int32;

#define BITRATE_AVERAGE_WINDOW 16
#define FRAMERATE_SCALE 1000

typedef enum {
    I_VOP,
    P_VOP,
    B_VOP
} VopType;

typedef struct Bitstream {
    uint8_t* data;
    int data_end_pos;
} Bitstream;

typedef struct Vop {
    int vopCoded;
    int predictionType;
    int refSelectCode;
    uint8_t* yChan;
    int timeStamp;
} Vop;

typedef struct Vol {
    Bitstream* bitstream;
} Vol;

typedef struct VideoDecData {
    int currLayer;
    Vol** vol;
    Vop* currVop;
    Vop* prevVop;
    Vop* prevEnhcVop;
    int frame_idx;
    int* nBitsPerVop;
    int* prevTimestamp;
    int duration;
    int frameRate;
    uint8_t* concealFrame;
    int vop_coding_type;
} VideoDecData;

typedef struct VideoDecControls {
    void* videoDecoderData;
    int nLayers;
    int size;
    uint8_t* outputFrame;
} VideoDecControls;

int getPointer(Bitstream *bs);
void PV_BitstreamByteAlign(Bitstream *bs);
PV_STATUS PV_DecodeVop(VideoDecData *video);
void mp4dec_log(const char* msg);
#define oscl_memcpy memcpy