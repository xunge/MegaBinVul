#include <string>

#define DCHECK_CURRENTLY_ON(thread)

namespace BrowserThread {
enum { UI };
}

class PageCaptureSaveAsMHTMLFunction {
public:
    void ReturnFailure(const std::string& error);
    void SendResponse(bool);
    void Release();
    std::string error_;
};