#include <stdlib.h>

typedef struct IDEState {
    // 基本字段定义
    int dummy;  // 示例字段，实际应根据IDEState的真实定义补充
} IDEState;

typedef struct AHCIDevice {
    struct {
        IDEState ifs[2];
    } port;
} AHCIDevice;

typedef struct AHCIState {
    int ports;
    AHCIDevice *dev;
} AHCIState;

void ide_exit(IDEState *s);
void g_free(void *ptr);