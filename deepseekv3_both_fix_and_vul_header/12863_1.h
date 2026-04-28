#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int GF_Err;
typedef int Fixed;

typedef enum {
    GF_OK = 0,
    GF_NON_COMPLIANT_BITSTREAM
} GF_ErrorCode;

typedef enum {
    GF_EVENT_REPEAT,
    GF_EVENT_REPEAT_EVENT
} GF_EventType;

typedef enum {
    DOM_String_datatype,
    SVG_Boolean_datatype,
    SVG_Color_datatype,
    SVG_Paint_datatype,
    SVG_FillRule_datatype,
    SVG_StrokeLineJoin_datatype,
    SVG_StrokeLineCap_datatype,
    SVG_FontStyle_datatype,
    SVG_FontWeight_datatype,
    SVG_FontVariant_datatype,
    SVG_TextAnchor_datatype,
    SVG_Display_datatype,
    SVG_Visibility_datatype,
    SVG_Overflow_datatype,
    SVG_ZoomAndPan_datatype,
    SVG_DisplayAlign_datatype,
    SVG_TextAlign_datatype,
    SVG_PointerEvents_datatype,
    SVG_RenderingHint_datatype,
    SVG_VectorEffect_datatype,
    SVG_PlaybackOrder_datatype,
    SVG_TimelineBegin_datatype,
    XML_Space_datatype,
    XMLEV_Propagate_datatype,
    XMLEV_DefaultAction_datatype,
    XMLEV_Phase_datatype,
    SMIL_SyncBehavior_datatype,
    SMIL_SyncTolerance_datatype,
    SMIL_AttributeType_datatype,
    SMIL_CalcMode_datatype,
    SMIL_Additive_datatype,
    SMIL_Accumulate_datatype,
    SMIL_Restart_datatype,
    SMIL_Fill_datatype,
    SVG_GradientUnit_datatype,
    SVG_FocusHighlight_datatype,
    SVG_Focusable_datatype,
    SVG_InitialVisibility_datatype,
    SVG_Overlay_datatype,
    SVG_TransformBehavior_datatype,
    SVG_SpreadMethod_datatype,
    SVG_Filter_TransferType_datatype,
    SVG_Length_datatype,
    SVG_Coordinate_datatype,
    SVG_FontSize_datatype,
    SVG_Rotate_datatype,
    SVG_Number_datatype,
    SMIL_AnimateValue_datatype,
    SMIL_AnimateValues_datatype,
    XMLRI_datatype,
    XML_IDREF_datatype,
    SMIL_AttributeName_datatype,
    SMIL_Times_datatype,
    SMIL_Duration_datatype,
    SMIL_RepeatCount_datatype,
    SVG_PathData_datatype,
    SVG_Points_datatype,
    SMIL_KeyTimes_datatype,
    SMIL_KeyPoints_datatype,
    SMIL_KeySplines_datatype,
    SVG_Numbers_datatype,
    SVG_Coordinates_datatype,
    SVG_ViewBox_datatype,
    SVG_StrokeDashArray_datatype,
    SVG_FontFamily_datatype,
    SVG_Motion_datatype,
    SVG_Transform_datatype,
    SVG_Transform_Translate_datatype,
    SVG_Transform_Scale_datatype,
    SVG_Transform_SkewX_datatype,
    SVG_Transform_SkewY_datatype,
    SVG_Transform_Rotate_datatype,
    SVG_PreserveAspectRatio_datatype,
    SVG_TransformType_datatype,
    SVG_ID_datatype,
    SVG_ContentType_datatype,
    SVG_LanguageID_datatype,
    DOM_StringList_datatype,
    XMLRI_List_datatype,
    XMLEV_Event_datatype,
    SVG_Focus_datatype,
    SVG_ClipPath_datatype,
    LASeR_Choice_datatype,
    LASeR_Size_datatype,
    SVG_Clock_datatype,
    SVG_Unknown_datatype
} GF_FieldType;

