#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdint>
#include <algorithm>

namespace Qt {
    enum CaseSensitivity { CaseInsensitive };
}

class QByteArray {
public:
    bool compare(const char* other, Qt::CaseSensitivity cs) const;
    bool operator==(const char* other) const;
    QByteArray& operator=(const QByteArray& other);
};

class QDateTime {
public:
    static QDateTime currentDateTimeUtc();
    QDateTime addSecs(int64_t seconds) const;
};

template<typename T1, typename T2>
using QPair = std::pair<T1, T2>;

template<typename T>
using QList = std::vector<T>;

class QHstsHeaderParser {
public:
    bool parse(const QList<QPair<QByteArray, QByteArray>>& headers);
private:
    QByteArray header;
    bool maxAgeFound;
    bool subDomainsFound;
    int64_t maxAge;
    QDateTime expiry;
    bool parseSTSHeader();
};