#include <vector>
#include <string>
#include <cstdlib>

class WebEmSession;
class request {
public:
    static std::string findValue(const request* req, const char* key);
};
class reply {
public:
    static void set_content(reply* rep, std::string::iterator begin, std::string::iterator end);
    static void add_header_attachment(reply* rep, const std::string& filename);
};
class CWebServer {
public:
    class m_sql {
    public:
        std::vector<std::vector<std::string>> safe_queryBlob(const char* query, ...);
    };
    m_sql m_sql;
    void GetFloorplanImage(WebEmSession& session, const request& req, reply& rep);
};