#include <string>
#include <memory>

namespace base {
using string16 = std::u16string;
}

class GURL {
public:
    bool is_valid() const;
};

namespace ui {
namespace DragDropTypes {
const int DRAG_NONE = 0;
}

class OSExchangeData {
public:
    enum FilenameConversionPolicy { CONVERT_FILENAMES };
    bool GetURLAndTitle(FilenameConversionPolicy policy, GURL* url, base::string16* title) const;
    bool GetURLAndTitle(GURL* url, base::string16* title) const;
    void SetURL(const GURL& url, const base::string16& title);
};

class DropTargetEvent {
public:
    const OSExchangeData& data() const;
};
}

class TabStrip {
public:
    int OnPerformDrop(const ui::DropTargetEvent& event);
};

class BrowserRootView {
private:
    bool forwarding_to_tab_strip_ = false;
    TabStrip* tabstrip();
    bool GetPasteAndGoURL(const ui::OSExchangeData& data, GURL* url);
    std::unique_ptr<ui::DropTargetEvent> MapEventToTabStrip(const ui::DropTargetEvent& event, const ui::OSExchangeData& data);
public:
    int OnPerformDrop(const ui::DropTargetEvent& event);
};

template<typename T>
using scoped_ptr = std::unique_ptr<T>;