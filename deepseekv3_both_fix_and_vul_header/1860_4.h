#include <stdlib.h>

class IByteReader;

class IDeletable {
public:
    virtual ~IDeletable() {}
};

template<typename T>
class Deletable : public IDeletable {
public:
    T* GetPtr();
};

class ByteList {};

class XcryptStreams {
public:
    bool IsUsingAES();
};

class PDFStreamInput {
public:
    IDeletable* GetMetadata(const char* key);
};

class DecryptionHelper {
public:
    bool IsEncrypted();
    bool CanDecryptDocument();
    bool HasCryptFilterDefinition(void* parser, PDFStreamInput* stream);
    IByteReader* CreateDecryptionReader(IByteReader* stream, const ByteList& key, bool useAES);
    IByteReader* CreateDefaultDecryptionFilterForStream(PDFStreamInput* inStream, IByteReader* inToWrapStream);
    void* mParser;
    XcryptStreams* mXcryptStreams;
    static const char* scEcnryptionKeyMetadataKey;
};