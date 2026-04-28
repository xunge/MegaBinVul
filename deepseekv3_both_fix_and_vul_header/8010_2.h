#include <unistd.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <semaphore.h>

struct drv_ctx_t {
    int video_driver_fd;
};

class omx_vdec {
public:
    ~omx_vdec();
    void* m_pmem_info;
    int m_pipe_in;
    int m_pipe_out;
    bool msg_thread_created;
    pthread_t msg_thread_id;
    bool async_thread_created;
    pthread_t async_thread_id;
    drv_ctx_t drv_ctx;
    pthread_mutex_t m_lock;
    pthread_mutex_t c_lock;
    pthread_mutex_t buf_lock;
    sem_t m_cmd_lock;
    bool perf_flag;
    struct {
        void end();
    } dec_time;
};

#define DEBUG_PRINT_HIGH(...)
#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_INFO(...)

void unsubscribe_to_events(int fd);