struct ipmi_user {
    void *release_barrier;
    void *refcount;
};

void _ipmi_destroy_user(struct ipmi_user *user);
void cleanup_srcu_struct(void *sp);
void kref_put(void *kref, void (*release)(void *kref));
void free_user(void *kref);