#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../src/jumplist.h"
#include "../src/appusermodel.h"
#include "../src/taskbarbutton.h"
#include "../src/taskbartoolbar.h"
#include "../src/taskbar.h"
#include "../src/taskbartabs.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

#ifdef Q_OS_WIN32
protected:
    bool winEvent(MSG * message, long * result);
#endif //Q_OS_WIN32

private:
    QAction* special;
    Ui::MainWindow *ui;
    QMainWindow* mainwindow2;
    QW7::JumpList mJumpList;
    QW7::TaskbarButton* mTaskbar;
    QW7::TaskbarToolbar* mToolbar;
    QW7::TaskbarTabs* mTabs;

private slots:
    void actionpressed();
    void on_pushButton_clicked();
    void tab_activated(QWidget* widget);
    void tab_remove(int index);
    void tab_remove(QWidget* widget);
    void tab_set_active(int index);
};

#endif // MAINWINDOW_H
