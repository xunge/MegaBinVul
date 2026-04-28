#include <iostream>
#include <string>

#define Q_INVOKABLE
#define qCWarning(x) std::cerr

class UserModel {
public:
    class User {
    public:
        class TalkApp {
        public:
            std::string url() { return ""; }
        };
        TalkApp* talkApp() { return nullptr; }
        std::string server() { return ""; }
    };
    User* currentUser() { return nullptr; }
    
    Q_INVOKABLE void openCurrentAccountTalk();
};

class QDesktopServices {
public:
    static void openUrl(const std::string& url) {}
};

class Utility {
public:
    static void openBrowser(const std::string& url) {}
};

int lcActivity;