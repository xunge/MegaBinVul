#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <sys/types.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

typedef struct lladdr_info {
    // placeholder structure
} lladdr_info;

#define ND_PRINT(args)

/* Ethernet protocol types */
#define ETHERTYPE_DN         0x6003  /* DECnet */
#define ETHERTYPE_ATALK      0x809B  /* AppleTalk */
#define ETHERTYPE_AARP       0x80F3  /* AppleTalk ARP */
#define ETHERTYPE_ISO        0x8100  /* ISO protocols */
#define ETHERTYPE_PPPOED     0x8863  /* PPPoE Discovery */
#define ETHERTYPE_PPPOES     0x8864  /* PPPoE Session */
#define ETHERTYPE_PPPOED2    0x8865  /* PPPoE Discovery v2 */
#define ETHERTYPE_PPPOES2    0x8866  /* PPPoE Session v2 */
#define ETHERTYPE_EAPOL      0x888E  /* EAP over LAN */
#define ETHERTYPE_RRCP       0x8899  /* RRCP */
#define ETHERTYPE_PPP        0x880B  /* PPP */
#define ETHERTYPE_MPCP       0x8808  /* Multi-Point Control Protocol */
#define ETHERTYPE_SLOW       0x8809  /* Slow Protocol */
#define ETHERTYPE_CFM        0x8902  /* Connectivity Fault Management */
#define ETHERTYPE_CFM_OLD    0x0001  /* Old CFM */
#define ETHERTYPE_LLDP       0x88CC  /* Link Layer Discovery Protocol */
#define ETHERTYPE_NSH        0x894F  /* Network Service Header */
#define ETHERTYPE_LOOPBACK   0x9000  /* Loopback */
#define ETHERTYPE_MPLS       0x8847  /* MPLS unicast */
#define ETHERTYPE_MPLS_MULTI 0x8848  /* MPLS multicast */
#define ETHERTYPE_TIPC       0x88CA  /* TIPC */
#define ETHERTYPE_MS_NLB_HB  0x886F  /* MS NLB heartbeat */
#define ETHERTYPE_GEONET_OLD 0x8060  /* Old GeoNetworking */
#define ETHERTYPE_GEONET     0x8947  /* GeoNetworking */
#define ETHERTYPE_CALM_FAST  0x88B5  /* CALM FAST */
#define ETHERTYPE_AOE        0x88A2  /* ATA over Ethernet */
#define ETHERTYPE_MEDSA      0x88CD  /* MEDSA */
#define ETHERTYPE_LAT        0x6004  /* LAT */
#define ETHERTYPE_SCA        0x6007  /* SCA */
#define ETHERTYPE_MOPRC      0x6002  /* MOP Remote Console */
#define ETHERTYPE_MOPDL      0x6001  /* MOP Dump/Load */
#define ETHERTYPE_IEEE1905_1 0x893A  /* IEEE 1905.1 */