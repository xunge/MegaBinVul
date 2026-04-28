#include <stddef.h>

class AnimationPlayer;

class PlayersListNode {
public:
    PlayersListNode* next();
    AnimationPlayer* value();
    void RemoveFromList();
};

class ObserverList {
public:
    void RemoveObserver(AnimationPlayer* player);
    PlayersListNode* head();
    PlayersListNode* end();
};

class ElementAnimations {
public:
    ObserverList* players_list_;
    void RemovePlayer(AnimationPlayer* player);
};