#include <string>

struct GURL {
    explicit GURL(const std::string& url_spec);
    bool is_valid() const;
};

enum WindowOpenDisposition {
    UNKNOWN,
    CURRENT_TAB,
    SINGLETON_TAB,
    NEW_FOREGROUND_TAB,
    NEW_BACKGROUND_TAB,
    NEW_POPUP,
    NEW_WINDOW,
    SAVE_TO_DISK,
    OFF_THE_RECORD,
    IGNORE_ACTION
};

class WebContents {};

namespace base {
    class UserMetricsAction {
    public:
        explicit UserMetricsAction(const char* action);
    };
};

namespace content {
    void RecordAction(const base::UserMetricsAction& action);
};

class InstantService {
public:
    bool IsValidURLForNavigation(const GURL& url);
};

class Delegate {
public:
    void NavigateOnThumbnailClick(const GURL& url, WindowOpenDisposition disposition, WebContents* web_contents);
};

class SearchTabHelper {
public:
    void NavigateToURL(const GURL& url, WindowOpenDisposition disposition, bool is_most_visited_item_url);
private:
    InstantService* instant_service_;
    Delegate* delegate_;
    WebContents* web_contents_;
};