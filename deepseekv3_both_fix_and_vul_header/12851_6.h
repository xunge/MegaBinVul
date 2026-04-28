#include <stdint.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <algorithm>

typedef uint8_t byte;
typedef uint32_t uint;
typedef int64_t int64;
typedef uint64_t uint64;
typedef wchar_t wchar;

#define ASIZE(x) (sizeof(x)/sizeof((x)[0]))
#define Min(a,b) std::min(a,b)

enum HEADER_TYPE { HEAD_MAIN, HEAD_FILE, HEAD_SERVICE };
enum { 
    MHEXTRA_LOCATOR, 
    MHEXTRA_LOCATOR_QLIST, 
    MHEXTRA_LOCATOR_RR,
    FHEXTRA_CRYPT,
    FHEXTRA_CRYPT_PSWCHECK,
    FHEXTRA_CRYPT_HASHMAC,
    FHEXTRA_HASH,
    FHEXTRA_HASH_BLAKE2,
    FHEXTRA_HTIME,
    FHEXTRA_HTIME_UNIXTIME,
    FHEXTRA_HTIME_MTIME,
    FHEXTRA_HTIME_CTIME,
    FHEXTRA_HTIME_ATIME,
    FHEXTRA_HTIME_UNIX_NS,
    FHEXTRA_VERSION,
    FHEXTRA_REDIR,
    FHEXTRA_REDIR_DIR,
    FHEXTRA_UOWNER,
    FHEXTRA_UOWNER_NUMUID,
    FHEXTRA_UOWNER_NUMGID,
    FHEXTRA_UOWNER_UNAME,
    FHEXTRA_UOWNER_GNAME,
    FHEXTRA_SUBDATA
};
enum HASH_TYPE { HASH_BLAKE2 };
enum FILE_SYSTEM_REDIRECT { /* appropriate values */ };
enum { 
    CRYPT_VERSION, 
    CRYPT5_KDF_LG2_COUNT_MAX, 
    CRYPT_RAR50,
    SIZE_SALT50 = 16,
    SIZE_INITV = 16,
    SIZE_PSWCHECK = 8,
    SIZE_PSWCHECK_CSUM = 4,
    SHA256_DIGEST_SIZE = 32,
    BLAKE2_DIGEST_SIZE = 32,
    NM = 1024
};

struct BaseBlock {
    HEADER_TYPE HeaderType;
};

struct MainHeader : public BaseBlock {
    bool Locator;
    uint64_t QOpenOffset;
    uint64_t RROffset;
};

struct FileHeader : public BaseBlock {
    wchar_t FileName[NM];
    bool UsePswCheck;
    bool UseHashKey;
    uint8_t Lg2Count;
    byte Salt[SIZE_SALT50];
    byte InitV[SIZE_INITV];
    byte PswCheck[SIZE_PSWCHECK];
    bool SaltSet;
    uint8_t CryptMethod;
    bool Encrypted;
    struct {
        HASH_TYPE Type;
        byte Digest[BLAKE2_DIGEST_SIZE];
    } FileHash;
    struct {
        void SetUnix(time_t);
        void SetWin(uint64_t);
        void Adjust(uint);
    } mtime, ctime, atime;
    bool Version;
    FILE_SYSTEM_REDIRECT RedirType;
    bool DirTarget;
    wchar_t RedirName[NM];
    bool UnixOwnerNumeric;
    bool UnixGroupNumeric;
    char UnixOwnerName[NM];
    char UnixGroupName[NM];
    uint32_t UnixOwnerID;
    uint32_t UnixGroupID;
    bool UnixOwnerSet;
    struct {
        void Alloc(size_t);
        byte *Addr(size_t);
    } SubData;
};

struct FileHead {
    wchar_t FileName[NM];
};

struct RawRead {
    void GetB(void*, size_t);
    uint8_t Get1();
    uint32_t Get4();
    uint64_t Get8();
    size_t GetPos();
    void SetPos(size_t);
    size_t DataLeft();
    size_t Size();
    uint64_t GetV();
};

struct sha256_context {
    void (*init)(sha256_context*);
    void (*process)(sha256_context*, const byte*, size_t);
    void (*done)(sha256_context*, byte*);
};

struct Archive {
    void ProcessExtra50(RawRead *Raw, size_t ExtraSize, BaseBlock *bb);
};

extern uint64_t CurBlockPos;
extern FileHead FileHead;
extern void UnkEncVerMsg(const wchar_t*);
extern void UnixSlashToDos(const char*, char*, size_t);
extern void UtfToWide(const char*, wchar_t*, size_t);
extern void sha256_init(sha256_context*);
extern void sha256_process(sha256_context*, const byte*, size_t);
extern void sha256_done(sha256_context*, byte*);
extern int swprintf(wchar_t*, size_t, const wchar_t*, ...);
extern void wcsncatz(wchar_t*, const wchar_t*, size_t);