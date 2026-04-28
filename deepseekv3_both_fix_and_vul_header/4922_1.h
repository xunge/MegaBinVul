#include <memory>
#include <string>

namespace Attach {
  struct Params {
    static Params* Create(const std::string& args);
    std::string target;
    std::string required_version;
  };
}

namespace ErrorUtils {
  std::string FormatErrorMessage(const std::string& error, const std::string& version);
}

namespace keys {
  extern const std::string kProtocolVersionNotSupportedError;
  extern const std::string kAlreadyAttachedError;
  extern const std::string kSilentDebuggingRequired;
}

namespace switches {
  extern const std::string kSilentDebuggerExtensionAPI;
}

namespace infobars {
  class InfoBar;
}

namespace ExtensionDevToolsInfoBarDelegate {
  infobars::InfoBar* Create(void* render_view_host, const std::string& name);
}

class CommandLine {
 public:
  static CommandLine* ForCurrentProcess();
  bool HasSwitch(const std::string& switch_string);
};

class Debuggee {};
class Profile {};

class Extension {
 public:
  std::string id() const;
  std::string name() const;
};

class ExtensionDevToolsClientHost {
 public:
  ExtensionDevToolsClientHost(Profile* profile, void* agent_host, const std::string& id, 
                             const std::string& name, Debuggee debuggee, infobars::InfoBar* infobar);
};

class DevToolsHttpHandler {
 public:
  static bool IsSupportedProtocolVersion(const std::string& version);
};

class AgentHost {
 public:
  bool IsAttached();
  void* GetRenderViewHost();
};

template<typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* ptr);
  ~scoped_ptr();
  T* get() const;
  T* operator->() const;
};

class DebuggerAttachFunction {
 public:
  bool RunAsync();
  bool InitAgentHost();
  void CopyDebuggee(Debuggee* debuggee, const std::string& target);
  void FormatErrorMessage(const std::string& error);
  void SendResponse(bool success);
  Profile* GetProfile();
  Extension* GetExtension();
  std::string* args_;
  Debuggee debuggee_;
  scoped_ptr<AgentHost> agent_host_;
  std::string error_;
};

#define EXTENSION_FUNCTION_VALIDATE(expr) if (!(expr)) return false