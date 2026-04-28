#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;

#define GF_EXPORT
#define GF_TRUE 1

typedef struct GF_List GF_List;
typedef struct GF_BitStream GF_BitStream;

typedef struct {
    GF_List *header_obus;
    GF_List *frame_obus;
    Bool is_first_frame;
} AV1StateFrame;

typedef struct {
    void *obu;
} GF_AV1_OBUArrayEntry;

typedef struct AV1State {
    AV1StateFrame frame_state;
    GF_BitStream *bs;
    void *frame_obus;
    u32 frame_obus_alloc;
} AV1State;