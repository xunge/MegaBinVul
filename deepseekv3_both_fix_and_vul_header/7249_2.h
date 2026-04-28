#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t PE_DWord;
typedef uint64_t ut64;
typedef uint8_t ut8;

#define MAX_METADATA_STRING_LENGTH 32
#define PFMT64x "llx"

typedef struct {
    uint32_t Signature;
    uint16_t MajorVersion;
    uint16_t MinorVersion;
    uint32_t Reserved;
    uint32_t VersionStringLength;
    char* VersionString;
    uint16_t Flags;
    uint16_t NumberOfStreams;
} PE_image_metadata_header;

typedef struct {
    uint32_t Offset;
    uint32_t Size;
    char* Name;
} PE_image_metadata_stream;

typedef struct {
    uint32_t MetaDataDirectoryAddress;
} PE_image_clr_header;

typedef struct RBinPEObj {
    void* b;
    bool big_endian;
    PE_image_clr_header* clr_hdr;
    PE_image_metadata_header* metadata_header;
    PE_image_metadata_stream** streams;
} RBinPEObj;

#define R_NEW0(x) calloc(1, sizeof(x))
#define PE_(x) PE_##x