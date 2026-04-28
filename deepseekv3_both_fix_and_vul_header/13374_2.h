#include <sys/types.h>
#include <cstddef>

class PdfDocument;
class PdfReference;
class InputStreamDevice;

class PdfVariant {
public:
    PdfVariant();
};

class PdfObject {
public:
    PdfObject(const PdfVariant&, const PdfReference&, bool);
};

class InputStreamDevice {
public:
    ssize_t GetPosition() const;
};

struct PdfParserObject : public PdfObject {
    PdfParserObject(PdfDocument* doc, const PdfReference& indirectReference,
        InputStreamDevice& device, ssize_t offset);
    
    InputStreamDevice* m_device;
    void* m_Encrypt;
    bool m_IsTrailer;
    ssize_t m_Offset;
    bool m_HasStream;
    size_t m_StreamOffset;

    void resetDirty();
    void SetDocument(PdfDocument* doc);
    void EnableDelayedLoading();
    void EnableDelayedLoadingStream();
};