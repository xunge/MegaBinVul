#include <stdbool.h>
#include <string.h>

#define ENGLISH_ALPHABET_BUF 27
#define CURRENT_WORD_BUF 128
#define CONFIDENTIAL

extern bool recovery_started;
extern char cipher[ENGLISH_ALPHABET_BUF];
extern char english_alphabet[ENGLISH_ALPHABET_BUF];
extern char auto_completed_word[CURRENT_WORD_BUF];

typedef enum {
    FailureType_Failure_UnexpectedMessage,
    FailureType_Failure_SyntaxError
} FailureType;

typedef enum {
    MessageType_MessageType_CharacterRequest
} MessageType;

typedef struct {
    int word_pos;
    int character_pos;
} CharacterRequest;

void recovery_abort(void);
void fsm_sendFailure(FailureType type, const char* message);
void layoutHome(void);
void random_permute_char(char* str, size_t len);
void get_current_word(char* word);
int get_current_word_pos(void);
void msg_write(MessageType type, const void* msg);
bool attempt_auto_complete(const char* word);
void format_current_word(const char* word, bool auto_completed);
void layout_cipher(const char* word, const char* cipher);