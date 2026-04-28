#include <stdint.h>
#include <stddef.h>

typedef uint8_t byte;
typedef uint32_t word32;

class Rijndael {
public:
    class Enc {
    public:
        void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
        void AdvancedProcessBlocks(const byte *inBlock, const byte *xorBlock, byte *outBlock, size_t blockSize, unsigned int flags) const;
        bool HasSSE2() const;
        bool HasAESNI() const;
        const word32* m_key;
        unsigned int m_rounds;
    };
};

template <class T, class B>
class BlockGetAndPut {
public:
    class PutProxy {
    public:
        PutProxy(byte *out, const byte *xorBlock);
        PutProxy& operator()(const T& a);
    };
    
    BlockGetAndPut(const byte *block);
    BlockGetAndPut& operator()(T& a);
    static PutProxy Put(const byte *xorBlock, byte *outBlock);
    static BlockGetAndPut Get(const byte *block);
};

class NativeByteOrder {};

extern const word32 Te[256];
#define QUARTER_ROUND_FE(a, b, c, d, e)
#define QUARTER_ROUND_E(a, b, c, d, e)
#define QUARTER_ROUND_LE(a, b, c, d, e)

int GetCacheLineSize();