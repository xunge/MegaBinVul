#include <cstdint>
#include <cstring>
#include <climits>
#include <string>

typedef int64_t SphOffset_t;
typedef unsigned char BYTE;

struct CSphString {
    const char* cstr() const;
    const char* scstr() const;
    bool IsEmpty() const;
    void SetSprintf(const char* fmt, ...);
    bool operator==(const char*) const;
    bool operator!=(const char*) const;
    CSphString& operator=(const char*);
    std::string m_str;
};

struct CSphIndex {
    struct Settings {
    };
    const Settings& GetSettings() const;
};

struct ExcerptQuery_t {
    CSphString m_sError;
    CSphString m_sSource;
    CSphString m_sStripMode;
    int m_iLimit;
    int m_iLimitPassages;
    int m_iLimitWords;
    unsigned m_uFilesMode;
    struct Separators {
        void Resize(int);
    };
    Separators m_dSeparators;
    struct Results {
    };
    Results m_dRes;
};

template <typename T>
struct CSphFixedVector {
    CSphFixedVector(int);
    void Reset(int);
    T* Begin();
};

struct CSphAutofile {
    int Open(const char*, int, CSphString&);
    SphOffset_t GetSize() const;
    bool Read(void*, int, CSphString&);
};

struct SnippetContext_t {
    struct Stripper {
        Stripper* Ptr() const;
        void Strip(BYTE*);
    };
    const Stripper m_tStripper;
    struct ExtQuery {
    };
    ExtQuery m_tExtQuery;
    int m_eExtQuerySPZ;
    void* m_pDict;
    void* m_pTokenizer;
    void* m_pQueryTokenizer;
    void BuildExcerpt(ExcerptQuery_t&, const CSphIndex*) const;
    void DoHighlighting(ExcerptQuery_t&, const CSphIndex::Settings&, const ExtQuery&, int, const char*, int, void*, void*, Stripper*, void*, ExcerptQuery_t::Results&, ExcerptQuery_t::Separators&) const;
    bool TestEscaping(const CSphString&, const CSphString&) const;
};

extern CSphString g_sSnippetsFilePrefix;

enum { SPH_O_READ };