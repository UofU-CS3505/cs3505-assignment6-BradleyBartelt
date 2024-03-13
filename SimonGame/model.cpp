// NOTE: Please add comments to your work.
// There are no comments in these files created for lecture.

#include "model.h"

Model::Model(QObject *parent) : QObject(parent) {

}

void Model::bluePressed() {
    emit flashBlue(QString("QPushButton {background-color: rgb(200,50,50);}"
                           " QPushButton:pressed {background-color: rgb(255,150,150);}"));
    emit flashBlue(QString("QPushButton {background-color: rgb(200,50,50);}"
                           " QPushButton:pressed {background-color: rgb(255,150,150);}"));
}
