#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define AD5755_NUM_CHANNELS 4
#define GFP_KERNEL 0
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

struct device_node {
    struct device_node *of_node;
};

struct device {
    struct device_node *of_node;
};

enum ad5755_mode {
    AD5755_MODE_CURRENT_4mA_20mA,
};

enum ad5755_dc_dc_phase {
    AD5755_DC_DC_PHASE_ALL_SAME_EDGE,
};

enum ad5755_dc_dc_freq {
    AD5755_DC_DC_FREQ_410kHZ,
};

enum ad5755_dc_dc_maxv {
    AD5755_DC_DC_MAXV_23V,
};

enum ad5755_slew_rate {
    AD5755_SLEW_RATE_64k,
};

enum ad5755_slew_step_size {
    AD5755_SLEW_STEP_SIZE_1,
};

struct ad5755_slew {
    bool enable;
    enum ad5755_slew_rate rate;
    enum ad5755_slew_step_size step_size;
};

struct ad5755_channel {
    enum ad5755_mode mode;
    bool ext_current_sense_resistor;
    bool enable_voltage_overrange;
    struct ad5755_slew slew;
};

struct ad5755_platform_data {
    bool ext_dc_dc_compenstation_resistor;
    enum ad5755_dc_dc_phase dc_dc_phase;
    enum ad5755_dc_dc_freq dc_dc_freq;
    enum ad5755_dc_dc_maxv dc_dc_maxv;
    struct ad5755_channel dac[AD5755_NUM_CHANNELS];
};

static unsigned int ad5755_dcdc_freq_table[1][2] = {{0}};
static unsigned int ad5755_dcdc_maxv_table[1][2] = {{0}};
static unsigned int ad5755_slew_rate_table[1][2] = {{0}};
static unsigned int ad5755_slew_step_table[1][2] = {{0}};

void *devm_kzalloc(struct device *dev, size_t size, int flags);
void devm_kfree(struct device *dev, void *p);
bool of_property_read_bool(const struct device_node *np, const char *propname);
int of_property_read_u32(const struct device_node *np, const char *propname, unsigned int *out_value);
int of_property_read_u32_array(const struct device_node *np, const char *propname, unsigned int *out_values, size_t sz);
void dev_err(const struct device *dev, const char *fmt, ...);
#define for_each_child_of_node(parent, child) for (child = NULL; child != NULL; )