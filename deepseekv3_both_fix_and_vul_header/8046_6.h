#include <memory>
#include <string>

namespace base {
class DictionaryValue {
public:
    bool GetString(const std::string& key, std::string* out_value);
    bool GetDouble(const std::string& key, double* out_value);
    bool GetInteger(const std::string& key, int* out_value);
    bool GetBoolean(const std::string& key, bool* out_value);
    bool HasKey(const std::string& key);
};
}

namespace webstore_install {
enum Result {
    ABORTED,
    NOT_PERMITTED,
    INVALID_WEBSTORE_RESPONSE
};
const char kInvalidWebstoreResponseError[] = "";
}

class GURL {
public:
    GURL();
    GURL(const std::string& url);
    bool is_valid() const;
    GURL Resolve(const std::string& relative) const;
};

class ExtensionInstallPrompt {
public:
    static constexpr double kMinExtensionRating = 0.0;
    static constexpr double kMaxExtensionRating = 5.0;
};

template <typename T>
class scoped_refptr {
public:
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    ~scoped_refptr() { delete ptr_; }
    T* operator->() { return ptr_; }
    T* get() { return ptr_; }
private:
    T* ptr_;
};

class RequestContext {
public:
    // Interface methods
};

class Profile {
public:
    RequestContext* GetRequestContext();
};

class WebstoreStandaloneInstaller;

class WebstoreInstallHelper {
public:
    WebstoreInstallHelper(WebstoreStandaloneInstaller* context, 
                         const std::string& id,
                         const std::string& manifest, 
                         const GURL& icon_url,
                         RequestContext* request_context);
    void Start();
};

class WebstoreStandaloneInstaller {
public:
    void OnWebstoreResponseParseSuccess(std::unique_ptr<base::DictionaryValue> webstore_data);
    void OnWebStoreDataFetcherDone();
    bool CheckRequestorAlive();
    void CompleteInstall(webstore_install::Result result, const std::string& error);
    bool CheckInlineInstallPermitted(const base::DictionaryValue& webstore_data, std::string* error);
    bool CheckRequestorPermitted(const base::DictionaryValue& webstore_data, std::string* error);
    
    std::string id_;
    Profile* profile_;
    std::string localized_user_count_;
    double average_rating_;
    int rating_count_;
    bool show_user_count_;
    std::string localized_name_;
    std::string localized_description_;
    std::unique_ptr<base::DictionaryValue> webstore_data_;
};

namespace extension_urls {
std::string GetWebstoreLaunchURL();
}

const char kManifestKey[] = "manifest";
const char kUsersKey[] = "users";
const char kAverageRatingKey[] = "average_rating";
const char kRatingCountKey[] = "rating_count";
const char kShowUserCountKey[] = "show_user_count";
const char kLocalizedNameKey[] = "localized_name";
const char kLocalizedDescriptionKey[] = "localized_description";
const char kIconUrlKey[] = "icon_url";

using webstore_install::kInvalidWebstoreResponseError;