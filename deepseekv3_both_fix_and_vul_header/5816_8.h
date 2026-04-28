#include <stdbool.h>
#include <string>

class KURL {
public:
    std::string url() const;
};

class FrameHost {
public:
    static const int maxNumberOfFrames = 10;
    int subframeCount() const;
};

class LocalFrame;

class Frame {
public:
    Frame* parent() const;
    bool isLocalFrame() const;
    LocalFrame* toLocalFrame(const Frame* frame) const;
    class Tree {
    public:
        Frame* parent() const;
    };
    Tree& tree() { return m_tree; }
    const Tree& tree() const { return m_tree; }
private:
    Tree m_tree;
};

class LocalFrame : public Frame {
public:
    bool isURLAllowed(const KURL& url) const;
    FrameHost* host() const;
    class Document {
    public:
        KURL url() const;
    };
    Document* document() const;
};

bool equalIgnoringFragmentIdentifier(const KURL&, const KURL&);

inline LocalFrame* Frame::toLocalFrame(const Frame* frame) const {
    return frame ? const_cast<LocalFrame*>(static_cast<const LocalFrame*>(frame)) : nullptr;
}