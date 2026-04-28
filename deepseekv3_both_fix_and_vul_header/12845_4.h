#include <stdint.h>

typedef int64_t int64;

struct QOpenType {
    bool Tell(int64* pos);
};

struct ArcMemType {
    bool Tell(int64* pos);
};

class File {
public:
    static int64 Tell();
};

class Archive {
private:
    QOpenType QOpen;
    ArcMemType ArcMem;
public:
    int64 Tell();
};