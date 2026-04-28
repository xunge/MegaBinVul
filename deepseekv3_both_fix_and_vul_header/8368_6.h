#include <stddef.h>

enum CSSPropertyID {
    CSSPropertyWebkitTextDecorationsInEffect,
    // Add other CSS property IDs as needed
};

enum CSSPropertyOverrideMode {
    OverrideValues,
    DoNotOverrideValues
};

class CSSValue {
public:
    bool isValueList() const { return false; }
    const char* cssText() const { return ""; }
};

class CSSValueList : public CSSValue {
};

class StylePropertySet {
public:
    class PropertyReference {
    public:
        CSSPropertyID id() const { return CSSPropertyWebkitTextDecorationsInEffect; }
        const CSSValue& value() const { static CSSValue v; return v; }
        bool isImportant() const { return false; }
        CSSPropertyID toCSSProperty() const { return CSSPropertyWebkitTextDecorationsInEffect; }
        const char* valueText() const { return ""; }
    };

    PropertyReference propertyAt(unsigned) const { return PropertyReference(); }
    unsigned propertyCount() const { return 0; }
    StylePropertySet* mutableCopy() const { return nullptr; }
    const CSSValue* getPropertyCSSValue(CSSPropertyID) const { return nullptr; }
    void setProperty(CSSPropertyID, const CSSValue*, bool) {}
    void setProperty(CSSPropertyID, const char*, bool) {}
    void setProperty(CSSPropertyID id) { setProperty(id, propertyAt(0).valueText(), false); }
};

class EditingStyle {
public:
    void mergeStyle(const StylePropertySet*, CSSPropertyOverrideMode);
protected:
    StylePropertySet* m_mutableStyle;
    CSSPropertyID textDecorationPropertyForEditing() const { return CSSPropertyWebkitTextDecorationsInEffect; }
    CSSValueList* mergeTextDecorationValues(const CSSValueList&, const CSSValueList&) { return nullptr; }
};

CSSValueList* toCSSValueList(const CSSValue* value) { return nullptr; }
const CSSValueList& toCSSValueList(const CSSValue& value) { static CSSValueList v; return v; }