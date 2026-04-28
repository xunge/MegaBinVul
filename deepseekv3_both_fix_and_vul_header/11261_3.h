#include <vector>
#include <string>

class QString {
public:
    QString();
    QString(const char* str);
    QString(const std::string& str);
    std::string toStdString() const;
    bool startsWith(const QString& str) const;
    QString operator+(const QString& other) const;
    QString operator+(const char* str) const;
    QString& operator=(const QString& other);
    QString& operator=(const char* str);
};

class QStringList : public std::vector<QString> {
public:
    QStringList();
    void append(const QString& str);
};

class QDir {
public:
    QDir(const QString& path);
    QString absolutePath() const;
    QString absoluteFilePath(const QString& fileName) const;
    static QString cleanPath(const QString& path);
};

struct QuaZip {
    enum Mode { mdUnzip };
    bool open(Mode mode);
    bool goToFirstFile();
    bool goToNextFile();
    QString getCurrentFileName();
    void close();
    int getZipError();
};

class JlCompress {
public:
    static QStringList extractDir(QuaZip &zip, const QString &dir);
    static bool extractFile(QuaZip *zip, const QString &fileName, const QString &fileDest);
    static void removeFile(const QStringList &listFile);
};