#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define WandExport

typedef struct _DrawingWand DrawingWand;
typedef enum { MagickFalse, MagickTrue } MagickBooleanType;
typedef enum { WandEvent } LogEventType;
typedef struct _MagickModule MagickModule;
typedef struct _DrawContext DrawContext;

extern const MagickModule *GetMagickModule(void);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void LogMagickEvent(LogEventType, const MagickModule *, const char *, ...);

#define WandSignature 0xABACADABUL

struct _DrawingWand {
  unsigned long signature;
  MagickBooleanType debug;
  const char *name;
};

extern DrawContext *CurrentContext;
struct _DrawContext {
  const double *dash_pattern;
};