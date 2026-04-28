#include <stdlib.h>

struct flb_config {
    /* 空结构体定义以满足编译要求 */
};

struct flb_in_mqtt_config;

void mqtt_config_free(struct flb_in_mqtt_config *ctx);