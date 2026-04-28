#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef long ssize_t;
typedef long MagickOffsetType;
typedef unsigned char MagickBooleanType;
typedef unsigned long Quantum;
typedef size_t MagickSizeType;
typedef double MagickRealType;

#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0xabacadabUL
#define QuantumRange 65535UL
#define MAGICKCORE_QUANTUM_DEPTH 16
#define LSBEndian 0
#define MSBEndian 1
#define PseudoClass 1
#define DirectClass 2
#define OpaqueOpacity 0

enum {
    TraceEvent,
    CorruptImageError,
    ResourceLimitError,
    CoderError,
    LoadImageTag,
    LoadImagesTag
};

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
    unsigned long scene;
    unsigned long number_scenes;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
    struct _ExceptionInfo *exception;
} ExceptionInfo;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum opacity;
} PixelPacket;

typedef struct _IndexPacket {
    size_t index;
    struct _IndexPacket *next;
} IndexPacket;

typedef struct _ColormapEntry {
    Quantum red;
    Quantum green;
    Quantum blue;
} ColormapEntry;

typedef struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    unsigned long colors;
    MagickBooleanType matte;
    unsigned long storage_class;
    unsigned long endian;
    struct _Image *previous;
    struct _Image *next;
    unsigned long scene;
    char *filename;
    struct _ExceptionInfo exception;
    ColormapEntry *colormap;
} Image;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef struct _ViffInfo {
    unsigned char identifier;
    unsigned char file_type;
    unsigned char release;
    unsigned char version;
    unsigned char machine_dependency;
    unsigned char reserve[3];
    char comment[512];
    unsigned int rows;
    unsigned int columns;
    unsigned int subrows;
    int x_offset;
    int y_offset;
    float x_bits_per_pixel;
    float y_bits_per_pixel;
    unsigned int location_type;
    unsigned int location_dimension;
    unsigned int number_of_images;
    unsigned int number_data_bands;
    unsigned int data_storage_type;
    unsigned int data_encode_scheme;
    unsigned int map_scheme;
    unsigned int map_storage_type;
    unsigned int map_rows;
    unsigned int map_columns;
    unsigned int map_subrows;
    unsigned int map_enable;
    unsigned int maps_per_cycle;
    unsigned int color_space_model;
} ViffInfo;