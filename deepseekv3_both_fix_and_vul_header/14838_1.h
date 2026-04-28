#include <string>
#include <memory>

namespace base {
class FilePath;
class TimeDelta {
public:
    static TimeDelta FromMilliseconds(int ms);
    static TimeDelta FromMinutes(int mins);
    static TimeDelta FromHours(int hrs);
};
}

class BaseSessionService {
public:
    BaseSessionService(int type, void* ptr, const base::FilePath& path);
};

class SessionService : public BaseSessionService {
public:
    explicit SessionService(const base::FilePath& save_path);
private:
    bool has_open_trackable_browsers_;
    bool move_on_new_browser_;
    base::TimeDelta save_delay_in_millis_;
    base::TimeDelta save_delay_in_mins_;
    base::TimeDelta save_delay_in_hrs_;
    bool force_browser_not_alive_with_no_windows_;
    void* weak_factory_;
    void Init();
};

const int SESSION_RESTORE = 0;