#include <string>
#include <unordered_map>
#include <cassert>

#define DCHECK_EQ(val1, val2) assert((val1) == (val2))

namespace webstore_install {
    enum class Result;
}

class ExtensionMsg_InlineWebstoreInstallResponse {
public:
    ExtensionMsg_InlineWebstoreInstallResponse(int, int, bool, const std::string&, webstore_install::Result);
};

class TabHelper {
public:
    void OnInlineInstallComplete(int install_id,
                                int return_route_id,
                                const std::string& extension_id,
                                bool success,
                                const std::string& error,
                                webstore_install::Result result);
    void OnInlineInstallComplete(int install_id,
                                int return_route_id,
                                bool success,
                                const std::string& error,
                                webstore_install::Result result);
protected:
    std::unordered_map<std::string, int> pending_inline_installations_;
    std::unordered_map<std::string, int> install_observers_;

    template<typename T>
    void Send(T* msg);
};