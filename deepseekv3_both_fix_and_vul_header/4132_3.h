#include <string>

class GURL {
public:
    GURL(const std::string& origin);
    std::string GetOrigin();
};

class ResourceContext {
public:
    std::string GetMediaDeviceIDSalt();
};

class WebrtcAudioPrivateFunction {
public:
    std::string CalculateHMACImpl(const std::string& raw_id);
    std::string device_id_salt();
    GURL source_url();
    ResourceContext* resource_context();
};

class BrowserThread {
public:
    enum { IO };
};

#define DCHECK_CURRENTLY_ON(thread)

namespace media {
class AudioManagerBase {
public:
    static const char kDefaultDeviceId[];
};
const char AudioManagerBase::kDefaultDeviceId[] = "default";
} // namespace media

namespace content {
std::string GetHMACForMediaDeviceID(const std::string& salt,
                                   const GURL& security_origin,
                                   const std::string& raw_id);
} // namespace content