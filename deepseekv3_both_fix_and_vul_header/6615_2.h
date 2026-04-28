#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#define QT_VERSION 0
#define QT_VERSION_CHECK(a,b,c) 0

typedef uint32_t quint32;

class QRandomGenerator {
public:
    static QRandomGenerator* system();
    quint32 generate();
};

class Pass {
public:
    quint32 boundedRandom(quint32 bound);
private:
    int fd = -1;
};