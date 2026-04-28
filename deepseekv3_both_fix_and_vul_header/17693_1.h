#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef uint8_t UINT8;

#define CHANNEL_RC_OK 0
#define ERROR_INVALID_DATA 1
#define STATUS_UNSUCCESSFUL 2

typedef struct stream Stream;
typedef struct _IRP IRP;
typedef struct _PRINTER_DEVICE PRINTER_DEVICE;
typedef struct _rdpPrintJob rdpPrintJob;

struct _IRP {
    Stream* input;
    Stream* output;
    UINT IoStatus;
    UINT (*Complete)(IRP* irp);
    UINT FileId;
};

struct _PRINTER_DEVICE {
    struct {
        rdpPrintJob* (*FindPrintJob)(void* printer, UINT FileId);
    }* printer;
};

struct _rdpPrintJob {
    UINT (*Write)(rdpPrintJob* printjob, void* ptr, UINT32 Length);
};

#define TAG "printer"

#define WLog_ERR(tag, format, ...) fprintf(stderr, format, ##__VA_ARGS__)