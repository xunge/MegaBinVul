#include <string>
#include <cstdint>

typedef uint64_t XMP_Uns64;
typedef uint32_t XMP_Uns32;
typedef uint16_t XMP_Uns16;
typedef int32_t XMP_Int32;

struct GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
};

struct ObjectState {
    bool broadcast;
};

struct ObjectData {
    GUID guid;
    XMP_Uns64 pos;
    XMP_Uns64 len;
};

struct ASF_ObjectBase {
    GUID guid;
    XMP_Uns64 size;
};

extern GUID ASF_Header_Object;
extern GUID ASF_File_Properties_Object;
extern GUID ASF_Content_Description_Object;
extern GUID ASF_Content_Branding_Object;
extern GUID ASF_Content_Encryption_Object;
extern GUID ASF_Padding_Object;
extern GUID ASF_Header_Extension_Object;

extern const XMP_Uns32 kASF_ObjectBaseLen;
extern XMP_Uns64 posFileSizeInfo;

class XMP_IO {
public:
    virtual void Seek(XMP_Uns64 pos, int mode) = 0;
    virtual XMP_Uns32 Read(void* buffer, XMP_Uns32 count, bool readAll) = 0;
    virtual void ReadAll(char* buffer, XMP_Int32 size) = 0;
};

enum {
    kXMP_SeekFromStart
};

class ASF_LegacyManager {
public:
    enum Field {
        fieldCreationDate,
        fieldTitle,
        fieldAuthor,
        fieldCopyright,
        fieldDescription,
        fieldCopyrightURL,
        fieldLicenseURL
    };
    enum Object {
        objectFileProperties,
        objectContentDescription,
        objectContentBranding,
        objectContentEncryption
    };

    void SetPadding(XMP_Uns64 padding);
    void SetField(Field field, const std::string& value);
    void SetBroadcast(bool broadcast);
    void SetObjectExists(Object object);
    XMP_Uns64 GetPadding();
    void ComputeDigest();
};

extern ASF_LegacyManager* legacyManager;

XMP_Uns32 GetUns32LE(const void* ptr);
XMP_Uns16 GetUns16LE(const void* ptr);
XMP_Uns64 GetUns64LE(const void* ptr);
bool IsEqualGUID(const GUID& g1, const GUID& g2);

class ASF_Support {
public:
    bool ReadHeaderObject(XMP_IO* fileRef, ObjectState& inOutObjectState, const ObjectData& newObject);
    void ReadHeaderExtensionObject(XMP_IO* fileRef, ObjectState& inOutObjectState, XMP_Uns64 pos, ASF_ObjectBase objectBase);
};

const ASF_LegacyManager::Object objectContentEncryption = ASF_LegacyManager::objectContentEncryption;