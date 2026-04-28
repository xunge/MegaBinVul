class QString;

namespace OCC {
namespace SocketApi {
    void openPrivateLink(const QString &link);
}
}

namespace Utility {
    void openBrowser(const QString &link);
    void openBrowser(const QString &link, void *);
}