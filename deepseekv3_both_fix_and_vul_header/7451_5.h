#include <string>
#include <vector>
#include <cctype>

class QLatin1Char;

class QChar {
public:
    QChar() : ch(0) {}
    QChar(char c) : ch(c) {}
    bool operator==(char c) const { return ch == c; }
    bool operator==(const QLatin1Char& lc) const;
    bool isSpace() const { return std::isspace(ch); }
    char toLatin1() const { return ch; }
private:
    char ch;
};

class QString {
public:
    QString() {}
    QString(const char* str) : data(str) {}
    QChar at(int i) const { return i < (int)data.size() ? QChar(data[i]) : QChar(); }
    bool isSpace() const { return !data.empty() && std::isspace(data.back()); }
    int size() const { return data.size(); }
    bool isEmpty() const { return data.empty(); }
    void clear() { data.clear(); }
    QString& operator+=(const QChar& c) { data += c.toLatin1(); return *this; }
private:
    std::string data;
};

class QStringList : public std::vector<QString> {
public:
    void append(const QString& str) { push_back(str); }
    QStringList& operator+=(const QString& str) { push_back(str); return *this; }
};

class QLatin1Char {
public:
    QLatin1Char(char c) : ch(c) {}
    operator QChar() const { return QChar(ch); }
    char toLatin1() const { return ch; }
private:
    char ch;
};

bool QChar::operator==(const QLatin1Char& lc) const { return ch == lc.toLatin1(); }

class GPService {
public:
    QStringList splitCommand(const QString& command);
    QStringList splitCommand(QString command);
};