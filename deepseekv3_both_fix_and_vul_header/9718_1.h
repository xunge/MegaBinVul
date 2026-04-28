struct seq_oss_devinfo {
    int port;
    void *cseq;
};

extern int snd_seq_event_port_detach(void *cseq, int port);
extern int debug_printk(const char *fmt, ...);