#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef unsigned int gfp_t;

#define WCD9335_CDC_TX0_TX_PATH_CTL 0
#define WCD9335_CDC_TX0_TX_PATH_SEC2 0
#define WCD9335_CDC_TX0_TX_PATH_CFG0 0
#define WCD9335_CDC_TX0_TX_VOL_CTL 0
#define WCD9335_MBHC_ZDET_RAMP_CTL 0

#define WCD9335_AMIC_PWR_LVL_MASK 0x03
#define WCD9335_AMIC_PWR_LVL_SHIFT 0
#define WCD9335_AMIC_PWR_LEVEL_LP 0
#define WCD9335_AMIC_PWR_LEVEL_HP 1
#define WCD9335_AMIC_PWR_LEVEL_DEFAULT 2

#define WCD9335_DEC_PWR_LVL_MASK 0x03
#define WCD9335_DEC_PWR_LVL_LP 0
#define WCD9335_DEC_PWR_LVL_HP 1
#define WCD9335_DEC_PWR_LVL_DF 2

#define TX_HPF_CUT_OFF_FREQ_MASK 0xE0
#define CF_MIN_3DB_150HZ 0

#define GFP_KERNEL 0
#define ENOMEM (-12)
#define EINVAL (-22)

#define SND_SOC_DAPM_PRE_PMU 0
#define SND_SOC_DAPM_POST_PMU 1
#define SND_SOC_DAPM_PRE_PMD 2
#define SND_SOC_DAPM_POST_PMD 3

struct snd_soc_dapm_widget {
    char *name;
    void *dapm;
};

struct snd_kcontrol {
    // dummy structure
};

struct snd_soc_component {
    void *dev;
};

static inline char* kstrndup(const char *s, size_t max, gfp_t gfp) {
    (void)gfp; // unused parameter
    return strndup(s, max);
}

static inline int kstrtouint(const char *s, unsigned int base, unsigned int *res) {
    char *endptr;
    unsigned long val = strtoul(s, &endptr, base);
    if (*endptr != '\0' || val > UINT_MAX)
        return -EINVAL;
    *res = (unsigned int)val;
    return 0;
}

static inline void kfree(void *p) {
    free(p);
}

struct snd_soc_component *snd_soc_dapm_to_component(void *dapm);
int snd_soc_component_read32(struct snd_soc_component *comp, int reg);
void snd_soc_component_write(struct snd_soc_component *comp, int reg, int val);
void snd_soc_component_update_bits(struct snd_soc_component *comp, int reg, int mask, int val);
int wcd9335_codec_find_amic_input(struct snd_soc_component *comp, unsigned int decimator);
int wcd9335_codec_get_amic_pwlvl_reg(struct snd_soc_component *comp, int amic_n);
void dev_err(void *dev, const char *fmt, ...);