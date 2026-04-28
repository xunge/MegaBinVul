#include <stdlib.h>

struct crypto_instance;
struct crypto_aead_spawn {
    // 最小化定义以满足编译
    int dummy;
};

struct pcrypt_instance_ctx {
    struct crypto_aead_spawn spawn;
};

// 声明函数以避免隐式声明警告
void *crypto_instance_ctx(struct crypto_instance *inst);
void crypto_drop_aead(struct crypto_aead_spawn *spawn);
void kfree(const void *objp);