#include <stdbool.h>

enum Granularity { CharacterGranularity };
enum { FROM_HERE };

class RenderObject;

class Node {
public:
    class RenderObject* renderer();
};

class VisiblePosition {
public:
    bool isNull() const;
    bool isNotNull() const;
    bool operator!=(const VisiblePosition& other) const;
};

class Position {
public:
    Position downstream();
    Position upstream();
    bool isCandidate();
    bool isNotNull();
    class Node* deprecatedNode();
    int deprecatedEditingOffset();
};

class VisibleSelection {
public:
    VisibleSelection(VisiblePosition start, VisiblePosition end);
    bool isCaret() const;
    bool isRange() const;
    VisiblePosition visibleStart() const;
    VisiblePosition visibleEnd() const;
    Position start() const;
    Position end() const;
};

class RenderObject {
public:
    class RenderView* view();
};

class RenderView {
public:
    void clearSelection();
    void setSelection(RenderObject* start, int startOffset, RenderObject* end, int endOffset);
};

class RenderTheme {
public:
    static RenderTheme& theme();
    double caretBlinkInterval();
};

class FrameSelection {
public:
    void updateAppearance();
    
private:
    bool m_shouldShowBlockCursor;
    bool m_caretPaint;
    VisibleSelection m_selection;
    struct {
        void stop();
        bool isActive();
        void startRepeating(double interval, int fromHere);
    } m_caretBlinkTimer;
    struct {
        RenderView* contentRenderer();
    }* m_frame;
    
    VisiblePosition modifyExtendingForward(Granularity granularity);
    bool recomputeCaretRect();
    bool shouldBlinkCaret();
    bool shouldStopBlinkingDueToTypingCommand(void* frame);
    void invalidateCaretRect();
};