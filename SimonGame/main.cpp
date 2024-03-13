#include "mainwindow.h"

#include <QApplication>
/*
 * Team: Isaac Hall and Bradley Bartelt
 * Github Usernames: Isaac-Hall1 and BradleyBartelt
 * Github link: https://github.com/UofU-CS3505/cs3505-assignment6-BradleyBartelt
 * Creative Idea:
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
