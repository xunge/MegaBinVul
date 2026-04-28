#include <string.h>

typedef unsigned long MagickSizeType;
typedef unsigned long Atom;
typedef unsigned long Window;
typedef unsigned long Time;
typedef struct _Display Display;

#define MagickPackageName "ImageMagick"
#define AnimateHelp "Animate Help Text"

typedef enum {
    OpenCommand,
    PlayCommand,
    StepCommand,
    StepBackwardCommand,
    StepForwardCommand,
    RepeatCommand,
    AutoReverseCommand,
    SaveCommand,
    SlowerCommand,
    FasterCommand,
    ForwardCommand,
    ReverseCommand,
    InfoCommand,
    HelpCommand,
    BrowseDocumentationCommand,
    VersionCommand,
    QuitCommand
} CommandType;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef unsigned int MagickStatusType;

typedef struct _ExceptionInfo {
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _Image {
    char *magick_filename;
    struct _Image *next;
} Image;

typedef struct _ImageInfo {
    char filename[4096];
    char *magick;
} ImageInfo;

typedef struct _XResourceInfo {
    MagickBooleanType immutable;
    ImageInfo *image_info;
    char *title;
    int delay;
    MagickBooleanType confirm_exit;
    char *client_name;
} XResourceInfo;

typedef struct _XWindows {
    struct {
        Window id;
        char name[4096];
    } image;
    Atom im_protocols;
    Atom im_exit;
} XWindows;

typedef struct _XTextProperty {
    unsigned char *value;
} XTextProperty;

#define MagickPathExtent 4096
#define LoadImageTag 0
#define BasePath 0
#define ExitState 0
#define PlayAnimationState 0
#define AutoReverseAnimationState 0
#define StepAnimationState 0
#define ForwardAnimationState 0
#define RepeatAnimationState 0
#define ResourceLimitError 0
#define ImageError 0
#define CurrentTime 0
#define XA_STRING 0
#define PropModeReplace 0
#define XDefaultScreen(d) 0

extern Image *NewImageList(void);
extern void ThrowXWindowException(int, const char *, const char *);
extern void XFileBrowserWidget(Display *, XWindows *, const char *, char *);
extern void *AcquireMagickMemory(size_t);
extern MagickBooleanType ExpandFilenames(int *, char ***);
extern ImageInfo *CloneImageInfo(ImageInfo *);
extern void XSetCursorState(Display *, XWindows *, MagickBooleanType);
extern void XCheckRefreshWindows(Display *, XWindows *);
extern Image *ReadImage(ImageInfo *, ExceptionInfo *);
extern void CatchException(ExceptionInfo *);
extern void AppendImageToList(Image **, Image *);
extern MagickBooleanType SetImageProgress(Image *, int, int, MagickSizeType);
extern void *RelinquishMagickMemory(void *);
extern ImageInfo *DestroyImageInfo(ImageInfo *);
extern Image *GetFirstImageInList(Image *);
extern void GetPathComponent(const char *, int, char *);
extern char *InterpretImageProperties(ImageInfo *, Image *, const char *, ExceptionInfo *);
extern int XStringListToTextProperty(char **, int, XTextProperty *);
extern void XSetWMName(Display *, Window, XTextProperty *);
extern void XFree(void *);
extern MagickBooleanType XSaveImage(Display *, XResourceInfo *, XWindows *, Image *, ExceptionInfo *);
extern void XNoticeWidget(Display *, XWindows *, const char *, const char *);
extern void XDisplayImageInfo(Display *, XResourceInfo *, XWindows *, Image *, Image *, ExceptionInfo *);
extern void XTextViewWidget(Display *, XResourceInfo *, XWindows *, MagickBooleanType, const char *, const char *);
extern Window XRootWindow(Display *, int);
extern Atom XInternAtom(Display *, const char *, MagickBooleanType);
extern Window XWindowByProperty(Display *, Window, Atom);
extern char *GetMagickHomeURL(void);
extern void XChangeProperty(Display *, Window, Atom, Atom, int, int, unsigned char *, int);
extern MagickBooleanType InvokeDelegate(ImageInfo *, Image *, const char *, char *, ExceptionInfo *);
extern void XDelay(Display *, int);
extern int XConfirmWidget(Display *, XWindows *, const char *, const char *);
extern void XClientMessage(Display *, Window, Atom, Atom, Time);
extern const char *GetMagickVersion(size_t *);
extern const char *GetMagickCopyright(void);
extern char *DestroyString(char *);
extern int FormatLocaleString(char *, size_t, const char *, ...);
extern void CopyMagickString(char *, const char *, size_t);