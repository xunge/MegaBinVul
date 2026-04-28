#include <stdint.h>

class Profile;

namespace base {
class FilePath {
public:
    FilePath();
};
class TimeDelta {
public:
    static TimeDelta FromMilliseconds(int64_t);
    static TimeDelta FromMinutes(int64_t);
    static TimeDelta FromHours(int64_t);
};
template <typename T>
class WeakPtrFactory {
public:
    explicit WeakPtrFactory(T* ptr) {}
    WeakPtrFactory() = delete;
};
}  // namespace base

class BaseSessionService {
public:
    BaseSessionService(int, Profile*, const base::FilePath&);
};

const int SESSION_RESTORE = 0;

class SessionService : public BaseSessionService {
public:
    explicit SessionService(Profile* profile);
private:
    bool has_open_trackable_browsers_;
    bool move_on_new_browser_;
    base::TimeDelta save_delay_in_millis_;
    base::TimeDelta save_delay_in_mins_;
    base::TimeDelta save_delay_in_hrs_;
    bool force_browser_not_alive_with_no_windows_;
    base::WeakPtrFactory<SessionService> weak_factory_{this};
    void Init();
};