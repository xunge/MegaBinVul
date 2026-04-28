struct bus_id_priv {
    int busid_lock;
};

static inline void spin_unlock(int *lock) {
    *lock = 0;
}