#include <vector>
#include <string>

class QByteArray {
public:
    QByteArray();
    QByteArray(const char* data, int size);
    int length() const;
    void append(char c);
    QByteArray& operator+=(const QByteArray& other);
    char* data();
    const char* constData() const;
};

namespace QCA {
    class Initializer {};
    enum Direction { Encode, Decode };
    class SymmetricKey {
    public:
        SymmetricKey();
        SymmetricKey(const QByteArray&);
    };
    class MemoryRegion {
    public:
        MemoryRegion(const QByteArray&);
        QByteArray toByteArray() const;
    };
    class Cipher {
    public:
        enum Algorithm {};
        enum Mode { ECB };
        enum Padding { NoPadding };
        Cipher(Algorithm, Mode, Padding, Direction, const SymmetricKey&);
        bool ok() const;
        MemoryRegion update(const MemoryRegion&);
        MemoryRegion final();
    };
}

class Cipher {
private:
    QCA::SymmetricKey m_key;
    QCA::Cipher::Algorithm m_type;
public:
    QByteArray blowfishECB(QByteArray cipherText, bool direction);
    QByteArray b64ToByte(const QByteArray &data);
    QByteArray byteToB64(const QByteArray &data);
};