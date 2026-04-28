#include <stdbool.h>

#define TYPE_INPUT_METHOD 0
#define TYPE_INPUT_METHOD_DIALOG 0
#define TYPE_MAGNIFICATION_OVERLAY 0
#define TYPE_STATUS_BAR 0
#define TYPE_NAVIGATION_BAR 0
#define TYPE_SECURE_SYSTEM_OVERLAY 0

struct InputWindowInfo {
    int layoutParamsType;
    bool isTrustedOverlay() const;
};