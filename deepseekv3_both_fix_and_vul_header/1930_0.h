#include <stddef.h>
#include <string.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#define DBG(fmt, ...) 
#define type2string(type) ""
static void process_response(int seq);
static void rtnl_newlink(struct nlmsghdr *hdr);
static void rtnl_dellink(struct nlmsghdr *hdr);
static void rtnl_newaddr(struct nlmsghdr *hdr);
static void rtnl_deladdr(struct nlmsghdr *hdr);
static void rtnl_newroute(struct nlmsghdr *hdr);
static void rtnl_delroute(struct nlmsghdr *hdr);
static void rtnl_newnduseropt(struct nlmsghdr *hdr);