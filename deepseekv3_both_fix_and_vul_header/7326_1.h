#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define XPATH_MAXLEN 256

struct isis_circuit {
    struct isis_area *area;
};

struct isis_area;
struct list;
struct listnode;
struct yang_data;

struct yang_data *yang_data_new(const char *xpath, const char *value);
struct yang_data *yang_data_new_uint8(const char *xpath, uint8_t value);
struct list *yang_data_list_new(void);
void notif_prep_instance_hdr(const char *xpath, struct isis_area *area, const char *instance, struct list *arguments);
void notif_prepr_iface_hdr(const char *xpath, const struct isis_circuit *circuit, struct list *arguments);
void hook_call(int hook, const struct isis_circuit *circuit, uint8_t version, const char *raw_pdu, size_t raw_pdu_len);
void nb_notification_send(const char *xpath, struct list *arguments);
void listnode_add(struct list *list, void *data);

#define isis_hook_version_skew 0