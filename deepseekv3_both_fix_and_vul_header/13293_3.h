#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

#define W_ARRAY_SIZE 3

using std::vector;
using std::numeric_limits;

class charbuff {
public:
    size_t size() const;
    char* data();
    const char* data() const;
};

enum class PdfErrorCode {
    InvalidXRefStream,
    NoXRef
};

namespace PoDoFo {
    void PODOFO_RAISE_ERROR_INFO(PdfErrorCode, const char*);
}
using PoDoFo::PODOFO_RAISE_ERROR_INFO;

struct XRefEntry {
    bool Parsed = false;
};

class XRefEntries {
public:
    void Enlarge(int64_t);
    XRefEntry& operator[](unsigned);
    unsigned GetSize();
};

class Stream {
public:
    void CopyTo(charbuff&);
};

class PdfXRefStreamParserObject {
public:
    void parseStream(const int64_t wArray[W_ARRAY_SIZE], const vector<int64_t>& indices);
    Stream& GetOrCreateStream();
    void readXRefStreamEntry(XRefEntry& entry, const char* data, const int64_t wArray[W_ARRAY_SIZE]);
    XRefEntries* m_entries;
};