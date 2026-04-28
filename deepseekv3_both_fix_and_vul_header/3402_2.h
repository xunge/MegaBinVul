#include <string>

class GURL {
public:
    GURL(const std::wstring& url);
    bool is_valid() const;
};

namespace base {
    typedef std::wstring string16;
}

namespace net {
    base::string16 GetSuggestedFilename(const GURL& url, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
}

class ClipboardUtil {
public:
    static bool GetUrl(void* source_object, base::string16* url_str, base::string16* title, bool);
};

namespace OSExchangeData {
    enum FilenameToURLPolicy {
        CONVERT_FILENAMES
    };
}

class OSExchangeDataProviderWin {
public:
    bool GetURLAndTitle(OSExchangeData::FilenameToURLPolicy policy, GURL* url, base::string16* title) const;
    bool GetURLAndTitle(GURL* url, base::string16* title) const;
private:
    void* source_object_;
    bool GetPlainTextURL(void* source_object, GURL* url) const;
};