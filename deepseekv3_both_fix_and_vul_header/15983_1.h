#include <pthread.h>

#define DVB_NET_DEVICES_MAX 10
#define DVB_DEVICE_NET 0

struct dvb_adapter;
struct dmx_demux;
struct dvb_device;

struct dvb_net {
    pthread_mutex_t ioctl_mutex;
    pthread_mutex_t remove_mutex;
    struct dmx_demux *demux;
    int state[DVB_NET_DEVICES_MAX];
    struct dvb_device *dvbdev;
};

extern const struct dvb_device dvbdev_net;

int dvb_register_device(struct dvb_adapter *adap, struct dvb_device **dvbdev,
                       const struct dvb_device *template, void *priv,
                       int type, int demux_sink_pads);