#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createDockWindows();
    void createMenu();
    void createActions();

private slots:
    void newFile();
    void open();
    void save();

private:
    QMenu *fileMenu;

    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
};
#endif // MAINWINDOW_H
