#include <string_view>

class PdfDictionary;

class PdfObject {
public:
    PdfObject* GetIndirectReference() const;
    PdfObject* GetOwner() const;
    bool TryGetDictionary(PdfDictionary*& dict) const;
    bool IsDictionary() const;
    PdfDictionary& GetDictionary() const;
    PdfObject* findKey(const std::string_view& key) const;
};

class PdfDictionary {
public:
    PdfObject* GetOwner() const;
    PdfObject* findKey(const std::string_view& key) const;
    PdfObject* findKeyParent(const std::string_view& key) const;
};

namespace utls {
    class RecursionGuard {};
}

using string_view = const std::string_view&;