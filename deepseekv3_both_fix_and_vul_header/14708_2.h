#include <memory>

namespace content {
class RenderView;
class RenderViewObserver {
public:
    explicit RenderViewObserver(RenderView* render_view);
};
template <typename T> class RenderViewObserverTracker {
public:
    explicit RenderViewObserverTracker(RenderView* render_view);
};
}

template <typename T> class scoped_ptr {
public:
    T* operator->() const;
    T* get() const;
    scoped_ptr();
    ~scoped_ptr();
    scoped_ptr(scoped_ptr&& other);
    scoped_ptr& operator=(scoped_ptr&& other);
    scoped_ptr Pass();
};

class PrintWebViewHelper : public content::RenderViewObserver,
                          public content::RenderViewObserverTracker<PrintWebViewHelper> {
public:
    class Delegate {
    public:
        virtual ~Delegate() {}
        virtual bool IsPrintPreviewEnabled() = 0;
    };

    template <typename T> class WeakPtrFactory {
    public:
        explicit WeakPtrFactory(T* ptr) {}
    };

    PrintWebViewHelper(content::RenderView* render_view,
                      scoped_ptr<Delegate> delegate);
private:
    scoped_ptr<Delegate> delegate_;
    bool reset_prep_frame_view_;
    bool is_print_ready_metafile_sent_;
    bool ignore_css_margins_;
    bool is_scripted_printing_blocked_;
    bool notify_browser_of_print_failure_;
    bool print_for_preview_;
    bool print_node_in_progress_;
    bool is_loading_;
    bool is_scripted_preview_delayed_;
    int ipc_nesting_level_;
    WeakPtrFactory<PrintWebViewHelper> weak_ptr_factory_;
};

void DisablePreview();