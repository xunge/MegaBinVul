#include <stddef.h>

class HValue {
public:
    virtual ~HValue() = default;
};

class HInstruction : public HValue {
public:
    virtual ~HInstruction() = default;
};

class Object {
public:
    bool IsJSObject() const;
};

class FixedArrayBase {
public:
    virtual int length() const = 0;
};

class FixedArray : public FixedArrayBase {
public:
    int length() const override;
    Object* get(int index) const;
};

class JSObject;
class AllocationSite;

enum ElementsKind {
    FAST_HOLEY_SMI_ELEMENTS,
    FAST_HOLEY_ELEMENTS
};

enum AllowReturnHole {
    ALLOW_RETURN_HOLE
};

template<typename T>
class Handle {
public:
    Handle(T* object, void* isolate);
    template<typename U>
    static Handle<T> cast(Handle<U> obj);
    T* operator->() const;
    T* get() const;
};

class HConstant : public HInstruction {
public:
    HConstant(Handle<FixedArrayBase> elements);
    HConstant(int value);
    operator HValue*() const;
};

class HLoadKeyed : public HInstruction {
public:
    HLoadKeyed(HInstruction* elements, HValue* key, HValue* dependency,
               ElementsKind kind, AllowReturnHole flag);
};

class HStoreKeyed : public HInstruction {
public:
    HStoreKeyed(HValue* object, HValue* key, HInstruction* value,
                ElementsKind kind);
};

class AllocationSiteUsageContext {
public:
    Handle<AllocationSite> EnterNewScope();
    void ExitScope(Handle<AllocationSite> site, Handle<JSObject> object);
};

class HOptimizedGraphBuilder {
public:
    template<typename T, typename U>
    T* Add(Handle<U> value);
    template<typename T>
    T* Add(int value);
    template<typename T>
    T* Add(HInstruction* elements, HValue* key, HValue* dependency,
           ElementsKind kind, AllowReturnHole flag);
    template<typename T>
    T* Add(HValue* object, HValue* key, HInstruction* value, ElementsKind kind);
    void BuildEmitFixedArray(Handle<FixedArrayBase> elements,
                            ElementsKind kind,
                            HValue* object_elements,
                            AllocationSiteUsageContext* site_context);
    HInstruction* BuildFastLiteral(Handle<JSObject> object,
                                  AllocationSiteUsageContext* site_context);
    void* isolate();
};