#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint64_t uint64;

struct PasswordType {
    bool IsSet() const { return false; }
};

struct RAROptions {
    PasswordType Password;
    RAROptions* GetRAROptions();
};

struct SubHeadType {
    bool Encrypted;
    bool CmpName(const char* name) { return strcmp(name, "QOPEN") == 0; }
    uint64_t UnpSize;
    uint8_t Salt[8];
    uint8_t InitV[16];
    uint32_t Lg2Count;
    uint8_t HashKey[32];
    uint16_t PswCheck;
};

struct CryptType {
    void SetCryptKeys(bool, int, const PasswordType*, const uint8_t*, const uint8_t*, uint32_t, const uint8_t*, uint16_t);
};

struct ArcType {
    uint64_t Tell();
    void Seek(uint64_t, int);
    void SetProhibitQOpen(bool);
    size_t ReadHeader();
    int GetHeaderType();
    SubHeadType SubHead;
    uint64_t CurBlockPos;
    RAROptions* GetRAROptions();
};

struct SaveFilePos {
    SaveFilePos(ArcType& arc) {}
};

struct QuickOpen {
    bool Loaded;
    uint64_t SeekPos;
    bool UnsyncSeekPos;
    uint64_t QLHeaderPos;
    uint64_t RawDataStart;
    uint64_t RawDataSize;
    uint64_t RawDataPos;
    size_t ReadBufSize;
    size_t ReadBufPos;
    struct {
        void Reset();
    } LastReadHeader;
    uint64_t LastReadHeaderPos;
    ArcType* Arc;
    CryptType Crypt;
    void ReadBuffer();
    void Load(uint64 BlockPos);
};

enum {
    HEAD_SERVICE,
    CRYPT_RAR50,
    SEEK_SET
};

#define SUBHEAD_TYPE_QOPEN "QOPEN"