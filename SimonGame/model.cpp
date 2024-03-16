// NOTE: Please add comments to your work.
// There are no comments in these files created for lecture.

#include "model.h"
#include "mytimer.h"
#include <vector>
#include <QAudioOutput>
#include <QMediaPlayer>

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
    if(playerCombo.back() != colorCombo.at(playerCombo.size() - 1)){ /// if the player sequence and computer sequence arent the same end the game
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
    emit changeSound(QUrl("qrc:/Sounds/start_sound.mp3"));
    emit soundEffect();
    emit updateProgressMinimum(0);
    emit updateProgressValue(0);
    speedup = 0;
    lengthOfSequence = 3;
    currentInputs = 0;
    for(int i = 0; i < 100; i++){ /// fill sequence list
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
    if(currentInputs == lengthOfSequence){ /// once the computer sequence ends start the player mode
        emit redBlueOn(true);
        currentInputs = 0;
    }
    if(int(playerCombo.size()) == lengthOfSequence){ /// when the player gets a sequence correct
        playerCombo.clear();
        currentInputs = 0;
        randomWinSound(); /// play victory sound
        lengthOfSequence++;
        emit redBlueOn(false); /// lock buttons for computer sequence
        QTimer::singleShot(1500, this, &Model::displaySequence); /// add a delay before the computer sequence
    }
}
void Model::endGame(){
    emit loseMessage(true); /// displays the lose message
    emit startOn(true);
    emit redBlueOn(false); /// resets the buttons back to how they are at the start
    emit changeSound(QUrl("qrc:/Sounds/loss_sound.mp3"));
    emit soundEffect();
    playerCombo.clear();
    colorCombo.clear(); /// resets the computer sequence and the player sequence
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
void Model::randomWinSound(){
    randomNum = (arc4random() % 4);
    if(randomNum == 0){
        emit changeSound(QUrl("qrc:/Sounds/alright.mp3"));
        emit soundEffect();
    }
    else if(randomNum == 1){
        emit changeSound(QUrl("qrc:/Sounds/got_it.mp3"));
        emit soundEffect();
    }
    else if(randomNum == 2){
        emit changeSound(QUrl("qrc:/Sounds/nailed_it.mp3"));
        emit soundEffect();
    }
    else{
        emit changeSound(QUrl("qrc:/Sounds/unbeliveable.mp3"));
        emit soundEffect();
    }
}

