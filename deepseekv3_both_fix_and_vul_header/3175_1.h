#include <string>

class SVGElement {
public:
    std::string getIdAttribute() const;
};

class RenderSVGHiddenContainer {
public:
    RenderSVGHiddenContainer(SVGElement* node);
};

class RenderSVGResourceContainer : public RenderSVGHiddenContainer {
public:
    RenderSVGResourceContainer(SVGElement* node);
protected:
    std::string m_id;
    bool m_registered;
    bool m_isInvalidating;
    bool m_isInLayout;
};