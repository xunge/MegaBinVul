#include <memory>
#include <stdint.h>

namespace base {
class TimeTicks {
public:
    TimeTicks();
    explicit TimeTicks(int64_t ticks);
    int64_t ToInternalValue() const;
};
}

namespace TargetProperty {
enum Type {
    TRANSFORM,
    OPACITY,
    FILTER
};
}

class AnimationPlayer {
public:
    void NotifyAnimationFinished(base::TimeTicks monotonic_time,
                                TargetProperty::Type target_property,
                                int group);
};

class PlayersListNode {
public:
    PlayersListNode* next();
    AnimationPlayer* value();
};

class ElementAnimations {
public:
    class PlayersList {
    public:
        class Iterator {
        public:
            explicit Iterator(PlayersList* list);
            AnimationPlayer* GetNext();
        };

        PlayersListNode* head();
        PlayersListNode* end();
    };

    using PlayersListPtr = std::unique_ptr<PlayersList>;
    PlayersListPtr players_list_;

    void NotifyPlayersAnimationFinished(
        base::TimeTicks monotonic_time,
        TargetProperty::Type target_property,
        int group);
};