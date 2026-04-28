#include <stdbool.h>
#include <string.h>

#define CONFIDENTIAL
#define MNEMONIC_BUF 256
#define MAX_UNCYPHERED_WORDS 3

extern bool awaiting_character;
extern bool recovery_started;
extern bool enforce_wordlist;
extern char mnemonic[MNEMONIC_BUF];
extern const char cipher[27];
extern const char english_alphabet[27];

extern void recovery_abort(void);
extern void fsm_sendFailure(int, const char*);
extern void layoutHome(void);
extern bool attempt_auto_complete(const char*);
extern void next_character(void);
extern void memzero(void*, size_t);

enum FailureType {
    FailureType_Failure_UnexpectedMessage,
    FailureType_Failure_SyntaxError
};