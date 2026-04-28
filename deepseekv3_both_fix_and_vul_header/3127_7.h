#include <string>
#include <vector>

class GURL {
public:
  std::string spec() const;
};

class Profile {
public:
  static Profile* FromBrowserContext(void* context);
  void* GetHostContentSettingsMap();
};

class NavigationEntry {
public:
  GURL GetURL() const;
};

class NavigationController {
public:
  NavigationEntry* GetVisibleEntry() const;
  NavigationEntry* GetActiveEntry() const;
};

class RendererContentSettingRules {};

class ChromeViewMsg_SetContentSettingRules {
public:
  explicit ChromeViewMsg_SetContentSettingRules(const RendererContentSettingRules& rules);
};

class WebContents {
public:
  const NavigationController& GetController();
  void* GetBrowserContext();
};

namespace content {
class NotificationSource {};
class NotificationDetails {};
template <typename T> class Details {
public:
  Details(const NotificationDetails& details);
  T* ptr() const;
};
}  // namespace content

struct ContentSettingsDetails {
  bool update_all() const;
  class ContentSettingsPattern {
  public:
    bool Matches(const GURL& url) const;
  };
  ContentSettingsPattern primary_pattern() const;
};

class TabSpecificContentSettings {
public:
  void Observe(int type, const content::NotificationSource& source,
               const content::NotificationDetails& details);
  WebContents* web_contents();
  void Send(ChromeViewMsg_SetContentSettingRules* msg);
};

namespace chrome {
const int NOTIFICATION_CONTENT_SETTINGS_CHANGED = 0;
}

void GetRendererContentSettingRules(void* map, RendererContentSettingRules* rules);
#define DCHECK(condition) ((void)0)