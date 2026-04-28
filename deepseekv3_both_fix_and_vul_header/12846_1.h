#include <cstring>
#include <new>

#define RARFMT15 15

struct RAROptions {
    bool OpenShared;
};

struct RARHeaderData {
    // Add necessary members if any
};

struct RARHeaderDataEx {
    // Add necessary members if any
};

struct RAROpenArchiveDataEx {
    // Add necessary members if any
};

class Time {
public:
    void Reset() {}
};

class Archive {
private:
    RAROptions *Cmd;
    bool DummyCmd;
    bool OpenShared;
    int Format;
    bool Solid;
    bool Volume;
    bool MainComment;
    bool Locked;
    bool Signed;
    bool FirstVolume;
    bool NewNumbering;
    unsigned int SFXSize;
    Time LatestTime;
    bool Protected;
    bool Encrypted;
    bool FailedHeaderDecryption;
    bool BrokenHeader;
    unsigned int LastReadBlock;
    unsigned int CurBlockPos;
    unsigned int NextBlockPos;
    int RecoverySize;
    int RecoveryPercent;
    RARHeaderData MainHead;
    RARHeaderData CryptHead;
    RARHeaderData EndArcHead;
    unsigned int VolNumber;
    unsigned int VolWrite;
    unsigned int AddingFilesSize;
    unsigned int AddingHeadersSize;
    char FirstVolumeName[260];
    bool Splitting;
    bool NewArchive;
    bool SilentOpen;
public:
    Archive(RAROptions *InitCmd);
};