#include <vector>
#include <cstdint>
#include <stdexcept>

using std::vector;

class PdfArray {
public:
    class iterator;
    iterator begin() const;
    iterator end() const;
    class iterator {
    public:
        const PdfArray& operator*() const;
        int64_t GetNumber() const;
        iterator& operator++();
        bool operator!=(const iterator&) const;
    };
    int64_t GetNumber() const;
};

class PdfObject {
public:
    bool TryGetArray(const PdfArray*&) const;
};

enum class PdfErrorCode {
    NoXRef
};

class PdfXRefStreamParserObject {
public:
    class Dictionary {
    public:
        const PdfObject* GetKey(const char*);
    };
    Dictionary GetDictionary();
    void getIndices(vector<int64_t>& indices, int64_t size);
};

#define PODOFO_RAISE_ERROR_INFO(code, msg) throw std::runtime_error(msg)