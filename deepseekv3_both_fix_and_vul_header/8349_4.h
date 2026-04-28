#include <memory>

namespace base {
class TimeTicks {};
}

namespace TargetProperty {
enum Type {};
}

class AnimationPlayer {
public:
    void NotifyAnimationAborted(base::TimeTicks monotonic_time,
                              TargetProperty::Type target_property,
                              int group);
};

class PlayersListNode {
public:
    PlayersListNode* next() const;
    AnimationPlayer* value() const;
};

class PlayersList {
public:
    PlayersListNode* head() const;
    PlayersListNode* end() const;
    class Iterator {
    public:
        explicit Iterator(PlayersList* list);
        AnimationPlayer* GetNext();
    private:
        PlayersList* list_;
    };
};

class ElementAnimations {
public:
    using PlayersList = ::PlayersList;
    std::unique_ptr<PlayersList> players_list_;
    void NotifyPlayersAnimationAborted(base::TimeTicks monotonic_time,
                                     TargetProperty::Type target_property,
                                     int group);
};