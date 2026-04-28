#include <string.h>

#define XCOPY_NAA_IEEE_REGEX_LEN 32

struct se_device {
    struct {
        struct {
            int emulate_3pc;
        } dev_attrib;
        struct {
            void *cg_item;
        } dev_group;
    };
};

struct xcopy_dev_search_info {
    unsigned char dev_wwn[XCOPY_NAA_IEEE_REGEX_LEN];
    struct se_device *found_dev;
};

extern int target_xcopy_gen_naa_ieee(struct se_device *se_dev, unsigned char *tmp_dev_wwn);
extern int target_depend_item(void *item);
extern void pr_debug(const char *fmt, ...);
extern void pr_err(const char *fmt, ...);