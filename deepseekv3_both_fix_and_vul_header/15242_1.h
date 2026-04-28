struct drm_device;
struct drm_file;

#define DRM_DEBUG(fmt, ...) 
#define LOCK_TEST_WITH_RETURN(dev, file_priv) (0)
#define DEV_INIT_TEST_WITH_RETURN(priv) (0)

int r128_do_engine_reset(struct drm_device *dev);