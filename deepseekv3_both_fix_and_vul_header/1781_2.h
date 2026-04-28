#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char Bool;
#define TRUE 1
#define FALSE 0
typedef unsigned long Mask;
typedef struct _ClientRec *ClientPtr;
typedef struct _DeviceIntRec *DeviceIntPtr;
typedef struct _XkbDescRec *XkbDescPtr;
typedef struct _XkbSrvLedInfoRec *XkbSrvLedInfoPtr;

typedef struct _XkbComponentNamesRec {
    char *keycodes;
    char *types;
    char *compat;
    char *symbols;
    char *geometry;
} XkbComponentNamesRec;

typedef struct _XkbEventCauseRec {
    int kc;
    int major;
    int minor;
    ClientPtr client;
} XkbEventCauseRec;

typedef struct _XkbChangesRec {
    unsigned int changed;
    unsigned int state_changes;
    unsigned int map_changes;
    unsigned int ctrls_changes;
    unsigned int indicator_changes;
    unsigned int name_changes;
    unsigned int compat_changes;
    unsigned int geom_changes;
} XkbChangesRec;

typedef struct _xkbNewKeyboardNotify {
    int deviceID;
    int oldDeviceID;
    int minKeyCode;
    int maxKeyCode;
    int oldMinKeyCode;
    int oldMaxKeyCode;
    int requestMajor;
    int requestMinor;
    unsigned int changed;
} xkbNewKeyboardNotify;

typedef struct _xkbGetKbdByNameReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned short found;
    unsigned short reported;
    unsigned char loaded;
    unsigned char newKeyboard;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char minKeyCode;
    unsigned char maxKeyCode;
} xkbGetKbdByNameReply;

typedef struct _xkbGetMapReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned char minKeyCode;
    unsigned char maxKeyCode;
    unsigned short present;
    unsigned short firstType;
    unsigned short nTypes;
    unsigned short totalTypes;
    unsigned short firstKeySym;
    unsigned short nKeySyms;
    unsigned short totalSyms;
    unsigned short firstKeyAct;
    unsigned short nKeyActs;
    unsigned short totalActs;
    unsigned short firstKeyBehavior;
    unsigned short nKeyBehaviors;
    unsigned short totalKeyBehaviors;
    unsigned short firstKeyExplicit;
    unsigned short nKeyExplicit;
    unsigned short totalKeyExplicit;
    unsigned short firstModMapKey;
    unsigned short nModMapKeys;
    unsigned short totalModMapKeys;
    unsigned short firstVModMapKey;
    unsigned short nVModMapKeys;
    unsigned short totalVModMapKeys;
    unsigned short virtualMods;
} xkbGetMapReply;

typedef struct _xkbGetCompatMapReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned short groups;
    unsigned short firstSI;
    unsigned short nSI;
    unsigned short nTotalSI;
} xkbGetCompatMapReply;

typedef struct _xkbGetIndicatorMapReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned int which;
} xkbGetIndicatorMapReply;

typedef struct _xkbGetNamesReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned int which;
    unsigned char minKeyCode;
    unsigned char maxKeyCode;
    unsigned short nTypes;
    unsigned short nKTLevels;
    unsigned short groupNames;
    unsigned short virtualMods;
    unsigned short indicators;
    unsigned short nRadioGroups;
    unsigned short firstKey;
    unsigned short nKeys;
    unsigned short nKeyAliases;
} xkbGetNamesReply;

typedef struct _xkbGetGeometryReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short deviceID;
    unsigned char found;
    unsigned char pad;
    unsigned short widthMM;
    unsigned short heightMM;
    unsigned short nProperties;
    unsigned short nColors;
    unsigned short nShapes;
    unsigned short nSections;
    unsigned short nDoodads;
    unsigned short baseColorNdx;
    unsigned short labelColorNdx;
} xkbGetGeometryReply;

typedef struct _xGenericReply {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
} xGenericReply;

typedef struct _xkbGetKbdByNameReq {
    unsigned char reqType;
    unsigned char xkbReqType;
    unsigned short length;
    unsigned short deviceSpec;
    unsigned short want;
    unsigned short need;
    unsigned char load;
    unsigned char pad0;
    unsigned short pad1;
} xkbGetKbdByNameReq;

struct _ClientRec {
    unsigned int sequence;
    unsigned int xkbClientFlags;
    Bool swapped;
    unsigned int length;
};

