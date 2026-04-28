#include <string>

namespace content {
class WebContents;
}

class Browser {
 public:
  class TabStripModel {
   public:
    content::WebContents* GetActiveWebContents();
  };
  TabStripModel* tab_strip_model();
};

namespace switches {
extern const char kDisableGpuSandbox[];
extern const char kDisableSeccompFilterSandbox[];
extern const char kDisableSetuidSandbox[];
extern const char kDisableWebSecurity[];
extern const char kNoSandbox[];
extern const char kSingleProcess[];
extern const char kEnableBrowserPluginForAllViewTypes[];
extern const char kTrustedSpdyProxy[];
extern const char kDisableUserMediaSecurity[];
extern const char kDisableWebRtcEncryption[];
extern const char kIgnoreCertificateErrors[];
extern const char kReduceSecurityForTesting[];
extern const char kSyncAllowInsecureXmppConnection[];
extern const char kGaiaUrl[];
}

namespace translate {
namespace switches {
extern const char kTranslateSecurityOrigin[];
extern const char kTranslateScriptURL[];
}
}

namespace autofill {
namespace switches {
extern const char kWalletSecureServiceUrl[];
}
}

namespace extensions {
namespace switches {
extern const char kExtensionsOnChromeURLs[];
}
}

class CommandLine {
 public:
  static CommandLine* ForCurrentProcess();
  bool HasSwitch(const char*);
};

class SimpleAlertInfoBarDelegate {
 public:
  static void Create(class InfoBarService*, int, const std::u16string&, bool);
};

class InfoBarService {
 public:
  static InfoBarService* FromWebContents(content::WebContents*);
};

class InfoBarDelegate {
 public:
  static const int kNoIconID;
};

namespace l10n_util {
std::u16string GetStringFUTF16(int, const std::u16string&);
}

namespace base {
std::u16string UTF8ToUTF16(const std::string&);
}

#define IDS_BAD_FLAGS_WARNING_MESSAGE 0