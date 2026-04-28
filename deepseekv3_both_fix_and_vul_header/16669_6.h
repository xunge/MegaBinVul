#include <string>

struct QVariant {
    std::string toString() const;
    int toInt() const;
};

struct QModelIndex {
    bool isValid() const;
    QModelIndex sibling(int row, int column) const;
    int row() const;
    QVariant data() const;
};

struct QString {
    QString(const std::string& str);
    bool startsWith(const std::string& prefix) const;
    int toInt() const;
};

struct QDialogButtonBox {
    enum StandardButton { Open };
    struct Button {
        void setEnabled(bool);
    };
    Button* button(StandardButton);
};

struct ExportObjectDialog {
    void currentHasChanged(QModelIndex current);
    bool mimeTypeIsPreviewable(const QString& mime_type);
};

struct WiresharkApplication {
    void gotoFrame(int frame);
};

struct ExportObjectDialogUI {
    QDialogButtonBox* buttonBox;
};

struct ExportObjectModel {
    static const int colPacket = 0;
    static const int colContent = 1;
};

extern WiresharkApplication* wsApp;
extern ExportObjectDialogUI* eo_ui_;