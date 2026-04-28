#include <stdbool.h>

namespace url_parse {
    typedef struct {
        int begin;
        int len;
        int end() const { return begin + len; }
    } Component;

    typedef struct {
        Component username;
        Component password;
        Component host;
        Component port;
        Component path;
        Component query;
        Component ref;
    } Parsed;

    void ParseAfterScheme(const char* relative_url, int len, int begin, Parsed* relative_parsed);
}

typedef char CHAR;

struct CharsetConverter;
struct CanonOutput;

template<typename T>
struct Replacements {
    void SetUsername(const T* url, url_parse::Component component) {}
    void SetPassword(const T* url, url_parse::Component component) {}
    void SetHost(const T* url, url_parse::Component component) {}
    void SetPort(const T* url, url_parse::Component component) {}
    void SetPath(const T* url, url_parse::Component component) {}
    void SetQuery(const T* url, url_parse::Component component) {}
    void SetRef(const T* url, url_parse::Component component) {}
};

bool ReplaceStandardURL(const char* base_url, const url_parse::Parsed& base_parsed,
                       const Replacements<CHAR>& replacements,
                       CharsetConverter* query_converter,
                       CanonOutput* output,
                       url_parse::Parsed* out_parsed);