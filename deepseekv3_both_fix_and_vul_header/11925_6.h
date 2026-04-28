#include <map>
#include <string>

enum ContentSetting {
  CONTENT_SETTING_DEFAULT,
  CONTENT_SETTING_ALLOW,
  CONTENT_SETTING_BLOCK,
  CONTENT_SETTING_ASK,
  CONTENT_SETTING_SESSION_ONLY,
  CONTENT_SETTING_DETECT_IMPORTANT_CONTENT,
  CONTENT_SETTING_NUM_SETTINGS
};

namespace url {
class Origin {
 public:
  explicit Origin(const std::string& origin_string);
  std::string GetURL() const;
};
}

namespace blink {
class WebLocalFrame {
 public:
  class Document {
   public:
    class SecurityOrigin {
     public:
      std::string ToString() const;
      operator std::string() const { return ToString(); }
    };
    SecurityOrigin GetSecurityOrigin() const;
  };
  Document GetDocument() const;
  static std::string GetOriginOrURL(WebLocalFrame* frame);
};
}

class RenderFrame {
 public:
  blink::WebLocalFrame* GetWebFrame() const;
};

class ContentSettingsRules {
 public:
  void* script_rules;
};

class ContentSettingsManager {
 public:
  static std::string GetOriginOrURL(blink::WebLocalFrame* frame);
  ContentSetting GetSetting(const std::string& origin_or_url,
                          const std::string& secondary_url,
                          const std::string& resource_identifier,
                          bool default_value);
  void* content_settings();
};

class ContentSettingsObserver {
 public:
  bool AllowScript(bool enabled_per_settings);
 protected:
  bool IsScriptDisabledForPreview(RenderFrame* render_frame);
  bool IsWhitelistedForContentSettings();
  RenderFrame* render_frame();
  ContentSetting GetContentSettingFromRules(void* rules,
                                          blink::WebLocalFrame* frame,
                                          const std::string& url);

  std::map<blink::WebLocalFrame*, bool> cached_script_permissions_;
  bool is_interstitial_page_;
  ContentSettingsManager* content_settings_manager_;
  ContentSettingsRules* content_setting_rules_;
};