#include <memory>
#include <string>

class GURL {
public:
  GURL();
  GURL(const GURL&);
};

class WebContents {
public:
  GURL GetVisibleURL();
};

class ExtensionTabUtil {
public:
  static bool GetTabById(const std::string& tab_id,
                        void* profile,
                        bool include_incognito,
                        void*,
                        void*,
                        WebContents** web_contents,
                        void*);
};

class DevToolsAgentHost {
public:
  static std::unique_ptr<DevToolsAgentHost> GetOrCreateFor(WebContents*);
  static std::unique_ptr<DevToolsAgentHost> GetForId(const std::string&);
  GURL GetURL();
};

class ExtensionHost {
public:
  GURL GetURL();
  WebContents* host_contents();
};

class ProcessManager {
public:
  static ProcessManager* Get(void* profile);
  ExtensionHost* GetBackgroundHostForExtension(const std::string& extension_id);
};

class PermissionsData {
public:
  static bool IsRestrictedUrl(const GURL& url,
                             const GURL&,
                             void* extension,
                             std::string* error);
};

struct Debuggee {
  std::string* tab_id;
  std::string* extension_id;
  std::string* target_id;
};

namespace keys {
  extern const char kInvalidTargetError[];
  extern const char kNoTargetError[];
}

class DebuggerFunction {
protected:
  Debuggee debuggee_;
  std::string error_;
  std::unique_ptr<DevToolsAgentHost> agent_host_;

  virtual void* GetProfile() = 0;
  virtual bool include_incognito() = 0;
  virtual void* extension() = 0;
  virtual void FormatErrorMessage(const char* error) = 0;
  
  bool InitAgentHost();
};