#include <string>
#include <vector>

struct QLatin1String {
    QLatin1String(const char*);
    operator std::string() const;
    bool operator==(const std::string&) const;
    bool operator==(const QLatin1String&) const;
};

struct QString {
    QString();
    QString(const char*);
    QString(const std::string&);
    operator std::string() const;
    bool operator==(const QLatin1String&) const;
    bool operator==(const QString&) const;
    bool operator!=(const char*) const;
};

struct QDomElement {
    QString tagName() const;
    QString attribute(const QLatin1String&) const;
    struct QDomNodeList childNodes() const;
    QDomElement firstChildElement(const QLatin1String& = QLatin1String("")) const;
    bool isNull() const;
};

struct QDomNodeList {
    int size() const;
    struct QDomNode at(int) const;
};

struct QDomNode {
    QDomElement toElement() const;
};

struct Jid {
    Jid(const QString&);
    bool compare(const Jid&, bool) const;
};

struct Stanza {
    Stanza();
    bool isNull() const;
};

struct Message {
    enum CarbonDir { NoCarbon, Received, Sent };
    bool fromStanza(const Stanza&, int, int);
    void setForwardedFrom(const Jid&);
    void setCarbonDirection(CarbonDir);
};

struct Stream {
    Stanza createStanza(const std::string&) const;
};

struct Client {
    Stream& stream();
    int manualTimeZoneOffset() const;
    int timeZoneOffset() const;
};

class JT_PushMessage {
public:
    bool take(const QDomElement &e);
    Client* client();
    void message(const Message &m);
    std::string addCorrectNS(const QDomElement&) const;
};

#define emit