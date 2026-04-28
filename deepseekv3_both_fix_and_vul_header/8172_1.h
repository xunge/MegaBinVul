struct static_key {
    int enabled;
};

extern struct static_key sched_feat_keys[];

static inline void static_key_enable(struct static_key *key)
{
    key->enabled = 1;
}