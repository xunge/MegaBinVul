#define DVB_NET_DEVICES_MAX 10

struct dvb_device {
    int users;
    void *wait_queue;
};

struct dvb_net {
    void *remove_mutex;
    int exit;
    struct dvb_device *dvbdev;
    int state[DVB_NET_DEVICES_MAX];
};

void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);
void wait_event(void *wait_queue, int condition);
void dvb_unregister_device(struct dvb_device *dvbdev);
void dvb_net_remove_if(struct dvb_net *dvbnet, int i);