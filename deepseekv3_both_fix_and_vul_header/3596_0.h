#include <climits>
#include <cstddef>

class Position {
public:
    enum AnchorType {
        PositionIsOffsetInAnchor
    };

    Position() = default;
    Position(void* node, unsigned offset) {}

    void* anchorNode() const { return nullptr; }
    AnchorType anchorType() const { return PositionIsOffsetInAnchor; }
    int offsetInContainerNode() const { return 0; }
};

class CharacterData {
public:
    unsigned length() const { return 0; }
};

class Text : public CharacterData {};

Text* toText(CharacterData* node) { return static_cast<Text*>(node); }

#define ASSERT(expr) ((void)0)
#define ASSERT_WITH_SECURITY_IMPLICATION(expr) ((void)0)