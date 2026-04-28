#include <string>
#include <climits>

#define REQUEST_BEGIN "<?xml version=\"1.0\"?><methodCall><methodName>"
#define REQUEST_END_METHODNAME "</methodName>"
#define PARAMS_TAG "<params>"
#define PARAM_TAG "<param>"
#define PARAM_ETAG "</param>"
#define PARAMS_ETAG "</params>"
#define REQUEST_END "</methodCall>"

class XmlRpcValue {
public:
    enum Type { TypeArray };
    bool valid() const;
    Type getType() const;
    int size() const;
    const XmlRpcValue& operator[](int) const;
    std::string toXml() const;
};

class XmlRpcUtil {
public:
    static void log(int, const char*, ...);
    static void error(const char*, ...);
};

class XmlRpcClient {
private:
    std::string _request;
    std::string generateHeader(size_t);
public:
    bool generateRequest(const char* methodName, const XmlRpcValue& params);
};