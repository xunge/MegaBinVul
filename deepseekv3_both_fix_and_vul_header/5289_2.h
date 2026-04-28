#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct SVG_SAFExternalStream SVG_SAFExternalStream;
typedef struct GF_SVG_Parser GF_SVG_Parser;

struct SVG_SAFExternalStream {
    u32 id;
    SVG_SAFExternalStream *next;
};

struct GF_SVG_Parser {
    SVG_SAFExternalStream *streams;
};

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))