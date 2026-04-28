#include <stddef.h>

struct Map;
struct Zone;

struct HValue {
    HValue* ActualValue();
};

template<typename T>
struct UniqueSet {
    bool Contains(T* map);
    UniqueSet<T>* Copy(Zone* zone);
    void Remove(T* map);
    void Add(T* map, Zone* zone);
};

struct HTransitionElementsKind {
    HValue* object();
    Map* original_map();
    Map* transitioned_map();
    bool map_is_stable();
    void DeleteAndReplaceWith(HValue* object);
};

struct HCheckTableEntry {
    enum State {
        CHECKED_STABLE,
        CHECKED
    };
    UniqueSet<Map>* maps_;
    State state_;
};

HCheckTableEntry* Find(HValue* object);
void Kill(HValue* object);
void EnsureChecked(HCheckTableEntry* entry, HValue* object, HTransitionElementsKind* instr);
void Insert(HValue* object, void* null, UniqueSet<Map>* maps, HCheckTableEntry::State state);
Zone* zone();
extern int transitions_;
void INC_STAT(int stat);