#include <stdint.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef uint32_t guint;
typedef int gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *pool;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct value_string {
    guint32 value;
    const char *strptr;
} value_string;

static int propertyIdentifier = -1;
static int propertyArrayIndex = 0;
static guint32 object_type = 0;
static const value_string BACnetPropertyIdentifier[] = { {0, NULL} };
static const char *ASHRAE_Reserved_Fmt = NULL;
static const char *Vendor_Proprietary_Fmt = NULL;
static const value_string BACnetAcknowledgedTransitions[] = { {0, NULL} };
static const value_string BACnetAction[] = { {0, NULL} };
static const value_string BACnetLifeSafetyState[] = { {0, NULL} };
static const value_string BACnetDoorAlarmState[] = { {0, NULL} };
static const value_string BACnetTimerState[] = { {0, NULL} };
static const value_string BACnetAccessZoneOccupancyState[] = { {0, NULL} };
static const value_string BACnetEventType[] = { {0, NULL} };
static const value_string BACnetLimitEnable[] = { {0, NULL} };
static const value_string BACnetServicesSupported[] = { {0, NULL} };
static const value_string BACnetSegmentation[] = { {0, NULL} };
static const value_string BACnetStatusFlags[] = { {0, NULL} };
static const value_string BACnetDeviceStatus[] = { {0, NULL} };
static const value_string BACnetEngineeringUnits[] = { {0, NULL} };
static const value_string BACnetObjectType[] = { {0, NULL} };
static const value_string BACnetEventState[] = { {0, NULL} };
static const value_string BACnetReliability[] = { {0, NULL} };
static const value_string BACnetNotifyType[] = { {0, NULL} };
static const value_string BACnetNodeType[] = { {0, NULL} };
static const value_string BACnetDoorStatus[] = { {0, NULL} };
static const value_string BACnetLockStatus[] = { {0, NULL} };
static const value_string BACnetDoorSecuredStatus[] = { {0, NULL} };
static const value_string BACnetMaintenance[] = { {0, NULL} };
static const value_string BACnetProgramState[] = { {0, NULL} };
static const value_string BACnetProgramRequest[] = { {0, NULL} };
static const value_string BACnetProgramError[] = { {0, NULL} };
static const value_string BACnetLifeSafetyMode[] = { {0, NULL} };
static const value_string BACnetSilencedState[] = { {0, NULL} };
static const value_string BACnetLifeSafetyOperation[] = { {0, NULL} };
static const value_string BACnetFileAccessMethod[] = { {0, NULL} };
static const value_string BACnetLoggingType[] = { {0, NULL} };
static const value_string BACnetAccessPassbackMode[] = { {0, NULL} };
static const value_string BACnetAccessCredentialDisableReason[] = { {0, NULL} };
static const value_string BACnetAccessUserType[] = { {0, NULL} };
static const value_string BACnetBackupState[] = { {0, NULL} };
static const value_string BACnetWriteStatus[] = { {0, NULL} };
static const value_string BACnetLightingTransition[] = { {0, NULL} };
static const value_string BACnetSecurityLevel[] = { {0, NULL} };
static const value_string BACnetFaultType[] = { {0, NULL} };
static const value_string BACnetAuthorizationExemption[] = { {0, NULL} };
static const value_string BACnetLightingInProgress[] = { {0, NULL} };
static const value_string BACnetTimerTransition[] = { {0, NULL} };
static const value_string BACnetIpMode[] = { {0, NULL} };
static const value_string BACnetNetworkPortCommand[] = { {0, NULL} };
static const value_string BACnetNetworkNumberQuality[] = { {0, NULL} };
static const value_string BACnetNetworkType[] = { {0, NULL} };
static const value_string BACnetLiftCarDirection[] = { {0, NULL} };
static const value_string BACnetLiftCarDoorCommand[] = { {0, NULL} };
static const value_string BACnetLiftCarDriveStatus[] = { {0, NULL} };
static const value_string BACnetLiftCarMode[] = { {0, NULL} };
static const value_string BACnetEscalatorMode[] = { {0, NULL} };
static const value_string BACnetLiftFault[] = { {0, NULL} };
static const value_string BACnetEscalatorFault[] = { {0, NULL} };
static const value_string BACnetLiftGroupMode[] = { {0, NULL} };
static const value_string BACnetEscalatorOperationDirection[] = { {0, NULL} };
static const value_string BACnetProtocolLevel[] = { {0, NULL} };
static const value_string BACnetRelationship[] = { {0, NULL} };
static const value_string BACnetDoorValue[] = { {0, NULL} };
static const value_string BACnetShedState[] = { {0, NULL} };
static const value_string BACnetAuthorizationMode[] = { {0, NULL} };

