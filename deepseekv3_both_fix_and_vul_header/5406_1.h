#include <string>
#include <cassert>

class GURL {
 public:
  GURL();
  explicit GURL(const std::string& url);
  bool is_valid() const;
  GURL GetOrigin() const;
  bool operator==(const GURL& other) const;
};

bool OriginCanAccessServiceWorkers(const GURL& url);

#define DCHECK(condition) assert(condition)