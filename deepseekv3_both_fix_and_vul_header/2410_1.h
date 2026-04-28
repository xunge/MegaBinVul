struct uwb_rc {
    struct {
        void *task;
    } uwbd;
};

void uwbd_flush(struct uwb_rc *rc);

void kthread_stop(void *task);