#include <stdlib.h>
#include <string.h>

typedef char gchar;
#define WEBKIT_WEB_VIEW(x) (x)
#define kJSClassAttributeNone 0

typedef struct {
    struct {
        void* classref;
    } js;
} UzblJS;

typedef struct _GString GString;
typedef struct _WebKitWebView WebKitWebView;
typedef struct _WebKitWebFrame WebKitWebFrame;
typedef void* JSGlobalContextRef;
typedef void* JSObjectRef;
typedef void* JSStringRef;
typedef void* JSValueRef;

static UzblJS uzbl;

void js_init(void);
WebKitWebFrame* webkit_web_view_get_main_frame(WebKitWebView*);
JSGlobalContextRef webkit_web_frame_get_global_context(WebKitWebFrame*);
JSObjectRef JSContextGetGlobalObject(JSGlobalContextRef);
JSStringRef JSStringCreateWithUTF8CString(const char*);
void JSObjectSetProperty(JSGlobalContextRef, JSObjectRef, JSStringRef, JSObjectRef, int, void*);
JSObjectRef JSObjectMake(JSGlobalContextRef, void*, void*);
JSValueRef JSEvaluateScript(JSGlobalContextRef, JSStringRef, JSObjectRef, void*, int, void*);
int JSValueIsUndefined(JSGlobalContextRef, JSValueRef);
JSStringRef JSValueToStringCopy(JSGlobalContextRef, JSValueRef, void*);
size_t JSStringGetMaximumUTF8CStringSize(JSStringRef);
void JSStringGetUTF8CString(JSStringRef, char*, size_t);
void g_string_assign(GString*, const char*);
void JSStringRelease(JSStringRef);
void JSObjectDeleteProperty(JSGlobalContextRef, JSObjectRef, JSStringRef, void*);