#include <map>
#include <memory>

#define DCHECK(condition) ((void)0)
#define CHECK(condition) ((void)0)

class NotificationService {
public:
    struct NoDetails {};
    static NotificationService* current();
    void Notify(int type, const void* source, NoDetails);
};

template <typename T>
class Source {
public:
    explicit Source(T* ptr) : ptr_(ptr) {}
    operator const void*() const { return ptr_; }
    T* ptr_;
};

class RenderWidgetHost {
public:
    virtual ~RenderWidgetHost() {}
};

class RenderWidgetHostView {
public:
    virtual void Destroy() = 0;
    virtual ~RenderWidgetHostView() {}
};

class RenderProcessHost {
public:
    virtual int GetID() const = 0;
    virtual void RemoveRoute(int routing_id) = 0;
    virtual ~RenderProcessHost() {}
};

class RenderWidgetHostDelegate {
public:
    virtual void RenderWidgetDeleted(void* widget) = 0;
    virtual ~RenderWidgetHostDelegate() {}
};

struct RenderWidgetHostID {
    int process_id;
    int routing_id;
    RenderWidgetHostID(int pid, int rid) : process_id(pid), routing_id(rid) {}
    bool operator<(const RenderWidgetHostID& other) const {
        return process_id < other.process_id || 
              (process_id == other.process_id && routing_id < other.routing_id);
    }
};

template <typename T>
struct DefaultSingletonTraits {
    static T* New() { return new T; }
};

template <typename T>
class Singleton {
public:
    static T& Get() {
        static T* instance = DefaultSingletonTraits<T>::New();
        return *instance;
    }
};

class RoutingIDWidgetMap : public std::map<RenderWidgetHostID, void*> {};
Singleton<RoutingIDWidgetMap> g_routing_id_widget_map;

enum {
    NOTIFICATION_RENDER_WIDGET_HOST_DESTROYED
};

class RenderWidgetHostImpl : public RenderWidgetHost {
public:
    void Destroy(bool also_delete);
    bool destroyed_;
    std::unique_ptr<RenderWidgetHostView> view_;
    RenderProcessHost* process_;
    int routing_id_;
    RenderWidgetHostDelegate* delegate_;
    void* owner_delegate_;
};