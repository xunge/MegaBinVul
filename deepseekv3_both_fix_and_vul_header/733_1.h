#include <stdint.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define LOG_UNIMP 0
#define LOG_GUEST_ERROR 1

typedef struct BusState {
    // dummy bus structure
} BusState;

typedef struct DeviceState {
    // dummy device structure
} DeviceState;

typedef struct LSIState {
    uint8_t scntl0;
    uint8_t scntl1;
    uint8_t scntl2;
    uint8_t scntl3;
    uint8_t scid;
    uint8_t sxfer;
    uint8_t sdid;
    uint8_t sfbr;
    uint32_t dsa;
    uint8_t istat0;
    uint8_t mbox0;
    uint8_t mbox1;
    uint8_t ctest2;
    uint8_t ctest3;
    uint32_t temp;
    uint8_t ctest4;
    uint8_t ctest5;
    uint32_t dbc;
    uint32_t dnad;
    uint32_t dsp;
    uint32_t dsps;
    uint32_t scratch[8];
    uint8_t dmode;
    uint8_t dien;
    uint8_t sbr;
    uint8_t dcntl;
    uint8_t sien0;
    uint8_t sien1;
    uint8_t stime0;
    uint8_t stime1;
    uint8_t respid0;
    uint8_t respid1;
    uint8_t stest1;
    uint8_t stest2;
    uint8_t stest3;
    uint8_t ccntl0;
    uint8_t ccntl1;
    uint32_t mmrs;
    uint32_t mmws;
    uint32_t sfs;
    uint32_t drs;
    uint32_t sbms;
    uint32_t dbms;
    uint32_t dnad64;
    uint32_t pmjad1;
    uint32_t pmjad2;
    uint32_t rbc;
    uint32_t ua;
    uint32_t ia;
    uint32_t sbc;
    uint32_t csbc;
    uint8_t ssid;
    uint8_t sstat0;
    uint8_t istat1;
    int waiting;
    BusState bus;
} LSIState;

#define LSI_SCNTL0_START 0x01
#define LSI_SCNTL1_SST 0x01
#define LSI_SCNTL1_IARB 0x02
#define LSI_SCNTL1_RST 0x04
#define LSI_SCNTL2_WSR 0x01
#define LSI_SCNTL2_WSS 0x02
#define LSI_SSTAT0_RST 0x01
#define LSI_SIST0_RST 0x01
#define LSI_ISTAT0_ABRT 0x80
#define LSI_ISTAT0_INTF 0x40
#define LSI_ISTAT0_SIGP 0x20
#define LSI_ISTAT0_SRST 0x10
#define LSI_DSTAT_ABRT 0x40
#define LSI_CTEST2_PCICIE 0x80
#define LSI_CTEST5_ADCK 0x80
#define LSI_CTEST5_BBCK 0x40
#define LSI_DMODE_MAN 0x01
#define LSI_ISTAT1_SRUN 0x01
#define LSI_DCNTL_PFF 0x80
#define LSI_DCNTL_STD 0x40
#define LSI_SIST1_GEN 0x01

enum {
    LSI_NOWAIT,
    LSI_WAIT_RESELECT
};

static const char *names[] = {
    [0x00] = "SCNTL0",
    [0x01] = "SCNTL1",
    [0x02] = "SCNTL2",
    [0x03] = "SCNTL3",
    [0x04] = "SCID",
    [0x05] = "SXFER",
    [0x06] = "SDID",
    [0x07] = "GPREG0",
    [0x08] = "SFBR",
    [0x10] = "DSA",
    [0x14] = "ISTAT0",
    [0x16] = "MBOX0",
    [0x17] = "MBOX1",
    [0x1a] = "CTEST2",
    [0x1b] = "CTEST3",
    [0x1c] = "TEMP",
    [0x21] = "CTEST4",
    [0x22] = "CTEST5",
    [0x24] = "DBC",
    [0x28] = "DNAD",
    [0x2c] = "DSP",
    [0x30] = "DSPS",
    [0x34] = "SCRATCH0",
    [0x38] = "DMODE",
    [0x39] = "DIEN",
    [0x3a] = "SBR",
    [0x3b] = "DCNTL",
    [0x40] = "SIEN0",
    [0x41] = "SIEN1",
    [0x47] = "GPCNTL0",
    [0x48] = "STIME0",
    [0x49] = "STIME1",
    [0x4a] = "RESPID0",
    [0x4b] = "RESPID1",
    [0x4d] = "STEST1",
    [0x4e] = "STEST2",
    [0x4f] = "STEST3",
    [0x56] = "CCNTL0",
    [0x57] = "CCNTL1",
    [0xa0] = "MMRS",
    [0xa4] = "MMWS",
    [0xa8] = "SFS",
    [0xac] = "DRS",
    [0xb0] = "SBMS",
    [0xb4] = "DBMS",
    [0xb8] = "DNAD64",
    [0xc0] = "PMJAD1",
    [0xc4] = "PMJAD2",
    [0xc8] = "RBC",
    [0xcc] = "UA",
    [0xd4] = "IA",
    [0xd8] = "SBC",
    [0xdc] = "CSBC"
};

static inline uint32_t deposit32(uint32_t value, int start, int length, uint32_t fieldval)
{
    uint32_t mask;
    mask = (~0U >> (32 - length)) << start;
    return (value & ~mask) | ((fieldval << start) & mask);
}