#include <string>
#include <memory>

class GURL {
public:
    GURL();
    explicit GURL(const std::string& url_spec);
    bool is_valid() const;
    std::string spec() const;
};

class PrefService {
public:
    bool GetBoolean(const std::string& path) const;
    std::string GetString(const std::string& path) const;
    void SetBoolean(const std::string& path, bool value);
    void SetString(const std::string& path, const std::string& value);
};

namespace ui {
class OSExchangeData {
public:
    enum FilenameConversionPolicy { CONVERT_FILENAMES };
    bool GetURLAndTitle(FilenameConversionPolicy policy, GURL* url, std::u16string* title) const;
    bool GetURLAndTitle(GURL* url, std::u16string* title) const;
};

class DropTargetEvent {
public:
    const OSExchangeData& data() const;
};

namespace DragDropTypes {
enum DragOperation { DRAG_NONE };
}  // namespace DragDropTypes
}  // namespace ui

namespace prefs {
extern const char kHomePageIsNewTabPage[];
extern const char kHomePage[];
}  // namespace prefs

namespace base {
typedef std::u16string string16;
}  // namespace base

class HomeButton;

class HomePageUndoBubble {
public:
    static void ShowBubble(class Browser* browser, bool old_is_ntp, const GURL& old_homepage, HomeButton* home_button);
};

class Browser {
public:
    class Profile* profile();
};

class Profile {
public:
    PrefService* GetPrefs();
};

class HomeButton {
public:
    int OnPerformDrop(const ui::DropTargetEvent& event);
private:
    Browser* browser_;
};