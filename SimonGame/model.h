#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>
#include <QAudioOutput>
#include <QMediaPlayer>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
private:
    /// blue is true, red is false
    std::vector<bool> colorCombo;
    std::vector<bool> playerCombo;
    /// helper method for when a game is started
    void startGame();
    /// helper method for the flashing buttons
    void emitColor(char);
    /// helper method for when the game ends
    void endGame();
    /// helper method that sets up the game and displays each sequence
    void displaySequence();
    /// when the computer emits the sequence, lights up the buttons and adds a delay
    void computerRed();
    void computerBlue();
    /// decides the sound for when a round is won
    void randomWinSound();
    int lengthOfSequence;
    int currentInputs;
    int speedup;
    int randomNum;
public slots:
    /// handler for the blueButton event. Changes the color of the button to blue, as well as, checks if that was correct move.
    void bluePressed();
    /// after a button is turned blue, changes the color back to grey after a set time
    void blueGrey();
    /// handler for the redButton event. Changes the color of the button to red, as well as, checks if that was correct move.
    void redPressed();
    /// after a button is turned red, changes the color back to grey after a set time
    void redGrey();
    /// when pressed starts the game by providing the player with a computer sequence of inputs.
    void startPressed();

signals:
    /// tells view to change color of blue button
    void changeColorBlue(QString);
    /// tells view to color of red button
    void changeColorRed(QString);
    /// tells view to disable or enable both the red and blue button
    void redBlueOn(bool);
    /// tells view to diasble or enable the start button
    void startOn(bool);
    /// updaters for the progress bar
    void updateProgressValue(int);
    void updateProgressMinimum(int);
    void updateProgressMaximum(int);
    /// enables and disables the lose label
    void loseMessage(bool);
    /// plays sound effects
    void soundEffect();
    /// changes the media source
    void changeSound(QUrl);
};

#endif // MODEL_H
