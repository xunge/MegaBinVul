#include <string>
#include <cstdint>

class GURL {
public:
    const std::string& query() const;
    const std::string& ref() const;
    bool empty() const;
};

namespace url {
    struct Component {
        int len;
        bool is_nonempty() const { return len > 0; }
    };
    bool ExtractQueryKeyValue(const char* url, Component* query, Component* key, Component* value);
}

namespace net {
    struct UnescapeRule {
        enum Type {
            NORMAL = 1 << 0,
            SPACES = 1 << 1,
            URL_SPECIAL_CHARS = 1 << 2,
            CONTROL_CHARS = 1 << 3,
            SPOOFING_AND_CONTROL_CHARS = 1 << 4,
            REPLACE_PLUS_WITH_SPACE = 1 << 5
        };
    };
    inline UnescapeRule::Type operator|(UnescapeRule::Type a, UnescapeRule::Type b) {
        return static_cast<UnescapeRule::Type>(static_cast<int>(a) | static_cast<int>(b));
    }
    std::string UnescapeURLComponent(const std::string& component, UnescapeRule::Type rules);
    std::string UnescapeAndDecodeUTF8URLComponent(const std::string& component, UnescapeRule::Type rules);
}

namespace base {
    std::u16string UTF8ToUTF16(const std::string& src);
}

class EmbeddedSearchRequestParams {
public:
    EmbeddedSearchRequestParams(const GURL& url);
    std::u16string search_query;
    std::u16string original_query;
    std::string rlz_parameter_value;
    std::string input_encoding;
    std::string assisted_query_stats;
    static const char kSearchQueryKey[];
    static const char kOriginalQueryKey[];
    static const char kRLZParameterKey[];
    static const char kInputEncodingKey[];
    static const char kAssistedQueryStatsKey[];
    
    std::string GetComponent(const std::string& url, const url::Component& comp);
};