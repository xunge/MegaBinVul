#include <utility>
#include <memory>

struct KURL {
    KURL(const KURL&) {}
};

struct CachedDocumentParameters {
    int referrerPolicy;
};

class MediaValuesCached {
public:
    struct MediaValuesCachedData {};
    static std::unique_ptr<MediaValuesCached> create(const MediaValuesCachedData&) {
        return std::unique_ptr<MediaValuesCached>();
    }
};

template<typename T> class PassOwnPtr {
public:
    PassOwnPtr(std::unique_ptr<T> ptr) : m_ptr(std::move(ptr)) {}
    std::unique_ptr<T> release() { return std::move(m_ptr); }
    operator std::unique_ptr<T>() { return release(); }
private:
    std::unique_ptr<T> m_ptr;
};

#define ASSERT(expr) ((void)0)

class TokenPreloadScanner {
public:
    TokenPreloadScanner(const KURL&, PassOwnPtr<CachedDocumentParameters>, const MediaValuesCached::MediaValuesCachedData&);
private:
    KURL m_documentURL;
    bool m_inStyle;
    bool m_inPicture;
    bool m_inScript;
    bool m_isAppCacheEnabled;
    bool m_isCSPEnabled;
    unsigned m_templateCount;
    std::unique_ptr<CachedDocumentParameters> m_documentParameters;
    std::unique_ptr<MediaValuesCached> m_mediaValues;
    bool m_didRewind;
    struct {
        void setReferrerPolicy(int) {}
    } m_cssScanner;
};