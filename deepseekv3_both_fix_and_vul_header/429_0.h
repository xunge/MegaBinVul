#include <stdint.h>

#define SCEnter()
#define SCLogDebug(...)
#define SCReturnUInt(x) (x)

typedef uint32_t AppProto;
#define ALPROTO_UNKNOWN 0
#define ALPROTO_MAX 256
#define ALPROTO_DCERPC 1

typedef struct AppLayerProtoDetectThreadCtx AppLayerProtoDetectThreadCtx;
typedef struct Flow Flow;

#define FLOW_IS_PM_DONE(f, dir) 0
#define FLOW_IS_PP_DONE(f, dir) 0
#define FLOW_IS_PE_DONE(f, dir) 0

#define STREAM_TOSERVER 0
#define IPPROTO_UDP 17

uint16_t AppLayerProtoDetectPMGetProto(AppLayerProtoDetectThreadCtx *tctx, Flow *f,
                                      uint8_t *buf, uint32_t buflen,
                                      uint8_t direction, uint8_t ipproto,
                                      AppProto *results);
AppProto AppLayerProtoDetectPPGetProto(Flow *f, uint8_t *buf, uint32_t buflen,
                                      uint8_t ipproto, uint8_t direction);
AppProto AppLayerProtoDetectPEGetProto(Flow *f, uint8_t ipproto, uint8_t direction);