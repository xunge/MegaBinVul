#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct cdtext_t cdtext_t;
typedef struct generic_img_private_t {
    bool b_cdtext_error;
    cdtext_t *cdtext;
} generic_img_private_t;

#define CDIO_MMC_GET_LEN16(p) ((uint16_t)(((p)[0] << 8) | (p)[1]))

uint8_t *read_cdtext_generic(generic_img_private_t *p_env);
cdtext_t *cdtext_init(void);
int cdtext_data_init(cdtext_t *cdtext, uint8_t *data, size_t len);
void cdtext_destroy(cdtext_t *cdtext);