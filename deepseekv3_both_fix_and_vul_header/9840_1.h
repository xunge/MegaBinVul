#include <stdio.h>
#include <unistd.h>

#define TPACPI_VIDEO_NONE 0
#define TPACPI_VIDEO_NEW 1
#define CAP_SYS_ADMIN 0
#define EPERM 1

struct seq_file {
    FILE *file;
};

static int video_supported;
static int video_outputsw_get(void);
static int video_autosw_get(void);
static const char *enabled(int status, int index);
static int seq_printf(struct seq_file *m, const char *fmt, ...);
static int capable(int cap);