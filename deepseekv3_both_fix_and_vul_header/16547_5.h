#include <string>
#include <vector>

class QString;

class QLatin1String {
public:
    QLatin1String(const char*);
    operator QString() const;
};

class QString {
public:
    QString();
    QString(const char *str);
    bool isEmpty() const;
    QString arg(const QString &) const;
    static QString fromLatin1(const char *);
};

class QStringList : public std::vector<QString> {
public:
    QStringList(std::initializer_list<QString> init);
    bool contains(const QString &) const;
};

class QUrl {
public:
    QUrl(const QString &);
    QString scheme() const;
    QString toString() const;
};

class QObject {
public:
    static QString tr(const char *);
};

class QMessageBox {
public:
    enum Icon { Warning };
    void setText(const QString &);
    void setInformativeText(const QString &);
    void setDetailedText(const QString &);
    void setIcon(Icon);
    int exec();
};

class QTreeWidgetItem {
};

class ServerItem : public QTreeWidgetItem {
public:
    QString qsUrl;
};

class QDesktopServices {
public:
    static void openUrl(const QUrl &);
};

class QTreeWidget {
public:
    QTreeWidgetItem *currentItem() const;
};

class ConnectDialog {
public:
    void on_qaUrl_triggered();
};

extern QTreeWidget *qtwServers;