#include <vector>

class AnimationPlayer;
class ObserverList;

class ElementAnimations {
public:
    ObserverList* players_list_;
    void AddPlayer(AnimationPlayer* player);
};

class ObserverList {
public:
    void AddObserver(AnimationPlayer* player);
    void Append(AnimationPlayer* player);
};