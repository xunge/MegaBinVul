#include <string>
#include <memory>
#include <functional>

class GURL {
public:
    bool is_valid() const;
    std::string spec() const;
    bool is_empty() const;
};

class ServiceWorkerProviderHost {
public:
    bool IsContextAlive() const;
    GURL document_url() const;
    GURL topmost_frame_url() const;
};

class ServiceWorkerContextWrapper {
public:
    ServiceWorkerProviderHost* GetProviderHost(int process_id, int provider_id);
    void RegisterServiceWorker(const GURL& pattern, const GURL& script_url,
                             ServiceWorkerProviderHost* provider_host,
                             std::function<void(bool)> callback);
};

class WebServiceWorkerError {
public:
    enum ErrorType {
        ErrorTypeAbort,
        ErrorTypeSecurity,
        ErrorTypeUnknown
    };
};

namespace base {
class UTF16String {
public:
    UTF16String();
    UTF16String operator+(const UTF16String& other);
};

UTF16String ASCIIToUTF16(const std::string& str);
UTF16String UTF8ToUTF16(const std::string& str);

template <typename T, typename... Args>
auto Bind(T&& func, Args&&... args) {
    return std::bind(std::forward<T>(func), std::forward<Args>(args)...);
}
}  // namespace base

namespace ServiceWorkerUtils {
bool ContainsDisallowedCharacter(const GURL& pattern, const GURL& script_url, std::string* error_message);
}  // namespace ServiceWorkerUtils

class ContentClient {
public:
    class Browser {
    public:
        bool AllowServiceWorker(const GURL& pattern, const GURL& topmost_frame_url, void* resource_context);
    };
    Browser* browser();
    static ContentClient* Get();
};

#define TRACE_EVENT0(category, name)
#define TRACE_EVENT_ASYNC_BEGIN2(category, name, id, arg1_name, arg1_val, arg2_name, arg2_val)

extern const char kServiceWorkerRegisterErrorPrefix[];
extern const char kShutdownErrorMessage[];
extern const char kNoDocumentURLErrorMessage[];
extern const char kDisallowedURLErrorMessage[];
extern const char kUserDeniedPermissionMessage[];

class ServiceWorkerMsg_ServiceWorkerRegistrationError {
public:
    ServiceWorkerMsg_ServiceWorkerRegistrationError(int thread_id, int request_id,
                                                  WebServiceWorkerError::ErrorType type,
                                                  base::UTF16String message);
};

class ServiceWorkerDispatcherHost {
public:
    void OnRegisterServiceWorker(int thread_id, int request_id, int provider_id,
                               const GURL& pattern, const GURL& script_url);
    void RegistrationComplete(int thread_id, int provider_id, int request_id);
    void Send(ServiceWorkerMsg_ServiceWorkerRegistrationError* msg);
    void BadMessageReceived();
    ServiceWorkerContextWrapper* GetContext();
    bool CanRegisterServiceWorker(const GURL& document_url, const GURL& pattern, const GURL& script_url);
    int render_process_id_;
    void* resource_context_;
    ContentClient* GetContentClient() { return ContentClient::Get(); }
};