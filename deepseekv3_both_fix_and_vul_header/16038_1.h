#include <stdlib.h>

struct dmx_frontend {
    int dummy;
};

struct pci_dev {
    int irq;
    void *driver_data;
};

struct dmx_demux {
    void (*close)(struct dmx_demux*);
    void (*disconnect_frontend)(struct dmx_demux*);
    void (*remove_frontend)(struct dmx_demux*, struct dmx_frontend*);
};

struct dvb_demux {
    struct dmx_demux dmx;
};

struct dvb_adapter {
    int dummy;
};

struct dvb_net {
    int dummy;
};

struct dmxdev {
    int dummy;
};

struct dvb_frontend {
    int dummy;
};

struct i2c_adapter {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct dm1105_dev {
    struct dvb_adapter dvb_adapter;
    struct dvb_demux demux;
    struct dvb_net dvbnet;
    struct dmx_frontend mem_frontend;
    struct dmx_frontend hw_frontend;
    struct dmxdev dmxdev;
    struct dvb_frontend *fe;
    struct i2c_adapter i2c_adap;
    void *io_mem;
    int devcount;
    struct {
        struct work_struct work;
    } ir;
};

int dm1105_devcount;
void dm1105_ir_exit(struct dm1105_dev *dev);
void dm1105_hw_exit(struct dm1105_dev *dev);
void *pci_get_drvdata(struct pci_dev *pdev);
void free_irq(unsigned int irq, void *dev_id);
void pci_iounmap(struct pci_dev *dev, void *addr);
void pci_release_regions(struct pci_dev *pdev);
void pci_disable_device(struct pci_dev *dev);
void kfree(const void *objp);
void dvb_net_release(struct dvb_net *dvbnet);
void dvb_unregister_frontend(struct dvb_frontend *fe);
void dvb_dmxdev_release(struct dmxdev *dmxdev);
void dvb_dmx_release(struct dvb_demux *dvbdemux);
void dvb_unregister_adapter(struct dvb_adapter *adapter);
void i2c_del_adapter(struct i2c_adapter *adap);
void cancel_work_sync(struct work_struct *work);