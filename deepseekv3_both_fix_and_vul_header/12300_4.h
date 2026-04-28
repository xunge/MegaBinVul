#include <stdint.h>
#include <stddef.h>

typedef uint8_t byte;
typedef uint32_t word32;

#define CRYPTOPP_BOOL_AESNI_INTRINSICS_AVAILABLE 0
#define CRYPTOPP_ALLOW_UNALIGNED_DATA_ACCESS
#define CRYPTOPP_ALLOW_RIJNDAEL_UNALIGNED_DATA_ACCESS

class Rijndael {
public:
    class Dec {
    public:
        void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
        void AdvancedProcessBlocks(const byte *inBlock, const byte *xorBlock, byte *outBlock, size_t length, word32 flags) const;
        bool HasAESNI() const;
        const word32* m_key;
        unsigned int m_rounds;
    };
};

template <class T, class B>
class BlockGetAndPut {
public:
    static BlockGetAndPut Get(const byte* block) { return BlockGetAndPut(block); }
    BlockGetAndPut& operator()(T value) { return *this; }
    static BlockGetAndPut Put(const byte* xorBlock, byte* outBlock) { return BlockGetAndPut(nullptr); }
private:
    BlockGetAndPut(const byte* block) {}
};

class NativeByteOrder {};

extern const word32 Td[256];
extern const word32 Sd[256];

#define QUARTER_ROUND_FD(a, b, c, d, e)
#define QUARTER_ROUND_D(a, b, c, d, e)
#define QUARTER_ROUND_LD(a, b, c, d, e)

int GetCacheLineSize();