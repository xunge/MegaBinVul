#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum {
    BUFFER_BLOCK,
    BUFFER_SPAN
};

enum {
    MD_CHAR_EMPHASIS,
    MD_CHAR_CODESPAN,
    MD_CHAR_LINEBREAK,
    MD_CHAR_LINK,
    MD_CHAR_LANGLE,
    MD_CHAR_ESCAPE,
    MD_CHAR_ENTITITY,
    MD_CHAR_AUTOLINK_EMAIL,
    MD_CHAR_AUTOLINK_URL,
    MD_CHAR_AUTOLINK_WWW,
    MD_CHAR_AUTOLINK_SUBREDDIT_OR_USERNAME,
    MD_CHAR_SUPERSCRIPT
};

enum {
    MKDEXT_STRIKETHROUGH,
    MKDEXT_AUTOLINK,
    MKDEXT_NO_EMAIL_AUTOLINK,
    MKDEXT_SUPERSCRIPT
};

struct sd_callbacks {
    void (*emphasis)(void);
    void (*double_emphasis)(void);
    void (*triple_emphasis)(void);
    void (*codespan)(void);
    void (*linebreak)(void);
    void (*image)(void);
    void (*link)(void);
};

struct sd_markdown {
    struct sd_callbacks cb;
    unsigned int ext_flags;
    void *opaque;
    size_t max_nesting;
    size_t max_table_cols;
    int in_link_body;
    unsigned char active_char[256];
    void *work_bufs[2];
};

extern int sip_hash_key_init;
extern unsigned char sip_hash_key[32];
#define SIP_HASH_KEY_LEN 32

void stack_init(void *stack, size_t size);