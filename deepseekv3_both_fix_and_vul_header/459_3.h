#include <stdint.h>

#define IWL_CMD_FAILED_MSK 0
#define ADD_STA_SUCCESS_MSK 1
#define ADD_STA_NO_ROOM_IN_TABLE 2
#define ADD_STA_NO_BLOCK_ACK_RESOURCE 3
#define ADD_STA_MODIFY_NON_EXIST_STA 4
#define STA_CONTROL_MODIFY_MSK 5
#define EIO 5

typedef uint8_t u8;
typedef uint32_t u32;

struct iwl_priv {
    struct {
        struct {
            struct {
                u8 sta_id;
                u8 addr[6];
                u8 mode;
            } sta;
        } stations[0];
        struct {
            int sta_lock;
        } *shrd;
    };
};

struct iwl_addsta_cmd {
    struct {
        u8 sta_id;
        u8 addr[6];
    } sta;
};

struct iwl_rx_packet {
    struct {
        u32 flags;
    } hdr;
    struct {
        struct {
            u32 status;
        } add_sta;
    } u;
};

#define IWL_ERR(priv, fmt, ...) 
#define IWL_DEBUG_INFO(priv, fmt, ...) 
#define IWL_DEBUG_ASSOC(priv, fmt, ...) 

static void spin_lock_irqsave(int *lock, unsigned long flags) {}
static void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static int iwl_sta_ucode_activate(struct iwl_priv *priv, u8 sta_id) { return 0; }