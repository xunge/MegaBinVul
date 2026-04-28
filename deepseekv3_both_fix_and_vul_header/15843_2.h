struct sk_buff;
struct flow_keys {
    /* minimal definition to satisfy compilation */
    unsigned int dummy[16]; 
};
typedef unsigned int u32;

extern u32 hashrnd;
extern void __flow_hash_secret_init(void);
extern u32 ___skb_get_hash(struct sk_buff *skb, struct flow_keys *keys, u32 hashrnd);
extern void __skb_set_sw_hash(struct sk_buff *skb, u32 hash, int flow_keys_have_l4);
extern int flow_keys_have_l4(const struct flow_keys *keys);