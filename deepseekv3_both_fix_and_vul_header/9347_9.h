#include <string>
#include <cstdint>
#include <iostream>
#include <sstream>

namespace v8 {
class Value {
public:
    bool IsNumber() const;
    int32_t IntegerValue() const;
    uint32_t Uint32Value() const;
};

template<typename T>
class FunctionCallbackInfo {
public:
    int Length() const;
    const T* operator[](int index) const;
};
}

namespace content {
class RenderView;
}

struct GURL {
    bool is_valid() const;
    bool SchemeIs(const char* scheme) const;
    std::string spec() const;
};

std::ostream& operator<<(std::ostream& os, const GURL& url);

struct base {
    typedef std::u16string string16;
};

struct InstantMostVisitedItem {
    GURL url;
};

enum WindowOpenDisposition {
    CURRENT_TAB
};

namespace url {
extern const char kJavaScriptScheme[];
}

class SearchBox {
public:
    static SearchBox* Get(content::RenderView* render_view);
    bool GetMostVisitedItemWithID(int id, InstantMostVisitedItem* item);
    void NavigateToURL(const GURL& url, WindowOpenDisposition disposition, bool is_most_visited_item_url);
};

namespace internal {
    GURL ResolveURL(const GURL& current_url, const base::string16& possibly_relative_url);
}

class SearchBoxExtensionWrapper {
public:
    void NavigateContentWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
};

content::RenderView* GetRenderView();
base::string16 V8ValueToUTF16(const v8::Value* value);
GURL GetCurrentURL(content::RenderView* render_view);
void ThrowInvalidParameters(const v8::FunctionCallbackInfo<v8::Value>& args);

#define DVLOG(level) if (level <= 1) std::cerr