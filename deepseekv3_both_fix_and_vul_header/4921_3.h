#include <string>
#include <vector>

class GURL {
public:
  bool SchemeIs(const char* scheme) const;
  std::string spec() const;
  GURL GetOrigin() const;
  bool operator!=(const GURL& other) const;
};

class Extension {
public:
  std::string id() const;
  static GURL GetBaseURLFromExtensionId(const std::string& id);
};

class URLPatternSet {
public:
  bool MatchesURL(const GURL& url) const;
};

class ErrorUtils {
public:
  static std::string FormatErrorMessage(const char* format, const std::string& s);
};

class ExtensionsClient {
public:
  static ExtensionsClient* Get();
  bool IsScriptableURL(const GURL& url, std::string* error);
};

namespace base {
class CommandLine {
public:
  static CommandLine* ForCurrentProcess();
  bool HasSwitch(const char* switch_string);
};
}

namespace content {
extern const char kChromeUIScheme[];
}

namespace switches {
extern const char kExtensionsOnChromeURLs[];
}

namespace manifest_errors {
extern const char kCannotAccessPage[];
extern const char kCannotAccessChromeUrl[];
extern const char kCannotAccessExtensionUrl[];
}

extern const char kExtensionScheme[];

struct PolicyDelegate {
  bool CanExecuteScriptOnPage(const Extension* extension,
                             const GURL& document_url,
                             const GURL& top_frame_url,
                             int tab_id,
                             int process_id,
                             std::string* error);
};

extern PolicyDelegate* g_policy_delegate;

class PermissionsData {
public:
  bool CanRunOnPage(const Extension* extension,
                   const GURL& document_url,
                   const GURL& top_frame_url,
                   int tab_id,
                   int process_id,
                   const URLPatternSet& permitted_url_patterns,
                   std::string* error) const;
  bool IsRestrictedUrl(const GURL& document_url,
                      const GURL& top_frame_url,
                      const Extension* extension,
                      std::string* error) const;
  bool HasTabSpecificPermissionToExecuteScript(int tab_id,
                                             const GURL& top_frame_url) const;
  bool CanExecuteScriptEverywhere(const Extension* extension) const;
};