typedef struct {
    GF_FieldType fieldType;
    void *far_ptr;
    char *name;
} GF_FieldInfo;

typedef struct GF_Node GF_Node;
typedef struct GF_List GF_List;
typedef char *SVG_String;
typedef int SVG_Boolean;
typedef int SVG_Color;
typedef int SVG_Paint;
typedef int SVG_FillRule;
typedef int SVG_StrokeLineJoin;
typedef int SVG_StrokeLineCap;
typedef int SVG_FontStyle;
typedef int SVG_FontWeight;
typedef int SVG_FontVariant;
typedef int SVG_TextAnchor;
typedef int SVG_Display;
typedef int SVG_Visibility;
typedef int SVG_Overflow;
typedef int SVG_ZoomAndPan;
typedef int SVG_DisplayAlign;
typedef int SVG_TextAlign;
typedef int SVG_PointerEvents;
typedef int SVG_RenderingHint;
typedef int SVG_VectorEffect;
typedef int SVG_PlaybackOrder;
typedef int SVG_TimelineBegin;
typedef int XML_Space;
typedef int XMLEV_Propagate;
typedef int XMLEV_DefaultAction;
typedef int XMLEV_Phase;
typedef int SMIL_SyncBehavior;
typedef int SMIL_SyncTolerance;
typedef int SMIL_AttributeType;
typedef int SMIL_CalcMode;
typedef int SMIL_Accumulate;
typedef int SMIL_Restart;
typedef int SMIL_Fill;
typedef enum {
    SVG_GRADIENTUNITS_USER,
    SVG_GRADIENTUNITS_OBJECT
} SVG_GradientUnit;
typedef int SVG_FocusHighlight;
typedef int SVG_Focusable;
typedef int SVG_InitialVisibility;
typedef int SVG_Overlay;
typedef int SVG_TransformBehavior;
typedef enum {
    SVG_SPREAD_REFLECT,
    SVG_SPREAD_REPEAT,
    SVG_SPREAD_PAD
} SVG_SpreadMethod;
typedef enum {
    SVG_FILTER_TRANSFER_TABLE,
    SVG_FILTER_TRANSFER_DISCRETE,
    SVG_FILTER_TRANSFER_LINEAR,
    SVG_FILTER_TRANSFER_GAMMA,
    SVG_FILTER_TRANSFER_IDENTITY,
    SVG_FILTER_TRANSFER_FRACTAL_NOISE,
    SVG_FILTER_TRANSFER_TURBULENCE,
    SVG_FILTER_MX_MATRIX,
    SVG_FILTER_MX_SATURATE,
    SVG_FILTER_HUE_ROTATE,
    SVG_FILTER_LUM_TO_ALPHA
} SVG_Filter_TransferType;
typedef int SVG_Number;
typedef int SMIL_AnimateValue;
typedef int SMIL_AnimateValues;
typedef int XMLRI;
typedef struct {
    char *name;
} SMIL_AttributeName;
typedef int SMIL_Duration;
typedef int SMIL_RepeatCount;
typedef int SVG_PathData;
typedef int SVG_ViewBox;
typedef int SVG_StrokeDashArray;
typedef int SVG_FontFamily;
typedef struct {
    Fixed x, y;
} SVG_Point;
typedef struct {
    Fixed x, y, angle;
} SVG_Point_Angle;
typedef struct {
    Fixed a, b, c, d, e, f;
} GF_Matrix2D;
typedef int SVG_Transform;
typedef int SVG_PreserveAspectRatio;
typedef int SVG_TransformType;
typedef int LASeR_Choice;
typedef int LASeR_Size;
typedef int SVG_Clock;
typedef struct {
    GF_EventType type;
    int parameter;
} XMLEV_Event;
typedef int SVG_Focus;
typedef int SVG_ClipPath;

#define GF_EXPORT
#define GF_LOG(level, category, message)
#define gf_strdup strdup
#define gf_free free
#define gf_error_to_string(e) ""
#define gf_dom_event_type_by_name(name) 0
#define gf_dom_get_key_type(name) 0