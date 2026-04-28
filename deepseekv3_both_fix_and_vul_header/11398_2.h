#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
typedef uint32_t gunichar;

typedef struct {
    const char *start;
    const char *end;
    const char *text_end;
    gboolean is_emoji;
} PangoEmojiIter;

typedef enum {
    PANGO_EMOJI_TYPE_INVALID,
    PANGO_EMOJI_TYPE_EMOJI_EMOJI,
    PANGO_EMOJI_TYPE_EMOJI_TEXT
} PangoEmojiType;

#define PANGO_EMOJI_TYPE_IS_EMOJI(type) ((type) == PANGO_EMOJI_TYPE_EMOJI_EMOJI)
#define TRUE true
#define FALSE false

#define kZeroWidthJoinerCharacter 0x200D
#define kVariationSelector15Character 0xFE0E
#define kVariationSelector16Character 0xFE0F
#define kCombiningEnclosingCircleBackslashCharacter 0x20E0
#define kLeftSpeechBubbleCharacter 0x1F5E8
#define kRainbowCharacter 0x1F308
#define kMaleSignCharacter 0x2642
#define kFemaleSignCharacter 0x2640
#define kStaffOfAesculapiusCharacter 0x2695
#define kCombiningEnclosingKeycapCharacter 0x20E3
#define kEyeCharacter 0x1F441
#define kWavingWhiteFlagCharacter 0x1F3F3

const char* g_utf8_next_char(const char* p);
gunichar g_utf8_get_char(const char* p);
gboolean _pango_Is_Regional_Indicator(gunichar ch);
gboolean _pango_Is_Emoji_Keycap_Base(gunichar ch);
PangoEmojiType _pango_get_emoji_type(gunichar ch);