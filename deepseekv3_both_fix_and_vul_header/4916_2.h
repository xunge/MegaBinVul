#include <string>
#include <vector>
#include <cstring>

namespace url {
const char kStandardSchemeSeparator[] = "://";
const char kFileScheme[] = "file";
}  // namespace url

const char kAllUrlsPattern[] = "<all_urls>";
const char kPathSeparator[] = "/";

namespace base {
void SplitString(const std::string& str, char delimiter, std::vector<std::string>* result);
std::string JoinString(const std::vector<std::string>& parts, char delimiter);
}  // namespace base

class URLPattern {
public:
    enum ParseResult {
        PARSE_SUCCESS,
        PARSE_ERROR_MISSING_SCHEME_SEPARATOR,
        PARSE_ERROR_INVALID_SCHEME,
        PARSE_ERROR_WRONG_SCHEME_SEPARATOR,
        PARSE_ERROR_EMPTY_HOST,
        PARSE_ERROR_EMPTY_PATH,
        PARSE_ERROR_INVALID_PORT,
        PARSE_ERROR_INVALID_HOST_WILDCARD,
        PARSE_ERROR_INVALID_HOST
    };

    ParseResult Parse(const std::string& pattern);
    void SetMatchAllURLs(bool value);
    void SetMatchSubdomains(bool value);
    bool SetPort(const std::string& port);
    bool SetScheme(const std::string& scheme);
    bool IsStandardScheme(const std::string& scheme);
    void SetPath(const std::string& path);

private:
    std::string spec_;
    std::string scheme_;
    std::string host_;
    bool match_subdomains_ = false;
};

using base::JoinString;