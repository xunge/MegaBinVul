#include <string>
#include <cstddef>

struct QStringRef {
    QStringRef(const char*);
};

struct QLatin1String {
    QLatin1String(const char*);
};

struct QXmlStreamAttributes {
    QStringRef value(QLatin1String) const;
};

struct QPainterPath {
    void setFillRule(int);
};

enum Qt {
    WindingFill
};

struct QSvgNode {};
struct QSvgHandler {};
struct QSvgPath : QSvgNode {
    QSvgPath(QSvgNode*, const QPainterPath&);
};

extern const char* lcSvgHandler;
void qCWarning(const char*, const char*);
bool parsePathDataFast(const QStringRef&, QPainterPath&);