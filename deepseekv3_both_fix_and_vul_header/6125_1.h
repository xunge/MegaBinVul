#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

typedef enum {
    ITUNES_STYLE,
    THIRD_GEN_PARTNER,
    THIRD_GEN_PARTNER_VER1_REL6,
    THIRD_GEN_PARTNER_VER1_REL7,
    THIRD_GEN_PARTNER_VER2,
    THIRD_GEN_PARTNER_VER2_REL_A
} MetadataStyle;

extern MetadataStyle metadata_style;
extern FILE* APar_OpenISOBaseMediaFile(char* filepath, bool read);
extern uint32_t APar_read32(char* buffer, FILE* file, size_t offset);
extern void APar_readX(char* buffer, FILE* file, size_t offset, size_t length);
extern uint32_t UInt32FromBigEndian(char* buffer);
extern void printBOM();
extern void APar_IdentifyBrand(char* brand);
extern void APar_ScanAtoms(char* filepath);