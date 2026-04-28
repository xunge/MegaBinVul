#include <stdbool.h>

#define Key_Backspace 0x01000003
#define Key_Return 0x01000004
#define Key_Escape 0x01000000
#define MAX_PASSWORD_LENGTH 256
#define TRUE true
#define emit

class KPasswordDlg;
class QKeyEvent;
class QString;
class QTimer;
class QLabel;
class QLocale;

class QKeyEvent {
public:
    int key() const;
    int ascii() const;
};

class QString {
public:
    int length() const;
    void truncate(int pos);
    QString& operator=(const char*);
    QString& operator+=(char);
};

class QTimer {
public:
    void stop();
    void start(int interval, bool singleShot);
    void changeInterval(int interval);
};

class QLabel {
public:
    void setText(const char*);
};

class QLocale {
public:
    const char* translate(const char*);
};

class KPasswordDlg {
public:
    void keyPressed(QKeyEvent* e);
    void passOk();
    void passCancel();
};

extern bool stars;
extern QString password;
extern QTimer timer;
extern int timerMode;
extern QLabel* label;
extern QLocale* glocale;

bool tryPassword();
void showStars();