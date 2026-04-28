#include <cstdint>
#include <cstring>
#include <cassert>

typedef unsigned char binary;
typedef uint64_t uint64;
typedef uint32_t uint32;

class IOCallback {
public:
    size_t read(void*, size_t);
    uint64_t getFilePointer();
    void setFilePointer(uint64_t);
};

class EbmlSemanticContext;

class EbmlId {
public:
    EbmlId(binary*, int);
};

class EbmlElement {
public:
    static EbmlElement* FindNextElement(IOCallback&, const EbmlSemanticContext&, int&, uint64, bool, unsigned int);
    bool IsDummy();
    void SetSizeLength(uint32);
    uint64 Size;
    bool ValidateSize();
    void SetSizeInfinite();
    uint64 SizePosition;
    uint64 ElementPosition;
    static EbmlElement* CreateElementUsingContext(const EbmlId&, const EbmlSemanticContext&, int&, bool, bool, unsigned int);
};

constexpr uint32 EBML_ID_LENGTH(const EbmlId& id);
uint64 ReadCodedSizeValue(binary*, uint32&, uint64&);