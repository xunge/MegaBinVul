#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    uint8_t private_key[32];
} HDNode;

typedef struct {
    bool has_value;
    struct { size_t size; uint8_t bytes[32]; } value;
    bool has_data_initial_chunk;
    struct { size_t size; uint8_t bytes[1024]; } data_initial_chunk;
    bool has_to;
    struct { size_t size; uint8_t bytes[20]; } to;
    bool has_nonce;
    struct { size_t size; uint8_t bytes[8]; } nonce;
    bool has_chain_id;
    uint32_t chain_id;
    bool has_tx_type;
    uint8_t tx_type;
    bool has_type;
    uint8_t type;
    bool has_data_length;
    uint32_t data_length;
    bool has_max_fee_per_gas;
    struct { size_t size; uint8_t bytes[32]; } max_fee_per_gas;
    bool has_max_priority_fee_per_gas;
    struct { size_t size; uint8_t bytes[32]; } max_priority_fee_per_gas;
    bool has_gas_price;
    struct { size_t size; uint8_t bytes[32]; } gas_price;
    bool has_gas_limit;
    struct { size_t size; uint8_t bytes[32]; } gas_limit;
    uint8_t address_type;
} EthereumSignTx;

typedef struct {
    // Define fields as needed
} EthereumTxRequest;

typedef struct {
    // Define fields as needed
} TokenType;

typedef enum {
    FailureType_Failure_SyntaxError,
    FailureType_Failure_Other,
    FailureType_Failure_ActionCancelled
} FailureType;

typedef enum {
    ButtonRequestType_ButtonRequest_ConfirmOutput,
    ButtonRequestType_ButtonRequest_ConfirmTransferToAccount,
    ButtonRequestType_ButtonRequest_SignTx,
    ButtonRequestType_ButtonRequest_Other
} ButtonRequestType;

typedef enum {
    OutputAddressType_TRANSFER
} OutputAddressType;

typedef enum {
    ETHEREUM_TX_TYPE_LEGACY,
    ETHEREUM_TX_TYPE_EIP_1559
} EthereumTxType;

extern bool ethereum_signing;
extern uint32_t chain_id;
extern uint8_t wanchain_tx_type;
extern uint8_t ethereum_tx_type;
extern uint32_t data_total;
extern uint32_t data_left;
extern uint8_t privkey[32];
extern EthereumTxRequest msg_tx_request;
extern void* keccak_ctx;

const char* _(const char* str);

void sha3_256_Init(void* ctx);
void fsm_sendFailure(FailureType type, const char* message);
void ethereum_signing_abort(void);
bool ethereum_signing_check(const EthereumSignTx* msg);
bool ethereum_contractHandled(uint32_t data_total, const EthereumSignTx* msg, const HDNode* node);
bool ethereum_contractConfirmed(uint32_t data_total, const EthereumSignTx* msg, const HDNode* node);
bool ethereum_cFuncHandled(const EthereumSignTx* msg);
bool ethereum_cFuncConfirmed(uint32_t data_total, const EthereumSignTx* msg);
const TokenType* tokenByChainAddress(uint32_t chain_id, const uint8_t* address);
bool ethereum_isStandardERC20Transfer(const EthereumSignTx* msg);
bool ethereum_isStandardERC20Approve(const EthereumSignTx* msg);
void layoutEthereumConfirmTx(const uint8_t* to, uint32_t to_len, const uint8_t* value, uint32_t value_len, const TokenType* token, char* msg, size_t msg_len, bool approve);
bool confirm(ButtonRequestType type, const char* title, const char* fmt, ...);
bool storage_isPolicyEnabled(const char* policy);
bool review(ButtonRequestType type, const char* title, const char* msg);
void layoutEthereumData(const uint8_t* data, uint32_t data_len, uint32_t total_len, char* msg, size_t msg_len);
void layoutEthereumFee(const EthereumSignTx* msg, bool has_token, char* msg_buf, size_t msg_len);
void layoutProgress(const char* msg, uint32_t progress);
uint32_t rlp_calculate_number_length(uint32_t number);
uint32_t rlp_calculate_length(uint32_t len, uint8_t firstbyte);
void hash_data(const uint8_t* data, size_t len);
void hash_rlp_list_length(uint32_t length);
void hash_rlp_number(uint32_t number);
void hash_rlp_field(const uint8_t* data, uint32_t len);
void hash_rlp_length(uint32_t len, uint8_t firstbyte);
void send_request_chunk(void);
void send_signature(void);
void ethereum_address_checksum(const uint8_t* bytes, char* addr, bool rskip60, uint32_t chain_id);