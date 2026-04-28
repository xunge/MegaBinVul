struct dmi_system_id {
    const char *ident;
    int (*callback)(const struct dmi_system_id *);
};

struct cpu_feature {
    const char *feature;
    int (*check)(void);
};

int dmi_check_system(const struct dmi_system_id *table);
int pm_cpu_check(const struct cpu_feature *table);

static const struct dmi_system_id msr_save_dmi_table[] = {0};
static const struct cpu_feature msr_save_cpu_table[] = {0};