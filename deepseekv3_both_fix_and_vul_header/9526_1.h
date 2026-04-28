#include <stdint.h>

typedef struct bfd bfd;

struct internal_extra_pe_aouthdr {
    uint16_t Magic;
    uint8_t MajorLinkerVersion;
    uint8_t MinorLinkerVersion;
    uint32_t SizeOfCode;
    uint32_t SizeOfInitializedData;
    uint32_t SizeOfUninitializedData;
    uint32_t AddressOfEntryPoint;
    uint32_t BaseOfCode;
    uint32_t BaseOfData;
    uint64_t ImageBase;
    uint32_t SectionAlignment;
    uint32_t FileAlignment;
    uint16_t MajorOperatingSystemVersion;
    uint16_t MinorOperatingSystemVersion;
    uint16_t MajorImageVersion;
    uint16_t MinorImageVersion;
    uint16_t MajorSubsystemVersion;
    uint16_t MinorSubsystemVersion;
    uint32_t Reserved1;
    uint32_t SizeOfImage;
    uint32_t SizeOfHeaders;
    uint32_t CheckSum;
    uint16_t Subsystem;
    uint16_t DllCharacteristics;
    uint64_t SizeOfStackReserve;
    uint64_t SizeOfStackCommit;
    uint64_t SizeOfHeapReserve;
    uint64_t SizeOfHeapCommit;
    uint32_t LoaderFlags;
    uint32_t NumberOfRvaAndSizes;
    struct {
        uint32_t VirtualAddress;
        uint32_t Size;
    } DataDirectory[16];
};

struct internal_aouthdr {
    uint16_t magic;
    uint16_t vstamp;
    uint32_t tsize;
    uint32_t dsize;
    uint32_t bsize;
    uint32_t entry;
    uint32_t text_start;
    uint32_t data_start;
    struct internal_extra_pe_aouthdr pe;
};

typedef struct {
    uint16_t magic;
    uint16_t vstamp;
    uint32_t tsize;
    uint32_t dsize;
    uint32_t bsize;
    uint32_t entry;
    uint32_t text_start;
    uint32_t data_start;
} AOUTHDR;

typedef struct {
    uint64_t ImageBase;
    uint32_t SectionAlignment;
    uint32_t FileAlignment;
    uint16_t MajorOperatingSystemVersion;
    uint16_t MinorOperatingSystemVersion;
    uint16_t MajorImageVersion;
    uint16_t MinorImageVersion;
    uint16_t MajorSubsystemVersion;
    uint16_t MinorSubsystemVersion;
    uint32_t Reserved1;
    uint32_t SizeOfImage;
    uint32_t SizeOfHeaders;
    uint32_t CheckSum;
    uint16_t Subsystem;
    uint16_t DllCharacteristics;
    uint64_t SizeOfStackReserve;
    uint64_t SizeOfStackCommit;
    uint64_t SizeOfHeapReserve;
    uint64_t SizeOfHeapCommit;
    uint32_t LoaderFlags;
    uint32_t NumberOfRvaAndSizes;
    uint32_t DataDirectory[16][2];
} PEAOUTHDR;

#define H_GET_16(abfd, val) (val)
#define H_GET_8(abfd, val) (val)
#define H_GET_32(abfd, val) (val)
#define GET_AOUTHDR_TSIZE(abfd, val) (val)
#define GET_AOUTHDR_DSIZE(abfd, val) (val)
#define GET_AOUTHDR_BSIZE(abfd, val) (val)
#define GET_AOUTHDR_ENTRY(abfd, val) (val)
#define GET_AOUTHDR_TEXT_START(abfd, val) (val)
#define GET_AOUTHDR_DATA_START(abfd, val) (val)
#define GET_OPTHDR_IMAGE_BASE(abfd, val) (val)
#define GET_OPTHDR_SIZE_OF_STACK_RESERVE(abfd, val) (val)
#define GET_OPTHDR_SIZE_OF_STACK_COMMIT(abfd, val) (val)
#define GET_OPTHDR_SIZE_OF_HEAP_RESERVE(abfd, val) (val)
#define GET_OPTHDR_SIZE_OF_HEAP_COMMIT(abfd, val) (val)

extern void (*_bfd_error_handler)(const char *, ...);
extern const char *_(const char *);