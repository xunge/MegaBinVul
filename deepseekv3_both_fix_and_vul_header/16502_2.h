namespace interfaces {
    class Node;
}

class QApplication {
public:
    QApplication(int&, char**);
    void setQuitOnLastWindowClosed(bool);
};

class BitcoinApplication : public QApplication {
public:
    BitcoinApplication(interfaces::Node& node);
    BitcoinApplication(interfaces::Node& node, int &argc, char **argv);

private:
    interfaces::Node& m_node;
    void* coreThread;
    void* optionsModel;
    void* clientModel;
    void* window;
    void* pollShutdownTimer;
    int returnValue;
    void* platformStyle;
    static int qt_argc;
    static char* qt_argv;
};

int BitcoinApplication::qt_argc;
char* BitcoinApplication::qt_argv;