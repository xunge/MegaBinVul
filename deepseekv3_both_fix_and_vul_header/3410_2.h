#include <string>

class GURL;

namespace base {
using string16 = std::u16string;
}

enum FilenameToURLPolicy {
    CONVERT_FILENAMES,
    DO_NOT_CONVERT_FILENAMES
};

class OSExchangeDataProvider {
public:
    virtual bool GetURLAndTitle(FilenameToURLPolicy policy, GURL* url, base::string16* title) = 0;
    virtual bool GetURLAndTitle(GURL* url, base::string16* title) = 0;
};

class OSExchangeData {
public:
    bool GetURLAndTitle(FilenameToURLPolicy policy, GURL* url, base::string16* title) const;
    bool GetURLAndTitle(GURL* url, base::string16* title) const;

private:
    OSExchangeDataProvider* provider_;
};