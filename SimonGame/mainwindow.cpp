#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"

MainWindow::MainWindow(Model& model,QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->blueButton,
            &QPushButton::clicked,
            &model,
            &Model::bluePressed);
    connect(&model,
            &Model::flashBlue,
            ui->blueButton,
            &QPushButton::setStyleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}
