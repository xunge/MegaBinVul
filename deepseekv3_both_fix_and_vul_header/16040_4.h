struct platform_device {
    struct {
        int dummy;
    } dev;
};

struct device_attribute {
    int dummy;
} dev_attr_role;

struct work_struct {
    int dummy;
};

struct usb_role_switch {
    int dummy;
};

struct usb_gadget {
    int dummy;
};

struct reset_control {
    int dummy;
};

struct dentry {
    int dummy;
};

struct renesas_usb3 {
    struct dentry *dentry;
    struct device_attribute dev_attr_role;
    struct work_struct role_work;
    struct usb_role_switch *role_sw;
    struct usb_gadget gadget;
    struct reset_control *usbp_rstc;
    void *ep0_req;
};

extern void* platform_get_drvdata(struct platform_device*);
extern void debugfs_remove_recursive(struct dentry*);
extern void device_remove_file(void*, struct device_attribute*);
extern void cancel_work_sync(struct work_struct*);
extern void usb_role_switch_unregister(struct usb_role_switch*);
extern void usb_del_gadget_udc(struct usb_gadget*);
extern void reset_control_assert(struct reset_control*);
extern void renesas_usb3_dma_free_prd(struct renesas_usb3*, void*);
extern void __renesas_usb3_ep_free_request(void*);
extern void pm_runtime_disable(void*);