#include <string>
#include <cstdlib>

typedef unsigned int quint32;

struct QChar {};
struct QString {
    int length() const;
    QChar at(int) const;
    void append(QChar);
};

struct Pass {
    static QString generateRandomPassword(const QString&, unsigned int);
};

quint32 boundedRandom(quint32 bound);