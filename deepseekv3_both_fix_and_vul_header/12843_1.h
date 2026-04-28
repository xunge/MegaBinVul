#include <stddef.h>

class QOpen {
public:
    bool Read(void *Data, size_t Size, size_t &Result);
} QOpen;

class File {
public:
    static int Read(void *Data, size_t Size);
};

class Archive {
public:
    int Read(void *Data, size_t Size);
};