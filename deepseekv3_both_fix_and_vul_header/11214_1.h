#include <stdbool.h>
#include <stdio.h>

#define LONG_STRING 1024
#define HUGE_STRING 8192
#define ANUM "%lu"

typedef unsigned long anum_t;

struct NntpServer;
struct NntpData;

struct NntpData {
    bool deleted;
    anum_t first_message;
    anum_t last_message;
    bool allowed;
    char *desc;
    void *newsrc_ent;
    anum_t last_cached;
    unsigned int unread;
};

extern struct NntpData *nntp_data_find(struct NntpServer *nserv, char *group);
extern void nntp_group_unread_stat(struct NntpData *nntp_data);
extern void mutt_str_replace(char **str, const char *value);