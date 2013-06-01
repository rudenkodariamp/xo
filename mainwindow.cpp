//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myView = new mgv();

    ui->verticalLayout->addWidget(myView);


}

MainWindow::~MainWindow()
{
    delete ui;
}
