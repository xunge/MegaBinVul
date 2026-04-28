#include <stdlib.h>

struct CDataFileHeader
{
    int m_NumRawData;
};

struct CDataFile
{
    CDataFileHeader m_Header;
    char **m_ppDataPtrs;
};

class CDataFileReader
{
private:
    CDataFile *m_pDataFile;
    void GetDataImpl(int Index, int Flags);
    void UnloadData(int Index);
public:
    void ReplaceData(int Index, char *pData);
};