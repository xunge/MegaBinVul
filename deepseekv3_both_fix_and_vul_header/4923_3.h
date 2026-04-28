#include <string>
#include <memory>
#include <vector>
#include <map>

class GURL {
public:
  std::string scheme() const;
};

class WebContents {
public:
  GURL GetURL() const;
  GURL GetVisibleURL() const;
};

class Extension {};

class ExtensionHost {
public:
  GURL GetURL() const;
  class RenderViewHost* render_view_host() const;
};

class DevToolsAgentHost {
public:
  static std::unique_ptr<DevToolsAgentHost> GetOrCreateFor(WebContents* web_contents);
  static std::unique_ptr<DevToolsAgentHost> GetOrCreateFor(RenderViewHost* render_view_host);
  static std::unique_ptr<DevToolsAgentHost> GetForId(const std::string& id);
};

class ExtensionSystem {
public:
  static ExtensionSystem* Get(void* profile);
  class ProcessManager* process_manager() const;
};

class ProcessManager {
public:
  ExtensionHost* GetBackgroundHostForExtension(const std::string& extension_id);
};

class RenderViewHost {};

class PermissionsData {
public:
  static bool IsRestrictedUrl(const GURL& url, const GURL& site_url, 
                            const Extension* extension, std::string* error);
};

class ErrorUtils {
public:
  static std::string FormatErrorMessage(const char* format, const std::string& s);
};

struct Debuggee {
  int* tab_id;
  std::string* extension_id;
  std::string* target_id;
};

namespace keys {
  const char kInvalidTargetError[] = "Invalid target";
  const char kNoTargetError[] = "No target";
  const char kAttachToWebUIError[] = "Cannot attach to WebUI";
}

namespace content {
  bool HasWebUIScheme(const GURL& url);
}

namespace ExtensionTabUtil {
  bool GetTabById(int tab_id, void* profile, bool include_incognito,
                 void* browser, void* tab_strip, WebContents** web_contents,
                 void* window);
}

class DebuggerFunction {
protected:
  Debuggee debuggee_;
  std::string error_;
  std::unique_ptr<DevToolsAgentHost> agent_host_;

  const Extension* GetExtension();
  void* GetProfile();
  bool include_incognito();
  void FormatErrorMessage(const char* error);
  bool InitAgentHost();
};