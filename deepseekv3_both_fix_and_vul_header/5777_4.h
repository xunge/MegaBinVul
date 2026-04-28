#include <memory>
#include <vector>
#include <cstddef>
#include <iterator>

#define FOR_EACH_OBSERVER(ObserverType, observer_list, method) \
  do { \
    for (auto& observer : (observer_list).observers_) \
      observer->method; \
  } while (0)

#define ENABLE_WEBRTC
#define OS_WIN

class RenderProcessObserver {
public:
    void OnRenderProcessShutdown();
};

class ChildThreadImpl {
public:
    static void Shutdown();
};

class WebView {
public:
    static void willEnterModalLoop();
    static void didExitModalLoop();
};

class RTCPeerConnectionHandler {
public:
    static void DestructAllHandlers();
};

class NPChannelBase {
public:
    static void CleanupChannels();
};

class MemoryObserver;
class WebDatabaseObserverImpl {
public:
    void WaitForAllDatabasesToClose();
};

class BlinkPlatformImpl {
public:
    WebDatabaseObserverImpl* web_database_observer_impl() { return nullptr; }
};
class DevToolsAgentMessageFilter;
class AudioInputMessageFilter;
class VCManager {
public:
    void* video_capture_message_filter() { return nullptr; }
};
class DBMessageFilter;
class CompositorMessageFilter;
class AudioMessageFilter;
class CompositorTaskGraphRunner {
public:
    void Shutdown();
};
class InputHandlerManager;
class InputEventFilter;
class EmbeddedWorkerDispatcher;
class MainThreadIndexedDBDispatcher;
class GpuChannel {
public:
    void DestroyChannel();
};
class RendererScheduler {
public:
    void Shutdown();
};

template <typename T>
class ObserverList {
public:
    std::vector<T*> observers_;
};

template <typename T>
class scoped_refptr {
public:
    T* get() { return nullptr; }
    T* operator->() { return nullptr; }
    void reset() {}
    operator bool() const { return false; }
    scoped_refptr& operator=(std::nullptr_t) { return *this; }
};

template <typename T>
class scoped_ptr {
public:
    T* get() { return nullptr; }
    T* operator->() { return nullptr; }
    void reset() {}
    operator bool() const { return false; }
};

class MessageLoop {
public:
    void RemoveTaskObserver(void* observer) {}
    static MessageLoop* current();
};

class Thread {
public:
    void Stop() {}
    void Join() {}
};

class TaskRunner {
public:
    void Cancel() {}
};

class LazyInstance {
public:
    class PointerType {
    public:
        void Set(void* ptr) {}
    };
    PointerType* Pointer() { return nullptr; }
};

namespace blink {
    void shutdown();
}

class RenderThreadImpl {
public:
    void Shutdown();
    MessageLoop* message_loop() { return nullptr; }
    void RemoveFilter(void* filter) {}

    ObserverList<RenderProcessObserver> observers_;
    scoped_ptr<MemoryObserver> memory_observer_;
    scoped_ptr<BlinkPlatformImpl> blink_platform_impl_;
    scoped_refptr<DevToolsAgentMessageFilter> devtools_agent_message_filter_;
    scoped_refptr<AudioInputMessageFilter> audio_input_message_filter_;
    scoped_ptr<VCManager> vc_manager_;
    scoped_refptr<DBMessageFilter> db_message_filter_;
    scoped_ptr<Thread> file_thread_;
    scoped_refptr<CompositorMessageFilter> compositor_message_filter_;
    scoped_ptr<Thread> media_thread_;
    scoped_refptr<AudioMessageFilter> audio_message_filter_;
    scoped_ptr<Thread> compositor_thread_;
    scoped_ptr<CompositorTaskGraphRunner> compositor_task_graph_runner_;
    std::vector<scoped_ptr<Thread>> compositor_raster_threads_;
    TaskRunner main_input_callback_;
    scoped_ptr<InputHandlerManager> input_handler_manager_;
    scoped_refptr<InputEventFilter> input_event_filter_;
    scoped_ptr<EmbeddedWorkerDispatcher> embedded_worker_dispatcher_;
    scoped_ptr<MainThreadIndexedDBDispatcher> main_thread_indexed_db_dispatcher_;
    void* main_thread_compositor_task_runner_;
    void* gpu_va_context_provider_;
    void* shared_main_thread_contexts_;
    scoped_refptr<GpuChannel> gpu_channel_;
    scoped_ptr<RendererScheduler> renderer_scheduler_;
    scoped_ptr<MessageLoop> main_message_loop_;
};

LazyInstance lazy_tls;