#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

typedef unsigned int TEE_Result;
typedef unsigned int TEE_ErrorOrigin;
typedef struct TEE_UUID TEE_UUID;

struct tee_ta_session {
    TAILQ_ENTRY(tee_ta_session) link;
};

TAILQ_HEAD(tee_ta_session_head, tee_ta_session);

#define TEE_MALLOC_FILL_ZERO 0
#define TEE_ERROR_OUT_OF_MEMORY 1
#define TEE_SUCCESS 0
#define TEE_ERROR_ITEM_NOT_FOUND 2
#define TEE_ORIGIN_TEE 0

TEE_Result tee_ta_init_pseudo_ta_session(const TEE_UUID *uuid, struct tee_ta_session *s);
TEE_Result tee_ta_init_user_ta_session(const TEE_UUID *uuid, struct tee_ta_session *s);

#define TEE_Malloc(size, flags) malloc(size)