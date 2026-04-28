#include <stdint.h>

typedef int32_t AP4_Result;
typedef uint32_t AP4_UI32;
typedef uint8_t AP4_UI08;
typedef uint32_t AP4_Size;

#define AP4_FAILED(result) ((result) < 0)
#define AP4_FULL_ATOM_HEADER_SIZE 12
#define AP4_ERROR_INVALID_FORMAT (-1)
#define AP4_SUCCESS (0)

class AP4_ByteStream {
public:
    AP4_Result WriteUI32(AP4_UI32 value);
    AP4_Result WriteUI08(AP4_UI08 value);
    AP4_Result Write(const void* buffer, AP4_Size size);
};

class AP4_String {
public:
    const char* GetChars() const;
    AP4_Size GetLength() const;
};

class AP4_HdlrAtom {
public:
    AP4_Result WriteFields(AP4_ByteStream& stream);
private:
    AP4_UI32 m_Predefined;
    AP4_UI32 m_HandlerType;
    AP4_UI32 m_Reserved[3];
    AP4_UI32 m_Size32;
    AP4_String m_HandlerName;
    bool m_QuickTimeMode;
};