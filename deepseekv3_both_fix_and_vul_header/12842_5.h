#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <stdio.h>

#define SFX_MODULE
#define RARFMT14 0
#define SIZEOF_MAINHEAD14 0
#define SIZEOF_MARKHEAD3 0
#define SIZEOF_MAINHEAD3 0
#define SIZEOF_COMMHEAD 0
#define SUBHEAD_TYPE_CMT 0
#define VER_UNPACK 0
#define HASH_CRC32 0
#define RAR_NOCRYPT
#define SEEK_SET 0

typedef uint8_t byte;
typedef uint32_t uint;
typedef uint32_t DWORD;
typedef wchar_t wchar;

struct SaveFilePos {
    SaveFilePos(class Archive &arc) {}
};

template<typename T>
struct Array {
    T* Addr(size_t) { return nullptr; }
    void Alloc(size_t) {}
    size_t Size() { return 0; }
    void Push(T) {}
};

struct ComprDataIO {
    void SetTestMode(bool) {}
    void SetFiles(class Archive*, void*) {}
    void EnableShowProgress(bool) {}
    void SetPackedSizeToRead(uint) {}
    void SetNoFileHeader(bool) {}
    void SetCmt13Encryption() {}
    void GetUnpackedData(byte**, size_t*) {}
    struct UnpHash {
        void Init(int, int) {}
        uint32_t GetCRC32() { return 0; }
    } UnpHash;
};

struct Unpack {
    Unpack(ComprDataIO*) {}
    void Init(int, bool) {}
    void SetDestSize(uint) {}
    void DoUnpack(uint, bool) {}
};

struct Archive {
    bool MainComment;
    uint Format;
    uint SFXSize;
    bool BrokenHeader;
    wchar_t* FileName;
    struct MainHead {
        bool CommentInHeader;
        bool PackComment;
    } MainHead;
    struct CommHead {
        uint HeadSize;
        uint Method;
        uint UnpVer;
        uint UnpSize;
        uint CommCRC;
    } CommHead;
    
    void Seek(uint, int) {}
    uint GetByte() { return 0; }
    bool ReadHeader() { return false; }
    uint GetStartPos() { return 0; }
    bool SearchSubBlock(uint) { return false; }
    bool ReadCommentData(Array<wchar_t>*) { return false; }
    int Read(byte*, uint) { return 0; }
    void uiMsg(int, wchar_t*) {}
    bool GetComment(Array<wchar_t> *CmtData);
};

uint32_t CRC32(uint32_t, byte*, uint) { return 0; }
void CharToWide(const char*, wchar_t*, size_t) {}