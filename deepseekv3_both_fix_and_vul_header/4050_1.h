#include <stddef.h>
#include <stdbool.h>

struct nfc_dev;
struct nfc_llcp_local;

#define LLCP_DEFAULT_MIU 0
#define LLCP_DEFAULT_LTO 0

struct nfc_llcp_local {
    unsigned int remote_miu;
    unsigned int remote_lto;
};

struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
void nfc_llcp_socket_release(struct nfc_llcp_local *local, bool flag, int code);