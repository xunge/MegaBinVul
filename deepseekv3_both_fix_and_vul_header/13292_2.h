#include <vector>
#include <cstdint>

#define W_ARRAY_SIZE 3
#define PODOFO_RAISE_ERROR_INFO(code, msg)

enum PdfErrorCode {
    NoXRef
};

class PdfName {
public:
    static const char* KeySize;
};

class PdfArray;

class PdfObject {
public:
    bool TryGetNumber(int64_t& num) const;
    bool TryGetArray(const PdfArray*& arr) const;
};

class PdfArray : public std::vector<PdfObject> {};

class PdfDictionary {
public:
    template<typename T>
    T FindKeyAs(const char* key, T defaultValue) const;
    const PdfObject& MustFindKey(const char* key) const;
};

class PdfXRefStreamParserObject {
public:
    const PdfDictionary& GetDictionary() const;
    void getIndices(std::vector<int64_t>& indices, int64_t size);
    void parseStream(const int64_t wArray[W_ARRAY_SIZE], const std::vector<int64_t>& indices);
    void ReadXRefTable();
};

using std::vector;