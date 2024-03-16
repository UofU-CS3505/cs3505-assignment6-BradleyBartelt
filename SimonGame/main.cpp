#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
/*
 * Team: Isaac Hall and Bradley Bartelt
 * Github Usernames: Isaac-Hall1 and BradleyBartelt
 * Github link: https://github.com/UofU-CS3505/cs3505-assignment6-BradleyBartelt
 * Creative Idea: We added sound effects whenever the game started, was lost, and 4 random sound effects
 * for when the player wins each turn. This was acomplished by
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    emit model.redBlueOn(false);
    emit model.updateProgressValue(0);
    emit model.loseMessage(false);
    return a.exec();
}
