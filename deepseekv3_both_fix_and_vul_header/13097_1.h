#include <stdint.h>
#include <pthread.h>

typedef uint8_t u8;

struct cmd_obj {
    uint32_t cmdcode;
    void *parmbuf;
};

struct _adapter {
    struct {
        uint32_t pwr_mode;
        pthread_mutex_t mutex_lock;
    } pwrctrlpriv;
};

#define GEN_CMD_CODE(x) (x)
enum {
    _Read_MACREG,
    _Write_MACREG,
    _Read_BBREG,
    _Write_BBREG,
    _Read_RFREG,
    _Write_RFREG,
    _SetUsbSuspend,
    _JoinBss,
    _DRV_INT_CMD_
};

enum {
    PS_MODE_ACTIVE,
    PS_STATE_S4
};

void read_macreg_hdl(struct _adapter *padapter, u8 *pcmd);
void write_macreg_hdl(struct _adapter *padapter, u8 *pcmd);
void read_bbreg_hdl(struct _adapter *padapter, u8 *pcmd);
void write_bbreg_hdl(struct _adapter *padapter, u8 *pcmd);
void read_rfreg_hdl(struct _adapter *padapter, u8 *pcmd);
void write_rfreg_hdl(struct _adapter *padapter, u8 *pcmd);
void sys_suspend_hdl(struct _adapter *padapter, u8 *pcmd);
void r8712_joinbss_reset(struct _adapter *padapter);
void r8712_set_rpwm(struct _adapter *padapter, uint32_t state);
void r871x_internal_cmd_hdl(struct _adapter *padapter, void *parmbuf);
void r8712_free_cmd_obj(struct cmd_obj *pcmd);