#include <stddef.h>

struct sdio_func;
struct hci_dev;

struct btsdio_data {
    void *work;
    struct hci_dev *hdev;
};

#define BT_DBG(fmt, ...) 
#define sdio_get_drvdata(func) NULL
#define sdio_set_drvdata(func, data) 
#define cancel_work_sync(work) 
#define hci_unregister_dev(hdev) 
#define hci_free_dev(hdev)