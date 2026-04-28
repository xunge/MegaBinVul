#include <string>
#include <string.h>

class GURL {
public:
    bool is_valid() const;
    GURL();
    GURL(const GURL&);
    GURL& operator=(const GURL&);
};

class OSExchangeData {
public:
    enum FilenameToURLPolicy {};
    enum { URL };
};

namespace base {
    typedef std::u16string string16;
}

class OSExchangeDataProviderAura {
private:
    int formats_;
    GURL url_;
    base::string16 title_;

public:
    bool GetPlainTextURL(GURL* url) const;
    bool GetURLAndTitle(OSExchangeData::FilenameToURLPolicy policy, GURL* url, base::string16* title) const;
    bool GetURLAndTitle(GURL* url, base::string16* title) const;
};