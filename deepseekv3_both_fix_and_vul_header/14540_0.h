#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int size;
    uint8_t value[16];
} PresentationSelector;

typedef struct {
    PresentationSelector calledPresentationSelector;
    PresentationSelector callingPresentationSelector;
    struct {
        int size;
    } nextPayload;
} IsoPresentation;

extern int DEBUG_PRES;
extern int BerDecoder_decodeLength(uint8_t* buffer, int* len, int bufPos, int endPos);
extern int parsePresentationContextDefinitionList(IsoPresentation* self, uint8_t* buffer, int len, int bufPos);
extern int parseFullyEncodedData(IsoPresentation* self, uint8_t* buffer, int len, int bufPos);