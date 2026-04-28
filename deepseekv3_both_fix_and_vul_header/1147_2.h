#include <stdbool.h>
#include <stddef.h>

struct sasl_output_buf {
    char *buf;
    size_t len;
    unsigned int flags;
};

struct sasl_session {
    char uid[64];
    char authceid[64];
    char authzeid[64];
    char pendingeid[64];
    struct sasl_mechanism *mechptr;
    unsigned int flags;
    void *si;
    char nick[64];
};

struct sasl_mechanism {
    const char *name;
    enum sasl_mechanism_result (*mech_start)(struct sasl_session *, struct sasl_output_buf *);
};

struct user {
    char nick[64];
};

struct myuser {
    char name[64];
};

struct entity {
    char name[64];
};

enum sasl_mechanism_result {
    ASASL_MRESULT_CONTINUE,
    ASASL_MRESULT_SUCCESS,
    ASASL_MRESULT_FAILURE,
    ASASL_MRESULT_ERROR
};

#define ASASL_OUTFLAG_NONE 0
#define ASASL_SFLAG_MARKED_FOR_DELETION (1 << 0)
#define LG_DEBUG 0
#define CMDLOG_LOGIN 0
#define MOWGLI_FUNC_NAME __func__

#define ATHEME_FATTR_WUR __attribute__((warn_unused_result))

extern const char *sasl_mechlist_string;
extern const char *LOGIN_CANCELLED_STR;
extern struct sasl_session *saslsvs;

extern struct sasl_mechanism *sasl_mechanism_find(const char *);
extern void sasl_sts(const char *, char, const char *);
extern void sasl_sourceinfo_recreate(struct sasl_session *);
extern enum sasl_mechanism_result sasl_process_input(struct sasl_session *, char *, size_t, struct sasl_output_buf *);
extern bool sasl_process_output(struct sasl_session *, struct sasl_output_buf *);
extern struct user *user_find(const char *);
extern struct myuser *sasl_user_can_login(struct sasl_session *);
extern bool sasl_handle_login(struct sasl_session *, struct user *, struct myuser *);
extern bool sasl_session_success(struct sasl_session *, struct myuser *, bool);
extern struct myuser *myuser_find_uid(const char *);
extern void logcommand(void *, int, const char *, ...);
extern void bad_password(void *, struct myuser *);
extern void notice(const char *, const char *, const char *);
extern size_t mowgli_strlcpy(char *, const char *, size_t);
extern void slog(int, const char *, ...);
extern struct entity *entity(struct myuser *);