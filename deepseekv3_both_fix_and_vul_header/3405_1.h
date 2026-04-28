#include <string>
#include <vector>
#include <memory>

class GURL {
public:
    GURL();
    explicit GURL(const std::string& url_spec);
};

class Pickle {
public:
    Pickle();
};

namespace ui {
class OSExchangeData {
public:
    enum FilenameConversionPolicy {
        CONVERT_FILENAMES
    };
    bool HasCustomFormat(int format) const;
    bool GetPickledData(int format, Pickle* data) const;
    bool GetURLAndTitle(FilenameConversionPolicy policy, GURL* url, std::u16string* title) const;
    bool GetURLAndTitle(GURL* url, std::u16string* title) const;
};
}

namespace base {
using string16 = std::u16string;
}

struct Element {
    GURL url;
    base::string16 title;
};

class BookmarkNodeData {
public:
    bool Read(const ui::OSExchangeData& data);
    bool ReadFromPickle(Pickle* drag_data_pickle);
    void ReadFromTuple(const GURL& url, const base::string16& title);
    bool is_valid() const;
    static int GetBookmarkCustomFormat();

    std::vector<Element> elements;
    std::string profile_path_;
};