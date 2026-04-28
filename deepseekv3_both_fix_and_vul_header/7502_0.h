#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OGS_NAS_5GS_SUPI_FORMAT_IMSI 0
#define OGS_NAS_5GS_NULL_SCHEME 0
#define OGS_NAS_MAX_SCHEME_OUTPUT_LEN 16
#define OGS_MAX_IMSI_BCD_LEN 16

typedef struct {
    uint8_t supi_format;
} ogs_nas_5gs_mobile_identity_suci_header_t;

typedef struct {
    ogs_nas_5gs_mobile_identity_suci_header_t h;
    uint8_t nas_plmn_id[3];
    uint8_t routing_indicator1:4;
    uint8_t routing_indicator2:4;
    uint8_t routing_indicator3:4;
    uint8_t routing_indicator4:4;
    uint8_t protection_scheme_id;
    uint8_t home_network_pki_value;
    uint8_t scheme_output[];
} ogs_nas_5gs_mobile_identity_suci_t;

typedef struct {
    uint8_t length;
    uint8_t buffer[];
} ogs_nas_5gs_mobile_identity_t;

typedef struct {
    uint8_t mcc1;
    uint8_t mcc2;
    uint8_t mcc3;
    uint8_t mnc1;
    uint8_t mnc2;
    uint8_t mnc3;
} ogs_plmn_id_t;