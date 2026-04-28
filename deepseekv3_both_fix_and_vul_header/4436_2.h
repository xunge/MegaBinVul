struct notifier_block {
    unsigned long dummy;
};

struct in_device {
    int dead;
    void *dev;
};

struct in_ifaddr {
    struct in_device *ifa_dev;
};

struct netdev_notifier_info {
    void *dummy1;
    void *dummy2;
};

#define NOTIFY_DONE 0x0000

static int netdev_notifier_info_init(struct netdev_notifier_info *info, void *dev) {
    return 0;
}

static int masq_device_event(struct notifier_block *this, unsigned long event, struct netdev_notifier_info *info) {
    return 0;
}