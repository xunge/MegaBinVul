#include <cstdint>
#include <map>
#include <vector>

typedef int64_t XMP_Int64;
typedef uint32_t XMP_OptionBits;

enum ChunkType {
    chunk_VALUE
};

class XMP_IO {
public:
    XMP_Int64 Offset();
    void Seek(XMP_Int64 offset, int mode);
};

class XIO {
public:
    static uint32_t ReadUns32_LE(XMP_IO* file);
};

class ValueChunk;

class ContainerChunk {
public:
    std::vector<class Chunk*> children;
    std::map<uint32_t, ValueChunk*> childmap;
    XMP_Int64 oldPos;
    XMP_Int64 oldSize;
};

class RIFF_MetaHandler {
public:
    XMP_Int64 oldFileSize;
    struct {
        XMP_IO* ioRef;
        XMP_OptionBits openFlags;
    }* parent;
};

class Chunk {
public:
    Chunk(ContainerChunk* parent, RIFF_MetaHandler* handler, bool skip, ChunkType c);
    ChunkType chunkType;
    ContainerChunk* parent;
    XMP_Int64 oldPos;
    XMP_Int64 oldSize;
    XMP_Int64 newSize;
    uint32_t id;
    bool hasChange;
    bool needSizeFix;
};

#define kXMPFiles_OpenForUpdate 0
#define kXMPFiles_OpenRepairFile 0
#define kXMP_SeekFromCurrent 0
#define kXMPErr_BadFileFormat 0

#define XMP_OptionIsSet(options, flag) ((options) & (flag))

void XMP_Throw(const char* message, int code);