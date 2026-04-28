#include <linux/types.h>
#include <linux/string.h>

struct dmx_demux {
    int (*close)(struct dmx_demux*);
    int (*remove_frontend)(struct dmx_demux*, struct dmx_frontend*);
};

struct dvb_frontend_ops {
    void (*release)(struct dvb_frontend*);
};

struct dvb_frontend {
    struct dvb_frontend_ops ops;
};

struct dvb_adapter {
    int num;
};

struct dvb_demux {
    struct dmx_demux dmx;
};

struct dmxdev {
    struct dmx_demux *demux;
};

struct dvb_net {
    struct dvb_device *dvbdev;
};

struct dmx_frontend {
    int source;
};

struct ttusb_dec {
    struct dvb_adapter adapter;
    struct dvb_demux demux;
    struct dmxdev dmxdev;
    struct dvb_net dvb_net;
    struct dvb_frontend *fe;
    struct dmx_frontend frontend;
};

extern void dprintk(const char *fmt, ...);
extern void dvb_net_release(struct dvb_net *);
extern void dvb_dmxdev_release(struct dmxdev *);
extern void dvb_dmx_release(struct dvb_demux *);
extern int dvb_unregister_frontend(struct dvb_frontend *);
extern int dvb_unregister_adapter(struct dvb_adapter *);