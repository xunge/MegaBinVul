class lcApplication {
public:
    void Shutdown();
    void ShutdownRenderer();
};

class lcContext {
public:
    static void ShutdownRenderer();
};

class lcMainWindow {
public:
    ~lcMainWindow();
};

class lcProject {
public:
    ~lcProject();
};

class lcLibrary {
public:
    ~lcLibrary();
};

extern lcMainWindow* gMainWindow;
extern lcProject* mProject;
extern lcLibrary* mLibrary;