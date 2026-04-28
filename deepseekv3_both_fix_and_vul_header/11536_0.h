#include <stdlib.h>
#include <string.h>

#define STACKDEPTH 100
#define FLAG_IGNORE 1
#define OUTPUT_DELIM 2
#define OUTPUT_TEXT 4
#define PARSE_MACROS 8

struct COMMENT {
    char *start;
    char *end;
    char quote;
    int warn;
    int flags[2];
    struct COMMENT *next;
};

struct STATE {
    struct {
        char *mArgRef;
    } User;
    struct COMMENT *comments;
};

struct CONTEXT {
    char *buf;
    int in_comment;
    int ambience;
    int may_have_args;
    int argc;
    char **argv;
};

extern int parselevel;
extern struct STATE *S;
extern struct CONTEXT *C;

void bug(const char *msg);
int matchStartSequence(char *seq, int *pos);
int findCommentEnd(char *end, char quote, int warn, int start, int flags);
int matchEndSequence(char *seq, int *pos);
void sendout(char *str, int len, int flag);
void replace_definition_with_blank_lines(char *start, char *end, int flag);
char *ProcessText(char *text, int len, int ambience);
void shiftIn(int pos);
int ParsePossibleMeta(void);
int ParsePossibleUser(void);
int matchSequence(char *seq, int *pos);
char getChar(int pos);
int identifierEnd(int pos);