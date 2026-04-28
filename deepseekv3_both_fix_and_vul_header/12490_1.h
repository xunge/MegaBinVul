#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

typedef struct {
    uint32_t chain_id;
    struct {
        uint8_t *bytes;
    } data_initial_chunk;
} EthereumSignTx;

typedef struct {
} TokenType;

typedef enum {
    ButtonRequestType_ButtonRequest_ConfirmOutput
} ButtonRequestType;

typedef struct {
    uint8_t bytes[32];
} bignum256;

void bn_from_bytes(const uint8_t *bytes, size_t len, void *bn);
bool isAddLiquidityEthCall(const EthereumSignTx *msg);
bool isRemoveLiquidityEthCall(const EthereumSignTx *msg);
const TokenType *tokenByChainAddress(uint32_t chain_id, const uint8_t *address);
void ethereumFormatAmount(const void *amount, const TokenType *token, uint32_t chain_id, char *buf, size_t buf_len);
void confirm(ButtonRequestType type, const char *title, const char *body, ...);
bool confirmFromAccountMatch(const EthereumSignTx *msg, const char *str);