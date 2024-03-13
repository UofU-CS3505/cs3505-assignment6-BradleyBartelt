// NOTE: Please add comments to your work.
// There are no comments in these files created for lecture.

#include "model.h"
#include "mytimer.h"
#include <vector>
#include <iostream>

Model::Model(QObject *parent) : QObject(parent) {

}
void Model::bluePressed() {
    playerCombo.push_back(true);
    if(playerCombo.back() != colorCombo.at(playerCombo.size() - 1)){
        endGame();
        return;
    }
    emitColor('b');
    QTimer::singleShot(300, this, &Model::blueGrey);
}
void Model::blueGrey() {
    emitColor('g');
}
void Model::startPressed(){
   emit redBlueOn(false);
   emit startOn(false);
   emitColor('g');
   startGame();
}
void Model::redPressed() {
    playerCombo.push_back(false);
    if(playerCombo.back() != colorCombo.at(playerCombo.size() - 1)){
        endGame();
        return;
    }
    emitColor('r');
    QTimer::singleShot(300, this, &Model::redGrey);
}
void Model::redGrey() {
    emitColor('g');
}
void Model::startGame(){
    colorCombo.clear();
    playerCombo.clear();
    currentInputs = 0;
    for(int i = 0; i < 20; i++){
        colorCombo.push_back(arc4random() % 2);
    }
    for(int i = 0; i < 3; i++){
        int waitTime = i * 1000;
        if(colorCombo.at(i)){
            QTimer::singleShot(waitTime, this, &Model::bluePressed);
        }
        else{
            QTimer::singleShot(waitTime, this, &Model::redPressed);
        }
    }
}
void Model::emitColor(char color){
    if(color == 'r'){
        currentInputs++;
        emit changeColorRed(QString("QPushButton {background-color: rgb(220,20,60);}"
                                    " QPushButton:pressed {background-color: rgb(220,20,60);}"));
        std::cout<< currentInputs << std::endl;
    }
    else if(color == 'b'){
        currentInputs++;
        emit changeColorBlue(QString("QPushButton {background-color: rgb(0,191,255);}"
                                     " QPushButton:pressed {background-color: rgb(0,191,255);}"));
        std::cout<< currentInputs << std::endl;
    }
    else if(color == 'g'){
        emit changeColorBlue(QString("QPushButton {background-color: rgb(128,128,128);}"
                                     " QPushButton:pressed {background-color: rgb(128,128,128);}"));
        emit changeColorRed(QString("QPushButton {background-color: rgb(128,128,128);}"
                                    " QPushButton:pressed {background-color: rgb(128,128,128);}"));
    }
    if(currentInputs == 3){
        playerCombo.clear();
        emit redBlueOn(true);
        currentInputs = 0;
    }
}
void Model::endGame(){
    emit startOn(true);
    emit redBlueOn(false);
}

