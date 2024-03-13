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
    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &Model::redPressed);
    connect(ui->startButton,
            &QPushButton::clicked,
            &model,
            &Model::startPressed);
    connect(&model,
            &Model::changeColorBlue,
            ui->blueButton,
            &QPushButton::setStyleSheet);
    connect(&model,
            &Model::changeColorRed,
            ui->redButton,
            &QPushButton::setStyleSheet);
    connect(&model,
            &Model::redBlueOn,
            ui->blueButton,
            &QPushButton::setEnabled);
    connect(&model,
            &Model::redBlueOn,
            ui->redButton,
            &QPushButton::setEnabled);
    connect(&model,
            &Model::startOn,
            ui->startButton,
            &QPushButton::setEnabled);
}

MainWindow::~MainWindow()
{
    delete ui;
}
