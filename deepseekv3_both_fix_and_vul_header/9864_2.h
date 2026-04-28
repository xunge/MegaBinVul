#include <stdint.h>

struct sk_buff;
struct vlan_group;

struct napi_struct {
    // 最小化定义以满足编译
    int dummy;
};

struct igb_adapter {
    struct vlan_group *vlgrp;
};

struct igb_q_vector {
    struct igb_adapter *adapter;
    struct napi_struct napi;
};

typedef uint16_t u16;

// 声明函数以避免隐式声明警告
void vlan_gro_receive(struct napi_struct *napi, struct vlan_group *vlgrp, u16 vlan_tag, struct sk_buff *skb);
void napi_gro_receive(struct napi_struct *napi, struct sk_buff *skb);