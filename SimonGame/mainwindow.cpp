#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include <QMediaPlayer>
#include <QAudioOutput>

///
/// \brief Main window connects all the signals to slots, allowing our front end and back end to communicate with eachother.
/// \param model
/// \param parent
///
MainWindow::MainWindow(Model& model,QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(15);
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
            &Model::soundEffect,
            player,
            &QMediaPlayer::play);
    connect(&model,
            &Model::changeSound,
            player,
            &QMediaPlayer::setSource);
    connect(&model,
            &Model::updateProgressValue,
            ui->progressBar,
            &QProgressBar::setValue);
    connect(&model,
            &Model::updateProgressMinimum,
            ui->progressBar,
            &QProgressBar::setMinimum);
    connect(&model,
            &Model::updateProgressMaximum,
            ui->progressBar,
            &QProgressBar::setMaximum);
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
    connect(&model,
            &Model::loseMessage,
            ui->youLoseLabel,
            &QPushButton::setVisible);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
}
