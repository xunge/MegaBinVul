#include <string>

class QString
{
public:
    QString();
    QString(const char* str);
    QString(const std::string& str);
};

class StelScriptMgr
{
public:
    bool runScript(const QString& fileName, const QString& includePath);
    bool prepareScript(QString& output, const QString& fileName, const QString& includePath);
    bool runPreprocessedScript(const QString& script, const QString& fileName);
};