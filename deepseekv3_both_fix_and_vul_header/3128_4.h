#include <string>
#include <cassert>

#define NOTREACHED() assert(false)

namespace ui {
class LocatedEvent {
 public:
  const void* location() const;
};
}  // namespace ui

class NavigationEntry {
 public:
  std::string GetURL() const;
  const void* GetSSL() const;
};

class NavigationController {
 public:
  NavigationEntry* GetVisibleEntry() const;
  NavigationEntry* GetActiveEntry() const;
};

class WebContents {
 public:
  const NavigationController& GetController() const;
};

class PageInfoHelper {
 public:
  class Delegate {
   public:
    virtual void ShowWebsiteSettings(WebContents* tab,
                                    const std::string& url,
                                    const void* ssl) = 0;
  };

  class LocationBar {
   public:
    class LocationEntry {
     public:
      virtual bool IsEditingOrEmpty() const = 0;
    };

    virtual LocationEntry* GetLocationEntry() const = 0;
    virtual WebContents* GetWebContents() const = 0;
    virtual Delegate* delegate() const = 0;
  };

  void ProcessEvent(const ui::LocatedEvent& event);

 private:
  class Owner {
   public:
    virtual bool HitTestPoint(const void* location) const = 0;
  };

  Owner* owner_;
  LocationBar* location_bar_;
};