#include <stdint.h>
#include <stdbool.h>
#include <string.h>

enum {
    IOFLAG_READ = 1,
    IOSEEK_START = 0,
    DEBUG = 0
};

typedef int IOHANDLE;
typedef int64_t int64;

struct CDatafile;
struct CDatafileHeader;
struct CDatafileItemType;
struct CDatafileInfo;

class IStorage {
public:
    IOHANDLE OpenFile(const char* pFilename, int flags, int StorageType);
};

class CDataFileReader {
public:
    bool Open(IStorage* pStorage, const char* pFilename, int StorageType);
    void Close();
    CDatafile* m_pDataFile;
};

struct SHA256_CTX {
    // SHA256 context structure
};
void sha256_init(SHA256_CTX* ctx);
void sha256_update(SHA256_CTX* ctx, const unsigned char* data, size_t len);
unsigned char* sha256_finish(SHA256_CTX* ctx);

struct CDatafileHeader {
    char m_aID[4];
    int m_Version;
    int m_Swaplen;
    int m_NumItemTypes;
    int m_NumItems;
    int m_NumRawData;
    int m_ItemSize;
};

struct CDatafileItemType {
    int type;
    int start;
    int num;
};

struct CDatafileInfo {
    CDatafileItemType* m_pItemTypes;
    int* m_pItemOffsets;
    int* m_pDataOffsets;
    int* m_pDataSizes;
    char* m_pItemStart;
    char* m_pDataStart;
};

struct CDatafile {
    CDatafileHeader m_Header;
    int64 m_DataStartOffset;
    char** m_ppDataPtrs;
    char* m_pData;
    IOHANDLE m_File;
    unsigned char* m_Sha256;
    unsigned m_Crc;
    CDatafileInfo m_Info;
};

void dbg_msg(const char* sys, const char* fmt, ...);
void* mem_alloc(int64 size, int alignment);
void mem_free(void* ptr);
void mem_zero(void* ptr, size_t size);
unsigned io_read(IOHANDLE file, void* buffer, unsigned size);
void io_seek(IOHANDLE file, int offset, int origin);
void io_close(IOHANDLE file);
void swap_endian(void* data, int elem_size, int num_elems);
unsigned crc32(unsigned crc, const unsigned char* buf, unsigned len);