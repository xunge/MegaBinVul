#include <stdlib.h>
#include <string.h>

typedef unsigned char Bytef;

typedef struct
{
    int m_Version;
    int m_NumRawData;
} CDataFileHeader;

typedef struct
{
    unsigned long *m_pDataSizes;
    unsigned long *m_pDataOffsets;
} CDataFileInfo;

typedef struct
{
    CDataFileHeader m_Header;
    CDataFileInfo m_Info;
    char **m_ppDataPtrs;
    void *m_File;
    unsigned long m_DataStartOffset;
} CDataFile;

class CDataFileReader
{
public:
    CDataFile* m_pDataFile;
    int GetDataSize(int Index);
    void* GetDataImpl(int Index, int Swap);
};

extern void *mem_alloc(size_t size, int alignment);
extern void mem_free(void *ptr);
extern void dbg_msg(const char *sys, const char *fmt, ...);
extern void io_seek(void *file, unsigned long offset, int origin);
extern int io_read(void *file, void *buffer, int size);
extern void swap_endian(void *data, int elem_size, int num_elems);
extern int uncompress(Bytef *dest, unsigned long *destLen, const Bytef *source, unsigned long sourceLen);

#define CONF_ARCH_ENDIAN_BIG
#define IOSEEK_START 0