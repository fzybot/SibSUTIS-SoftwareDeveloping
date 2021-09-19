#include "mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QGraphicsScene* scene = new QGraphicsScene();
    // Отрисовка простых элементов
//    scene->setSceneRect(0, 0, 1500, 1500);
//    scene->addLine(20.0, 50.0, 50.0, 200.0);
//    scene->addRect(100.0, 50.0, 60.0, 80.0);
//    scene->addEllipse(200.0, 100.0, 80.0, 80.0);

    QPixmap map(200, 200); // создаем карту для рисования
    QPainter p(&map);
    p.setPen(QColor(100, 10, 100, 127));
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
                p.drawPoint(i, j);
        }
    }
    p.end();
    scene->addPixmap(map);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);
    createDockWindows();
    createActions();
    createMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Config"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QListWidget *firstList;
    firstList = new QListWidget(dock);
    firstList->addItems(QStringList()
            << "One"
            << "Two"
            << "Three");
    dock->setWidget(firstList);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
//    viewMenu->addAction(dock->toggleViewAction());

    dock = new QDockWidget(tr("Paragraphs"), this);
    QListWidget *secondList;
    secondList = new QListWidget(dock);
    secondList->addItems(QStringList()
            << "Hello, it's one"
            << "Helloo"
            << "Hell");
    dock->setWidget(secondList);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

}

void MainWindow::createMenu()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

}

void MainWindow::newFile()
{
    this->setWindowTitle("New File");
}

void MainWindow::open()
{
    this->setWindowTitle("Open");
}

void MainWindow::save()
{
    this->setWindowTitle("Save");
}

