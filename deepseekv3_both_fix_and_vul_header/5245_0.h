#include <stdlib.h>

struct CDataFileHeader
{
    int m_NumRawData;
};

struct CDataFile
{
    CDataFileHeader m_Header;
    void** m_ppDataPtrs;
};

class CDataFileReader
{
public:
    CDataFile* m_pDataFile;
    void UnloadData(int Index);
};

static inline void mem_free(void* ptr) { free(ptr); }