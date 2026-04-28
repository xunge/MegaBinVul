struct QOpenGLContext;
struct QOpenGLWidget;

namespace lcShadingMode {
    enum Enum {
        DefaultLights,
        Flat
    };
}

class lcContext {
public:
    QOpenGLContext* mContext;
    QOpenGLWidget* mWidget;
    
    void SetGLContext(QOpenGLContext* Context, QOpenGLWidget* Widget);
    void MakeCurrent();
    void initializeOpenGLFunctions();
    void CreateResources();
};

class lcView {
public:
    static void CreateResources(lcContext* context);
};

class lcViewSphere {
public:
    static void CreateResources(lcContext* context);
};

class lcPreferences {
public:
    lcShadingMode::Enum mShadingMode;
    bool mDrawConditionalLines;
};

class lcMainWindow {
public:
    class PartSelectionWidget* GetPartSelectionWidget();
};

class PartSelectionWidget {
public:
    void DisableIconMode();
};

class StringCache {
public:
    void Initialize(lcContext* context);
};

class TexFont {
public:
    void Initialize(lcContext* context);
};

extern bool gSupportsShaderObjects;
extern bool gSupportsFramebufferObject;
extern int mValidContexts;
extern bool mValid;
extern StringCache gStringCache;
extern TexFont gTexFont;
extern lcMainWindow* gMainWindow;

lcPreferences& lcGetPreferences();
void lcInitializeGLExtensions(QOpenGLContext* Context);