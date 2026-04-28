#include <stdint.h>
#include <string.h>
#include <string>
#include <memory>

namespace pp {
class Var {
public:
    bool is_string() const;
    std::string AsString() const;
};
class VarDictionary : public Var {
public:
    void Set(const char*, const char*);
    void Set(const char*, const pp::Var&);
};
class TextInput_Dev {
public:
    TextInput_Dev(void*);
};
namespace URLUtil_Dev {
class Get {
public:
    pp::Var GetDocumentURL(void*);
};
Get* Get();
}
}  // namespace pp

namespace base {
class StringPiece {
public:
    StringPiece(const std::string&);
    bool starts_with(const char*) const;
};
}

extern const char* kChromeExtension;
extern const char* kChromePrint;
extern const char* kType;
extern const char* kJSSetTranslatedStringsType;
extern const char* kJSGetPasswordString;
extern const char* kJSLoadingString;
extern const char* kJSLoadFailedString;
extern const char* kJSResetPrintPreviewModeType;
extern uint32_t PP_RESOURCESTRING_PDFGETPASSWORD;
extern uint32_t PP_RESOURCESTRING_PDFLOADING;
extern uint32_t PP_RESOURCESTRING_PDFLOAD_FAILED;
extern uint32_t kBackgroundColorMaterial;
extern uint32_t kBackgroundColor;

class OutOfProcessInstance {
public:
    bool full_;
    uint32_t background_color_;
    std::string url_;
    std::unique_ptr<pp::TextInput_Dev> text_input_;

    bool Init(uint32_t argc, const char* argn[], const char* argv[]);
    void SetPluginToHandleFindRequests();
    pp::Var GetLocalizedString(uint32_t string_id);
    void PostMessage(const pp::Var& message);
    bool IsPrintPreviewUrl(const char* url);
    void LoadUrl(const char* url);
    class Engine {
    public:
        bool New(const char* url, const char* headers);
    };
    Engine* engine_;
};