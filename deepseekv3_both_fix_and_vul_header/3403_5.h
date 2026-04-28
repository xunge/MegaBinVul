#include <string>
#include <string_view>

namespace base {
using string16 = std::u16string;
string16 UTF8ToUTF16(const std::string& text);
}

namespace ui {
class GURL {
public:
    std::string spec() const;
};

class OSExchangeData {
public:
    enum FilenameConversion { CONVERT_FILENAMES };
    bool HasURL() const;
    bool GetURLAndTitle(FilenameConversion, ui::GURL*, base::string16*) const;
    bool GetURLAndTitle(ui::GURL*, base::string16*) const;
    bool HasString() const;
    bool GetString(base::string16*) const;
};
namespace DragDropTypes {
    const int DRAG_NONE = 0;
    const int DRAG_COPY = 1;
};
}  // namespace ui

class GURL : public ui::GURL {
};

class OmniboxViewViews {
public:
    bool HasTextBeingDragged() const;
    class Model {
    public:
        bool CanPasteAndGo(const base::string16& text);
        void PasteAndGo(const base::string16& text);
    };
    Model* model();
    int OnDrop(const ui::OSExchangeData& data);
};

base::string16 StripJavascriptSchemas(const base::string16& text);
base::string16 CollapseWhitespace(const base::string16& text, bool trim);