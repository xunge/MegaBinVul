#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define X_CMDLINE 1
#define GAMMA_MIN 0.1
#define GAMMA_MAX 10.0
#define LDR_OPT_ABI_MISMATCH_NONFATAL 1

extern char *xf86ModulePath;
extern char *xf86LogFile;
extern char *xf86ConfigFile;
extern char *xf86ConfigDir;
extern int xf86FlipPixels;
extern int xf86VidModeDisabled;
extern int xf86VidModeAllowNonLocal;
extern int xf86AllowMouseOpenFail;
extern int xf86Verbose;
extern int xf86LogVerbose;
extern int xf86fpFlag;
extern int xf86bsDisableFlag;
extern int xf86bsEnableFlag;
extern int xf86sFlag;
extern int xf86FbBpp;
extern int xf86Depth;
extern int xf86silkenMouseDisableFlag;
extern int xf86acpiDisableFlag;
extern int xf86DoConfigure;
extern int xf86DoShowOptions;
extern int xf86xkbdirFlag;
extern char *xf86LayoutName;
extern char *xf86ScreenName;
extern char *xf86PointerName;
extern char *xf86KeyboardName;

struct {
    int red;
    int green;
    int blue;
} xf86Weight;

struct {
    double red;
    double green;
    double blue;
} xf86Gamma;

struct {
    int autoVTSwitch;
    int ShareVTs;
    int iglxFrom;
} xf86Info;

extern int xf86ModPathFrom;
extern int xf86LogFileFrom;

void ErrorF(const char *format, ...);
void UseMsg(void);
void FatalError(const char *format, ...);
void xf86CheckPrivs(const char *opt, const char *arg);
void xf86SetVerbosity(int verb);
void xf86SetLogVerbosity(int verb);
void xf86PrintBanner(void);
void xf86PrintDefaultModulePath(void);
void xf86PrintDefaultLibraryPath(void);
void LoaderSetOptions(int options);
void xf86PciIsolateDevice(const char *device);
int xf86ProcessArgument(int argc, char **argv, int i);