#include <linux/capability.h>
#include <linux/errno.h>

#define TPACPI_VIDEO_NONE 0
#define TPACPI_VIDEO_NEW 1
#define TP_ACPI_VIDEO_S_LCD 0x01
#define TP_ACPI_VIDEO_S_CRT 0x02
#define TP_ACPI_VIDEO_S_DVI 0x04

static int video_supported;
static int video_autosw_set(int val);
static int video_outputsw_cycle(void);
static int video_expand_toggle(void);
static int video_outputsw_get(void);
static int video_outputsw_set(int val);
static char *next_cmd(char **buf);
static int strlencmp(const char *cmd, const char *str);