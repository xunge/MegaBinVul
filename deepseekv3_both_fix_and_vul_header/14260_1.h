#include <stdint.h>
#include <stddef.h>

typedef struct {
    int sock;
} TCP_Secure_Connection;

void kill_sock(int sock);
void crypto_memzero(void *data, size_t len);