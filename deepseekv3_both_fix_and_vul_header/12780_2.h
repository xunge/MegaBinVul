class QUrl {
public:
    QUrl();
    QUrl(const QUrl& other);
    ~QUrl();
    QUrl& operator=(const QUrl& other);
};

class QWebEnginePage {
public:
    void setUrl(const QUrl &url);
};

class WebEnginePage : public QWebEnginePage {
private:
    QUrl _rootUrl;
public:
    void setUrl(const QUrl &url);
};