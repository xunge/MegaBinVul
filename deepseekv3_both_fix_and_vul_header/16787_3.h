#include <vector>
#include <string>
#include <iostream>

class ActivityListModel {
public:
    void triggerAction(int activityIndex, int actionIndex);
    void sendNotificationRequest(const std::string& accName, const std::string& link, const std::string& verb, int activityIndex);
};

struct Link {
    std::string _verb;
    std::string _link;
};

struct Activity {
    std::string _accName;
    std::vector<Link> _links;
};

std::vector<Activity> _finalList;

namespace QDesktopServices {
    void openUrl(const std::string& url) {}
}

namespace Utility {
    void openBrowser(const std::string& url) {}
}

#define qCWarning(category) std::cerr
#define lcActivity ""
#define emit
using QUrl = std::string;