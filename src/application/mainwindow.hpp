#pragma once

#include "optionsdialog.hpp"
#include "searchdialog.hpp"

#include <hexedit/hexedit.hpp>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QUndoStack;
class QLabel;
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void about();
    void dataChanged();
    void open();
    void optionsAccepted();
    void findNext();
    bool save();
    bool saveAs();
    void saveSelectionToReadableFile();
    void saveToReadableFile();
    void setAddress(qint64 address);
    void setOverwriteMode(bool mode);
    void setSize(qint64 size);
    void showOptionsDialog();
    void showSearchDialog();

public:
    void loadFile(const QString &fileName);

private:
    void init();
    void createActions();
    void createMenus();
    void createStatusBar();
    void createToolBars();
    void readSettings();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    void writeSettings();

    QString curFile;
    QFile file;
    bool isUntitled;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *saveReadable;
    QAction *closeAct;
    QAction *exitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *saveSelectionReadable;

    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *optionsAct;
    QAction *findAct;
    QAction *findNextAct;

    HexEdit *hexEdit;
    OptionsDialog *optionsDialog;
    SearchDialog *searchDialog;
    QLabel *lbAddress, *lbAddressName;
    QLabel *lbOverwriteMode, *lbOverwriteModeName;
    QLabel *lbSize, *lbSizeName;
};
