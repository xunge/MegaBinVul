#include <pthread.h>
#include <stdlib.h>

struct dmxdev {
    pthread_mutex_t mutex;
    int exit;
    struct dvb_device *dvbdev;
    struct dvb_device *dvr_dvbdev;
    void *filter;
    struct dmx_demux *demux;
};

struct dvb_device {
    int users;
    pthread_cond_t wait_queue;
};

struct dmx_demux {
    void (*close)(struct dmx_demux *demux);
};

void dvb_unregister_device(struct dvb_device *dvbdev);