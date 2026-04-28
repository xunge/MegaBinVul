#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

enum NavigationType {
  NAVIGATION_TYPE_NAV_IGNORE,
  NAVIGATION_TYPE_NEW_PAGE,
  NAVIGATION_TYPE_NEW_SUBFRAME,
  NAVIGATION_TYPE_AUTO_SUBFRAME,
  NAVIGATION_TYPE_SAME_PAGE,
  NAVIGATION_TYPE_IN_PAGE,
  NAVIGATION_TYPE_EXISTING_PAGE,
  NAVIGATION_TYPE_UNKNOWN
};

class SiteInstance {
public:
  virtual int GetId() const = 0;
};

class RenderFrameHost {
public:
  virtual SiteInstance* GetSiteInstance() const = 0;
  virtual int GetRoutingID() const = 0;
};

class RenderFrameHostImpl : public RenderFrameHost {
public:
  class RenderViewHost {
  public:
    void Send(void* msg);
  };
  RenderViewHost* render_view_host();
};

class NavigationEntryImpl {
public:
  virtual int GetPageID() const = 0;
  virtual SiteInstance* site_instance() const = 0;
  virtual std::string GetURL() const = 0;
  virtual bool is_renderer_initiated() const = 0;
};

class GURL {
public:
  GURL(const std::string& url);
  std::string spec() const;
  friend std::ostream& operator<<(std::ostream& os, const GURL& url);
};

std::ostream& operator<<(std::ostream& os, const GURL& url) {
  return os << url.spec();
}

struct FrameHostMsg_DidCommitProvisionalLoad_Params {
  int page_id;
  int transition;
  bool history_list_was_cleared;
  GURL url;
  bool was_within_same_page;
};

class ViewMsg_TempCrashWithData {
public:
  explicit ViewMsg_TempCrashWithData(const GURL& url);
};

namespace base {
class UserMetricsAction {
public:
  explicit UserMetricsAction(const char* name);
};

std::string IntToString(int value);
}

class NavigationControllerImpl {
public:
  NavigationType ClassifyNavigation(
      RenderFrameHost* rfh,
      const FrameHostMsg_DidCommitProvisionalLoad_Params& params) const;
  
private:
  bool PageTransitionIsMainFrame(int transition) const;
  NavigationEntryImpl* GetLastCommittedEntry() const;
  int GetEntryIndexWithPageID(SiteInstance* site_instance, int page_id) const;
  bool AreURLsInPageNavigation(const GURL& existing_url, const GURL& new_url,
                             bool was_within_same_page, RenderFrameHost* rfh) const;
  bool AreURLsInPageNavigation(const GURL& existing_url, const GURL& new_url,
                             bool was_within_same_page, NavigationType nav_type) const;
  
  std::vector<std::unique_ptr<NavigationEntryImpl>> entries_;
  NavigationEntryImpl* pending_entry_;
  class Delegate {
  public:
    int GetMaxPageIDForSiteInstance(SiteInstance* site_instance) const;
    int GetMaxPageID() const;
  };
  Delegate* delegate_;
};

#define DCHECK(condition) ((void)0)
#define NOTREACHED() ((void)0)
#define LOG(severity) std::cerr
#define ERROR 0

void RecordAction(const base::UserMetricsAction& action);