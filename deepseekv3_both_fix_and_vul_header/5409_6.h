#include <string>
#include <string.h>

class GURL {
public:
    bool is_valid() const;
    std::string spec() const;
    bool is_empty() const;
};

class ServiceWorkerMsg_ServiceWorkerUnregistrationError {
public:
    ServiceWorkerMsg_ServiceWorkerUnregistrationError(
        int thread_id,
        int request_id,
        int error_type,
        const std::wstring& message);
};

class ServiceWorkerProviderHost {
public:
    bool IsContextAlive();
    GURL document_url();
    GURL topmost_frame_url();
};

class ServiceWorkerContextWrapper {
public:
    ServiceWorkerProviderHost* GetProviderHost(int render_process_id, int provider_id);
    void UnregisterServiceWorker(const GURL& pattern, void* callback);
};

class ServiceWorkerDispatcherHost {
public:
    void OnUnregisterServiceWorker(int thread_id, int request_id, int provider_id, const GURL& pattern);
    void Send(ServiceWorkerMsg_ServiceWorkerUnregistrationError* msg);
    void BadMessageReceived();
    bool CanUnregisterServiceWorker(const GURL& document_url, const GURL& pattern);
    ServiceWorkerContextWrapper* GetContext();
    int render_process_id_;
    void* resource_context_;
    void UnregistrationComplete(int thread_id, int request_id);
};

class ContentBrowserClient {
public:
    bool AllowServiceWorker(const GURL& pattern, const GURL& frame_url, void* resource_context);
};

class ContentClient {
public:
    ContentBrowserClient* browser();
};

ContentClient* GetContentClient();

extern const char kShutdownErrorMessage[];
extern const char kNoDocumentURLErrorMessage[];
extern const char kServiceWorkerUnregisterErrorPrefix[];
extern const char kDisallowedURLErrorMessage[];
extern const char kUserDeniedPermissionMessage[];

namespace base {
    std::wstring ASCIIToUTF16(const char* str);
    void* Bind(void (ServiceWorkerDispatcherHost::*func)(int, int), 
               ServiceWorkerDispatcherHost* obj, int arg1, int arg2);
}

namespace blink {
enum WebServiceWorkerError {
    ErrorTypeAbort,
    ErrorTypeSecurity,
    ErrorTypeUnknown
};
}  // namespace blink

namespace content {
class ResourceContext;
}  // namespace content

namespace WebServiceWorkerError {
    enum ErrorType {
        ErrorTypeAbort = blink::WebServiceWorkerError::ErrorTypeAbort,
        ErrorTypeSecurity = blink::WebServiceWorkerError::ErrorTypeSecurity,
        ErrorTypeUnknown = blink::WebServiceWorkerError::ErrorTypeUnknown
    };
}

#define TRACE_EVENT0(category, name)
#define TRACE_EVENT_ASYNC_BEGIN1(category, name, id, key, value)