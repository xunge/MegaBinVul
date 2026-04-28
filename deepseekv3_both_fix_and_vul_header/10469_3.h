#include <stdlib.h>
#include <sys/types.h>

#define MAILIMF_NO_ERROR 0
#define MAILIMF_ERROR_PARSE -1
#define MAILIMF_ERROR_MEMORY -2

struct mailimf_group;
struct mailimf_mailbox_list;
struct clist;

struct mailimf_group {
    char * display_name;
    struct mailimf_mailbox_list * mailbox_list;
};

struct mailimf_mailbox_list {
    struct clist * list;
};

struct mailimf_group * mailimf_group_new(char * display_name, struct mailimf_mailbox_list * mailbox_list);
void mailimf_group_free(struct mailimf_group * group);
void mailimf_mailbox_list_free(struct mailimf_mailbox_list * mailbox_list);
int mailimf_display_name_parse(const char * message, size_t length, size_t * indx, char ** result);
void mailimf_display_name_free(char * display_name);
int mailimf_colon_parse(const char * message, size_t length, size_t * indx);
int mailimf_mailbox_list_parse(const char * message, size_t length, size_t * indx, struct mailimf_mailbox_list ** result);
int mailimf_cfws_parse(const char * message, size_t length, size_t * indx);
int mailimf_semi_colon_parse(const char * message, size_t length, size_t * indx);
struct mailimf_mailbox_list * mailimf_mailbox_list_new(struct clist * list);

struct clist * clist_new(void);
void clist_free(struct clist * list);

typedef struct clist clist;