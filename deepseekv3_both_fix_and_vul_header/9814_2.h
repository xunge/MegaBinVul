#include <stddef.h>

typedef int NotificationType;
typedef void* NotificationSource;
typedef void* NotificationDetails;

struct Extension {
    const char* id() const { return nullptr; }
};

template<typename T>
struct Details {
    explicit Details(const NotificationDetails& details) {}
    const T* ptr() const { return nullptr; }
};

#define DCHECK_EQ(a, b) ((void)0)

class TabContents {
public:
    void RemoveInfoBar(void* delegate) {}
    bool is_being_destroyed() const { return false; }
};

class ThemeInstalledInfoBarDelegate {
public:
    void Observe(NotificationType type, const NotificationSource& source, const NotificationDetails& details);
protected:
    const char* theme_id_;
    TabContents* tab_contents_;
};