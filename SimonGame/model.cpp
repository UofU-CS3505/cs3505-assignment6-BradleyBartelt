// NOTE: Please add comments to your work.
// There are no comments in these files created for lecture.

#include "model.h"
#include "mytimer.h"
#include <vector>

//TODO:
// speed up as more moves are added
// creative feature, and good visuals

Model::Model(QObject *parent) : QObject(parent) {

}
void Model::bluePressed() {
    playerCombo.push_back(true);
    if(playerCombo.back() != colorCombo.at(playerCombo.size() - 1)){
        endGame();
        return;
    }
    emitColor('b');
    emit updateProgressValue(currentInputs);
    QTimer::singleShot(150, this, &Model::blueGrey);
}
void Model::blueGrey() {
    emitColor('g');
}
void Model::startPressed(){
   emit startOn(false);
   lengthOfSequence = 3;
   currentInputs = 0;
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
    emit updateProgressValue(currentInputs);
    QTimer::singleShot(150, this, &Model::redGrey);
}
void Model::redGrey() {
    emitColor('g');
}
void Model::startGame(){
    emit loseMessage(false);
    emit startOn(false);
    emit updateProgressMinimum(0);
    emit updateProgressValue(0);
    speedup = 0;
    lengthOfSequence = 3;
    currentInputs = 0;
    for(int i = 0; i < 100; i++){
        colorCombo.push_back(arc4random() % 2);
    }
    displaySequence();
}
void Model::displaySequence(){
    emit updateProgressMaximum(lengthOfSequence);
    if(speedup < 600)
        speedup = (lengthOfSequence - 3) * 100;
    int waitTime = 0;
    for(int i = 0; i < lengthOfSequence; i++){
        if(i > 0)
            waitTime = i * (1000 - speedup);
        if(colorCombo.at(i)){
            QTimer::singleShot(waitTime, this, &Model::computerBlue);
        }
        else{
            QTimer::singleShot(waitTime, this, &Model::computerRed);
        }
    }
}
void Model::emitColor(char color){
    if(color == 'r'){
        currentInputs++;
        emit changeColorRed(QString("QPushButton {background-color: rgb(220,20,60);}"
                                    " QPushButton:pressed {background-color: rgb(220,20,60);}"));
    }
    else if(color == 'b'){
        currentInputs++;
        emit changeColorBlue(QString("QPushButton {background-color: rgb(0,191,255);}"
                                     " QPushButton:pressed {background-color: rgb(0,191,255);}"));
    }
    else if(color == 'g'){
        emit changeColorBlue(QString("QPushButton {background-color: rgb(128,128,128);}"
                                     " QPushButton:pressed {background-color: rgb(128,128,128);}"));
        emit changeColorRed(QString("QPushButton {background-color: rgb(128,128,128);}"
                                    " QPushButton:pressed {background-color: rgb(128,128,128);}"));
    }
    if(currentInputs == lengthOfSequence){
        emit redBlueOn(true);
        currentInputs = 0;
    }
    if(int(playerCombo.size()) == lengthOfSequence){
        playerCombo.clear();
        currentInputs = 0;
        lengthOfSequence++;
        emit redBlueOn(false);
        QTimer::singleShot(1500, this, &Model::displaySequence);
    }
}
void Model::endGame(){
    emit loseMessage(true);
    emit startOn(true);
    emit redBlueOn(false);
    playerCombo.clear();
    colorCombo.clear();
    lengthOfSequence = 3;
    currentInputs = 0;
}
void Model::computerRed(){
    emitColor('r');
    QTimer::singleShot(300, this, &Model::redGrey);
}
void Model::computerBlue(){
    emitColor('b');
    QTimer::singleShot(300, this, &Model::blueGrey);
}

