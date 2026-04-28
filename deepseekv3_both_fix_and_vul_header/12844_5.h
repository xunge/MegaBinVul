#include <cstdint>

using int64 = int64_t;

class QOpenType {
public:
    bool Seek(int64_t Offset, int Method);
};

class File {
public:
    static void Seek(int64_t Offset, int Method);
};

class Archive {
public:
    QOpenType QOpen;
    void Seek(int64 Offset, int Method);
};