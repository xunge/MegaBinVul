#include <cassert>
#include <string>

#define DCHECK(condition) assert(condition)

class GURL {
public:
    bool is_valid() const;
};

bool AllOriginsMatch(const GURL& document_url, const GURL& pattern, const GURL& script_url);
bool OriginCanAccessServiceWorkers(const GURL& url);