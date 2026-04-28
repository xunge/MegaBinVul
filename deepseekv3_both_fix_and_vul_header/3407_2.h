#include <string>
#include <vector>

namespace base {
typedef std::u16string string16;
}

namespace ui {
namespace OSExchangeData {
const int CONVERT_FILENAMES = 0;
}
}

class GURL {
public:
    bool is_valid() const;
    bool SchemeIsFile() const;
};

struct DropTargetEvent {
    struct Data {
        bool GetURLAndTitle(int, GURL* url, base::string16* title) const;
        bool GetURLAndTitle(GURL* url, base::string16* title) const;
    };
    Data data() const;
};

struct DropInfo {
    GURL url;
};

class Controller {
public:
    void CheckFileSupported(const GURL& url);
};

class TabStrip {
public:
    void StopAnimating(bool);
    void UpdateDropIndex(const DropTargetEvent& event);
    DropInfo* drop_info_;
    Controller* controller();
    void OnDragEntered(const DropTargetEvent& event);
};