#include <cstddef>

struct QObject {
    QObject(QObject* parent = nullptr) {}
};

template<typename T> 
struct QFutureWatcher {
    QFutureWatcher(QObject* parent) {}
};

struct FramebufferModel : QObject {
    FramebufferModel(QObject* parent);
    void* m_pixelBuffer;
    int m_width;
    int m_height;
    bool m_isImageLoaded;
    int m_exposure;
    QFutureWatcher<void>* m_imageLoadingWatcher;
    QFutureWatcher<void>* m_imageEditingWatcher;
    float m_pixelAspectRatio;
};