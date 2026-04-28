struct tty_struct {
    void *disc_data;
};

struct slcan {
    void *tx_work;
};

void schedule_work(void *work);