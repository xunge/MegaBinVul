#include <cstddef>

typedef int AP4_Result;
typedef unsigned char AP4_UI08;
typedef unsigned int AP4_UI32;
typedef long long AP4_Position;

class AP4_ByteStream {
public:
    AP4_Result Tell(AP4_Position& offset);
    AP4_Result ReadUI08(unsigned char& tag);
    AP4_Result Seek(AP4_Position offset);
};

class AP4_Descriptor {
};

class AP4_DescriptorFactory {
public:
    static AP4_Result CreateDescriptorFromStream(AP4_ByteStream& stream, AP4_Descriptor*& descriptor);
};

class AP4_ObjectDescriptor : public AP4_Descriptor {
public:
    AP4_ObjectDescriptor(AP4_ByteStream& stream, unsigned char tag, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_InitialObjectDescriptor : public AP4_Descriptor {
public:
    AP4_InitialObjectDescriptor(AP4_ByteStream& stream, unsigned char tag, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_EsIdIncDescriptor : public AP4_Descriptor {
public:
    AP4_EsIdIncDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_EsIdRefDescriptor : public AP4_Descriptor {
public:
    AP4_EsIdRefDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_EsDescriptor : public AP4_Descriptor {
public:
    AP4_EsDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_DecoderConfigDescriptor : public AP4_Descriptor {
public:
    AP4_DecoderConfigDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_DecoderSpecificInfoDescriptor : public AP4_Descriptor {
public:
    AP4_DecoderSpecificInfoDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_SLConfigDescriptor : public AP4_Descriptor {
public:
    AP4_SLConfigDescriptor(unsigned int header_size);
};

class AP4_IpmpDescriptorPointer : public AP4_Descriptor {
public:
    AP4_IpmpDescriptorPointer(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_IpmpDescriptor : public AP4_Descriptor {
public:
    AP4_IpmpDescriptor(AP4_ByteStream& stream, unsigned int header_size, AP4_UI32 payload_size);
};

class AP4_UnknownDescriptor : public AP4_Descriptor {
public:
    AP4_UnknownDescriptor(AP4_ByteStream& stream, unsigned char tag, unsigned int header_size, AP4_UI32 payload_size);
};

enum {
    AP4_DESCRIPTOR_TAG_OD,
    AP4_DESCRIPTOR_TAG_MP4_OD,
    AP4_DESCRIPTOR_TAG_IOD,
    AP4_DESCRIPTOR_TAG_MP4_IOD,
    AP4_DESCRIPTOR_TAG_ES_ID_INC,
    AP4_DESCRIPTOR_TAG_ES_ID_REF,
    AP4_DESCRIPTOR_TAG_ES,
    AP4_DESCRIPTOR_TAG_DECODER_CONFIG,
    AP4_DESCRIPTOR_TAG_DECODER_SPECIFIC_INFO,
    AP4_DESCRIPTOR_TAG_SL_CONFIG,
    AP4_DESCRIPTOR_TAG_IPMP_DESCRIPTOR_POINTER,
    AP4_DESCRIPTOR_TAG_IPMP_DESCRIPTOR
};

#define AP4_SUCCESS 0
#define AP4_FAILED(result) ((result) != AP4_SUCCESS)
#define AP4_ERROR_INVALID_FORMAT (-1)