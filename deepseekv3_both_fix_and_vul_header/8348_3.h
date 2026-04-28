#include <list>
#include <memory>

class PlayersList {
public:
    bool might_have_observers() const;
    bool empty() const;
};

class ElementAnimations {
private:
    PlayersList* players_list_;
public:
    bool IsEmpty() const;
};