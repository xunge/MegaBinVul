#include <string>
#include <cstdint>

namespace gfx {
enum DirectionalityMode {
  DIRECTIONALITY_FORCE_LTR,
  DIRECTIONALITY_FROM_TEXT
};
enum Style {
  DIAGONAL_STRIKE
};
class Range {
 public:
  Range(int begin, int end) : begin_(begin), end_(end) {}
 private:
  int begin_;
  int end_;
};

class RenderText {
 public:
  void SetDirectionalityMode(DirectionalityMode mode);
};
}  // namespace gfx

namespace url {
struct Component {
  int begin;
  int len;
  int end() const { return begin + len; }
  bool is_nonempty() const { return len > 0; }
};
}  // namespace url

namespace connection_security {
enum SecurityLevel {
  NONE,
  SECURITY_ERROR
};
}  // namespace connection_security

namespace extensions {
extern const char kExtensionScheme[];
}  // namespace extensions

namespace base {
std::u16string UTF8ToUTF16(const std::string& utf8);
}  // namespace base

typedef uint32_t SkColor;

class ChromeAutocompleteSchemeClassifier {
 public:
  explicit ChromeAutocompleteSchemeClassifier(void* profile);
};

class AutocompleteInput {
 public:
  static void ParseForEmphasizeComponents(
      const std::u16string& text,
      const ChromeAutocompleteSchemeClassifier& classifier,
      url::Component* scheme,
      url::Component* host);
};

class LocationBarView {
 public:
  enum ColorType {
    TEXT,
    DEEMPHASIZED_TEXT,
    SECURITY_TEXT
  };
  SkColor GetColor(connection_security::SecurityLevel level, ColorType type);
};

class OmniboxModel {
 public:
  bool CurrentTextIsURL() const;
  bool user_input_in_progress() const;
};

class OmniboxViewViews {
 public:
  void EmphasizeURLComponents();
  void SetColor(SkColor color);
  void ApplyColor(SkColor color, const gfx::Range& range);
  void SetStyle(gfx::Style style, bool apply);
  void ApplyStyle(gfx::Style style, bool apply, const gfx::Range& range);
  std::u16string text() const;
  void* profile();
  OmniboxModel* model();
  gfx::RenderText* GetRenderText();
  LocationBarView* location_bar_view_;
  connection_security::SecurityLevel security_level_;
};