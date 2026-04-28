#include <stdbool.h>
#include <stdint.h>
#include <cstddef>

typedef uintptr_t UDATA;
typedef intptr_t IDATA;

#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))

#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_NO_CLASS_INIT 0x08
#define J9_RESOLVE_FLAG_FIELD_SETTER 0x10
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x20

#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_LOOK_NO_NESTMATES 0x04

#define J9_VISIBILITY_NON_MODULE_ACCESS_ERROR -1
#define J9_VISIBILITY_ALLOWED 0

#define J9AccFinal 0x0010
#define J9AccPrivate 0x0002
#define J9AccVolatile 0x0040

#define J9FieldFlagObject 0x0100
#define J9FieldSizeDouble 0x0200
#define J9FieldTypeMask 0x0F00
#define J9FieldTypeBoolean 0x0100

#define J9StaticFieldRefBaseType 0x01
#define J9StaticFieldRefDouble 0x02
#define J9StaticFieldRefBoolean 0x04
#define J9StaticFieldRefVolatile 0x08
#define J9StaticFieldRefFinal 0x10
#define J9StaticFieldRefPutResolved 0x20

#define J9ClassInitSucceeded 0
#define J9_RUNTIME_VERIFY 0x01

#define J9VMCONSTANTPOOL_JAVALANGILLEGALACCESSERROR 1
#define J9VMCONSTANTPOOL_JAVALANGVERIFYERROR 2

#define J9FLAGSANDCLASS_FROM_CLASSANDFLAGS(x) (x)
#define J9_CLASS_FROM_CP(cp) ((J9Class*)(cp)->ramClass)
#define J9ROMFIELDREF_NAMEANDSIGNATURE(ref) ((J9ROMNameAndSignature*)((ref) + 1))
#define J9ROMNAMEANDSIGNATURE_NAME(nas) ((J9UTF8*)((nas)->nameAndSignature))
#define J9ROMNAMEANDSIGNATURE_SIGNATURE(nas) ((J9UTF8*)((nas)->nameAndSignature + (nas)->nameAndSignature->length + 1))
#define J9ROMFIELDSHAPE_SIGNATURE(field) ((J9UTF8*)((field)->nameAndSignature + (field)->nameAndSignature->length + 1))
#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9UTF8_LENGTH(utf8) ((utf8)->length)

#define PORT_ACCESS_FROM_VMC(vmStruct)
#define IDATA_MIN ((IDATA)1 << (sizeof(IDATA)*8 - 1))

typedef struct J9VMThread J9VMThread;
typedef struct J9Method J9Method;
typedef struct J9ConstantPool J9ConstantPool;
typedef struct J9ROMFieldShape J9ROMFieldShape;
typedef struct J9RAMStaticFieldRef J9RAMStaticFieldRef;
typedef struct J9ROMFieldRef J9ROMFieldRef;
typedef struct J9Class J9Class;
typedef struct J9JavaVM J9JavaVM;
typedef struct J9ROMNameAndSignature J9ROMNameAndSignature;
typedef struct J9UTF8 J9UTF8;
typedef struct J9ClassLoader J9ClassLoader;
typedef struct J9ROMClass J9ROMClass;

struct J9VMThread {
    J9JavaVM *javaVM;
};

struct J9ConstantPool {
    J9Class *ramClass;
    J9ROMFieldRef *romConstantPool;
};

struct J9RAMStaticFieldRef {
    UDATA flagsAndClass;
    UDATA valueOffset;
};

struct J9ROMFieldRef {
    UDATA classRefCPIndex;
};

struct J9ROMNameAndSignature {
    J9UTF8 *nameAndSignature;
};

struct J9UTF8 {
    UDATA length;
    char *data;
};

struct J9Class {
    J9ROMClass *romClass;
    J9ClassLoader *classLoader;
    UDATA initializeStatus;
    void *ramStatics;
};

struct J9JavaVM {
    UDATA hotSwapCount;
    UDATA runtimeFlags;
    J9ClassLoader *systemClassLoader;
};

struct J9ROMClass {
    UDATA modifiers;
};

struct J9ROMFieldShape {
    UDATA modifiers;
    J9UTF8 *nameAndSignature;
};

extern void Trc_VM_resolveStaticFieldRef_Entry(J9VMThread*, J9Method*, J9ConstantPool*, UDATA, UDATA, J9ROMFieldShape**);
extern void Trc_VM_resolveStaticFieldRef_Exit(J9VMThread*, void*);
extern J9Class* resolveClassRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
extern void *staticFieldAddress(J9VMThread*, J9Class*, char*, UDATA, char*, UDATA, J9Class**, UDATA*, UDATA, J9Class*);
extern IDATA checkVisibility(J9VMThread*, J9Class*, J9Class*, UDATA, UDATA);
extern void initializeClass(J9VMThread*, J9Class*);
extern bool threadEventsPending(J9VMThread*);
extern char *illegalAccessMessage(J9VMThread*, IDATA, J9Class*, J9Class*, IDATA);
extern void setCurrentExceptionUTF(J9VMThread*, UDATA, char*);
extern void setCurrentException(J9VMThread*, UDATA, char*);
extern bool finalFieldSetAllowed(J9VMThread*, bool, J9Method*, J9Class*, J9Class*, J9ROMFieldShape*, bool);
extern int j9bcv_checkClassLoadingConstraintsForSignature(J9VMThread*, J9ClassLoader*, J9ClassLoader*, J9UTF8*, J9UTF8*);
extern void j9mem_free_memory(void*);

namespace VM_VMHelpers {
    extern void reportFinalFieldModified(J9VMThread*, J9Class*);
}