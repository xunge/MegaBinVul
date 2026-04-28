#include <stdlib.h>

struct rudp {
    struct {
        struct message *head;
    } send_queue;
    struct {
        struct message *head;
    } recv_queue;
    struct {
        struct message *head;
    } send_history;
    struct message *free_list;
    struct {
        void *a;
    } send_again;
};

struct message;

void free_message_list(struct message *head);
void clear_outpackage(struct rudp *U);