static const unsigned BACAPP_MAX_RECURSION_DEPTH = 10;
static int proto_bacapp = -1;
static int ei_bacapp_max_recursion_depth_reached = 0;

static inline guint GPOINTER_TO_UINT(void *p) { return (guint)(uintptr_t)p; }
static inline void *GUINT_TO_POINTER(guint u) { return (void *)(uintptr_t)u; }

static gboolean tag_is_context_specific(guint8 tag_info) { return 0; }
static gboolean tag_is_opening(guint8 tag_info) { return 0; }

static const char *val_to_split_str(int val, int width, const value_string *vs, const char *reserved_fmt, const char *vendor_fmt) {
    return NULL;
}

static int g_snprintf(char *str, size_t size, const char *format, ...) {
    return 0;
}

static void *p_get_proto_data(void *pool, packet_info *pinfo, int proto, int idx) {
    return NULL;
}

static void p_add_proto_data(void *pool, packet_info *pinfo, int proto, int idx, void *data) {
}

static guint tvb_reported_length_remaining(tvbuff_t *tvb, guint offset) {
    return 0;
}

static void fTagHeader(tvbuff_t *tvb, packet_info *pinfo, guint offset, guint8 *tag_no, guint8 *tag_info, guint32 *lvt) {
}

static gboolean tag_is_closing(guint8 tag_info) {
    return 0;
}

static guint fApplicationTypesEnumerated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar, const value_string *vs) {
    return 0;
}

static guint fActionList(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) {
    return 0;
}

static guint fTagHeaderTree(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 *tag_no, guint8 *tag_info, guint32 *lvt) {
    return 0;
}

static guint fContextTaggedValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) {
    return 0;
}

static guint fApplicationTypes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) {
    return 0;
}

static guint fAddressBinding(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLOPR(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static void fSessionKey(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) {}
static guint fApplicationTypesEnumeratedSplit(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar, const value_string *vs, int split) { return 0; }
static guint fDestination(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fPriorityArray(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fSpecialEvent(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fDeviceObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fBACnetObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fWeeklySchedule(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fClientCOV(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fEventLogRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLogMultipleRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLogRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fDeviceObjectReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fRestartReason(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fShedLevel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fCOVSubscription(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fCalendarEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fRecipient(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fEventParameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fEventTimeStamps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fTimeStamp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fDateTime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fDoorMembers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fSequenceOfEnums(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar, const value_string *vs) { return 0; }
static guint fAuthenticationFactor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fListOfGroupMembers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fSecurityKeySet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fNetworkSecurityPolicy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fAccessRule(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fAuthenticationFactorFormat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fFaultParameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fEventNotificationSubscription(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLightingCommand(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fAuthenticationPolicy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fTimerStateChangeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fHostNPort(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fBDTEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fFDTEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fRouterEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fVMACEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fValueSource(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fAssignedLandingCalls(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLandingCallStatus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLandingDoorStatus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fCOVMultipleSubscription(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fNameValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fNameValueCollection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fEnumeratedTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar, const value_string *vs) { return 0; }
static guint fChannelValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, char *ar) { return 0; }
static guint fPropertyAccessResult(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fLoggingRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fPrescale(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fScale(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }
static guint fReadAccessResult(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset) { return 0; }

static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, void *expert, tvbuff_t *tvb, int start, int length) {
}