#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct _XMLTreeInfo {
    char *tag;
    struct _XMLTreeInfo *node;
} XMLTreeInfo;

typedef struct _XMLTreeRoot {
    XMLTreeInfo *node;
    char ***attributes;
    char **entities;
    XMLTreeInfo root;
} XMLTreeRoot;

typedef struct _ExceptionInfo {
    int dummy;
} ExceptionInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define MagickExport
#define XMLWhitespace " \t\n\r"
#define sentinel ((char **) ~0UL)
#define OptionWarning 0
#define ResourceLimitError 0
#define GetMagickModule() NULL
#define ThrowMagickException(exception,module,severity,tag,reason,...) 0
#define NewXMLTreeTag(tag) NULL
#define ConvertUTF16ToUTF8(xml,length) NULL
#define DestroyString(string) (free(string), NULL)
#define ConstantString(string) ((char *)string)
#define AcquireQuantumMemory(count,size) malloc((count)*(size))
#define ResizeQuantumMemory(memory,count,size) realloc(memory,(count)*(size))
#define DestroyXMLTreeAttributes(attributes) (free(attributes), NULL)
#define ParseEntities(content,entities,space) NULL
#define ParseOpenTag(root,tag,attributes) 
#define ParseCloseTag(root,tag,exception) NULL
#define IsSkipTag(tag) MagickFalse
#define ParseCharacterContent(root,content,length,space) 
#define ParseInternalDoctype(root,tag,length,exception) MagickFalse
#define ParseProcessingInstructions(root,target,content) 