#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XPATH_MAXLEN 256

struct isis_circuit {
    struct isis_area *area;
};

struct isis_area;
struct list;
struct listnode;
struct yang_data;
struct nb_notification;

struct yang_data {
    const char *xpath;
    const void *value;
};

struct list {
    struct listnode *head;
};

struct listnode {
    void *data;
    struct listnode *next;
};

extern struct list *yang_data_list_new(void);
extern struct yang_data *yang_data_new_string(const char *xpath, const char *value);
extern struct yang_data *yang_data_new(const char *xpath, const void *value);
extern void listnode_add(struct list *list, void *data);
extern void notif_prep_instance_hdr(const char *xpath, struct isis_area *area, const char *instance, struct list *arguments);
extern void notif_prepr_iface_hdr(const char *xpath, const struct isis_circuit *circuit, struct list *arguments);
extern void hook_call(int hook, const struct isis_circuit *circuit, const char *raw_pdu, size_t raw_pdu_len);
extern void nb_notification_send(const char *xpath, struct list *arguments);

#define isis_hook_reject_adjacency 0