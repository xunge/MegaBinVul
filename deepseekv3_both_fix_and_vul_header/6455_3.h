#include <cstddef>

class Log {
public:
    void Debug(const char*, const char*, ...);
    void Error(const char*, const char*, ...);
};

class FileTimer {};

class ForkHandler {
public:
    void RegisterFileTimer(FileTimer*);
};

class PlugInManager {
public:
    void ProcessEnvironmentSettings();
};

class DefaultEnv {
public:
    void Initialize();
    void SetUpLog();
};

extern Log* sLog;
extern DefaultEnv* sEnv;
extern ForkHandler* sForkHandler;
extern FileTimer* sFileTimer;
extern PlugInManager* sPlugInManager;

bool XrdOucPreload(const char* lib, char* errBuff, int buffSize);