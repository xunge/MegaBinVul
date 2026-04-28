#include <cstdint>
#include <cstring>
#include <cassert>

typedef unsigned char binary;
typedef uint64_t uint64;
typedef uint32_t uint32;

class IOCallback {
public:
    virtual size_t read(void *buffer, size_t size) = 0;
    virtual uint64 getFilePointer() const = 0;
    virtual void setFilePointer(uint64 position) = 0;
};

class EbmlId {
public:
    EbmlId(const binary *data, int length);
    int GetLength() const;
};

class EbmlSemanticContext;

class EbmlElement {
public:
    virtual ~EbmlElement();
    virtual bool IsDummy() const = 0;
    virtual void SetSizeLength(uint32 length) = 0;
    virtual bool ValidateSize() const = 0;
    virtual bool SetSizeInfinite() = 0;
    
    uint64 Size;
    uint64 SizePosition;
    uint64 ElementPosition;
    
    static EbmlElement* CreateElementUsingContext(const EbmlId& id, const EbmlSemanticContext& context, 
                                                 int& upperLevel, bool isGlobal, bool allowDummy, unsigned int maxLowerLevel);
    
    static EbmlElement* FindNextElement(IOCallback& DataStream, const EbmlSemanticContext& Context, 
                                      int& UpperLevel, uint64 MaxDataSize, bool AllowDummyElt, 
                                      unsigned int MaxLowerLevel);
};

uint64 ReadCodedSizeValue(const binary* data, uint32& sizeLength, uint64& sizeUnknown);

#define EBML_ID_LENGTH(id) (id).GetLength()