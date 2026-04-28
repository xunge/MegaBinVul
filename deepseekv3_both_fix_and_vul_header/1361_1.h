#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define LSI_TAG_VALID 0x01000000
#define PHASE_CMD 0
#define PHASE_MI 1
#define LOG_UNIMP 0
#define LSI_MSG_ACTION_COMMAND 0

typedef struct lsi_request {
    int tag;
    void *req;
    struct {
        struct lsi_request *tqe_next;
    } next;
} lsi_request;

typedef struct LSIState {
    int dbc;
    int sfbr;
    int current_lun;
    int select_tag;
    int msg_action;
    lsi_request *current;
    struct {
        lsi_request *tqh_first;
    } queue;
} LSIState;

#define QTAILQ_FOREACH_SAFE(p, head, field, p_next) \
    for ((p) = QTAILQ_FIRST(head); \
         (p) != NULL && ((p_next) = QTAILQ_NEXT(p, field), 1); \
         (p) = (p_next))

#define QTAILQ_FIRST(head) (head)->tqh_first
#define QTAILQ_NEXT(elm, field) (elm)->field.tqe_next