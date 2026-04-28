#include <stddef.h>

struct platform_device;
struct media_device {
    void *devnode;
};
struct v4l2_device {
    // minimal definition
};
struct video_device {
    // minimal definition
};
struct v4l2_m2m_dev;

struct cedrus_dev {
    struct media_device mdev;
    struct v4l2_device v4l2_dev;
    struct video_device vfd;
    struct v4l2_m2m_dev *m2m_dev;
    int watchdog_work;
};

static inline void *platform_get_drvdata(struct platform_device *pdev) { return NULL; }
static inline void cancel_delayed_work_sync(int *work) {}
static inline int media_devnode_is_registered(void *devnode) { return 0; }
static inline void media_device_unregister(struct media_device *mdev) {}
static inline void v4l2_m2m_unregister_media_controller(struct v4l2_m2m_dev *m2m_dev) {}
static inline void media_device_cleanup(struct media_device *mdev) {}
static inline void v4l2_m2m_release(struct v4l2_m2m_dev *m2m_dev) {}
static inline void video_unregister_device(struct video_device *vfd) {}
static inline void v4l2_device_unregister(struct v4l2_device *v4l2_dev) {}
static inline void cedrus_hw_remove(struct cedrus_dev *dev) {}