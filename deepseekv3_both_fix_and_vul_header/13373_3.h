#include <memory>
#include <string>

class PdfVariant {
public:
    std::string ToString() const;
};

class PdfObject {
public:
    PdfObject(const PdfObject& other);
    PdfObject& GetObject();
    PdfVariant& GetVariant();
    std::string ToString() const;
};

class PdfEncrypt;

enum class PdfLogSeverity {
    Debug
};

class PdfParser {
public:
    double GetPdfVersion();
    bool HasXRefStream();
    long GetXRefOffset();
    PdfObject GetTrailer();
    bool IsEncrypted();
    PdfEncrypt* GetEncrypt();
    PdfEncrypt* TakeEncrypt();
};

class PdfMemDocument {
private:
    double m_Version;
    double m_InitialVersion;
    bool m_HasXRefStream;
    long m_PrevXRefOffset;
    PdfEncrypt* m_Encrypt;

public:
    void initFromParser(PdfParser& parser);
    void SetTrailer(std::unique_ptr<PdfObject> trailer);
    PdfObject& GetTrailer();
    void Init();
};

namespace PoDoFo {
    void LogMessage(PdfLogSeverity severity, const std::string& message);
}

namespace PdfCommon {
    bool IsLoggingSeverityEnabled(PdfLogSeverity severity);
}