struct _DeviceIntRec {
    int id;
    struct _DeviceIntRec *next;
    struct _DeviceIntRec *lastSlave;
    struct {
        struct {
            XkbDescPtr desc;
        } *xkbInfo;
    } *key;
    struct {
        struct {
            XkbSrvLedInfoPtr xkb_sli;
        } *kbdfeed;
    };
};

struct _XkbDescRec {
    unsigned char min_key_code;
    unsigned char max_key_code;
    struct {
        unsigned int num_types;
    } *map;
    struct {
        unsigned int num_si;
    } *compat;
    struct {
        unsigned int num_rg;
        unsigned int num_key_aliases;
    } *names;
    void *geom;
    void *indicators;
};

struct _XkbSrvLedInfoRec {
    unsigned int explicitState;
    unsigned int effectiveState;
};

struct {
    DeviceIntPtr devices;
} inputInfo;

#define X_Reply 1
#define BadAccess 1
#define BadMatch 1
#define BadLength 1
#define Success 1
#define XkbGBN_AllComponentsMask 0xffff
#define XkbGBN_CompatMapMask 0x01
#define XkbGBN_IndicatorMapMask 0x02
#define XkbGBN_TypesMask 0x04
#define XkbGBN_SymbolsMask 0x08
#define XkbGBN_GeometryMask 0x10
#define XkbGBN_OtherNamesMask 0x20
#define XkbGBN_KeyNamesMask 0x40
#define XkbGBN_ClientSymbolsMask 0x80
#define XkbGBN_ServerSymbolsMask 0x100
#define XkmVirtualModsMask 0x01
#define XkmKeymapRequired 0x02
#define XkmKeymapLegal 0x04
#define XkmSymbolsMask 0x08
#define XkmKeyNamesIndex 0x10
#define XkmTypesIndex 0x20
#define XkmIndicatorsIndex 0x40
#define XkbKeyTypesMask 0x01
#define XkbKeySymsMask 0x02
#define XkbModifierMapMask 0x04
#define XkbAllServerInfoMask 0x08
#define XkbAllNamesMask 0x01
#define XkbKeyNamesMask 0x02
#define XkbKeyAliasesMask 0x04
#define XkbAllGroupsMask 0x01
#define XkbAllVirtualModsMask 0x01
#define XkbAllIndicatorsMask 0x01
#define XkbNKN_KeycodesMask 0x01
#define XkbNKN_GeometryMask 0x02
#define XkbReqCode 0x01
#define X_kbGetKbdByName 0x01
#define DixGetAttrAccess 0x01
#define DixManageAccess 0x02
#define MASTER_KEYBOARD 0x01
#define None 0x00
#define _XkbClientInitialized 0x01

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_AT_LEAST_SIZE(x) \
    if (client->length < (sizeof(x) >> 2)) \
        return BadLength
#define CHK_KBD_DEVICE(dev, spec, client, mode) \
    dev = (DeviceIntPtr)spec
#define GetMaster(dev, type) dev
#define XkbNumKeys(xkb) (xkb->max_key_code - xkb->min_key_code + 1)
#define XkbPaddedSize(size) (((size) + 3) & ~3)
#define Xstrdup(str) strdup(str)
#define SIZEOF(x) sizeof(x)
#define swaps(x)
#define swapl(x)
#define WriteToClient(client, size, data)
#define XkbSendMap(client, xkb, rep)
#define XkbSendCompatMap(client, compat, rep)
#define XkbSendIndicatorMap(client, indicators, rep)
#define XkbSendNames(client, xkb, rep)
#define XkbSendGeometry(client, geom, rep, flag)
#define XkbSendNewKeyboardNotify(dev, nkn)
#define XkbDeviceApplyKeymap(dev, xkb)
#define XkbAllocSrvLedInfo(dev, feed, ctrls, flags) NULL
#define XkbFreeSrvLedInfo(sli)
#define XkbFreeKeyboard(xkb, mask, freeDesc)
#define XkbFreeComponentNames(names, freeAll)
#define XkbSetCauseXkbReq(cause, major, client)
#define XkbUpdateAllDeviceIndicators(dev, cause)
#define XkbCopyControls(dst, src)
#define XkbUpdateDescActions(xkb, min, max, changes)
#define XkbComputeGetMapReplySize(xkb, rep)
#define XkbComputeGetCompatMapReplySize(compat, rep)
#define XkbComputeGetIndicatorMapReplySize(indicators, rep)
#define XkbComputeGetNamesReplySize(xkb, rep)
#define XkbComputeGetGeometryReplySize(geom, rep, atom)
#define GetComponentSpec(str, flag, status) NULL
#define XkbDDXLoadKeymapByNames(dev, names, fwant, fneed, new, mapFile, len) 0