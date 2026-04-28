#include <map>
#include <set>
#include <string>

class GURL {
public:
    std::string scheme() const;
    bool SchemeIs(const char* scheme) const;
};

class url {
public:
    class Origin {
    public:
        Origin(const GURL& url);
        bool operator<(const Origin& other) const;
    };
    static const char kFileScheme[];
};

namespace base {
    class FilePath {
    public:
        bool operator<(const FilePath& other) const;
    };
}

namespace net {
    bool FileURLToFilePath(const GURL& url, base::FilePath* path);
}

typedef std::map<std::string, bool> SchemeMap;
extern SchemeMap scheme_policy_;
extern std::set<url::Origin> origin_set_;
extern std::set<base::FilePath> request_file_set_;

template <typename T, typename U>
bool ContainsKey(const T& container, const U& key) {
    return container.find(key) != container.end();
}