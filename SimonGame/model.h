#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>
#include <QAudioOutput>
#include <QMediaPlayer>

///
/// \brief The Model class keeps track of the game logic, and signals to the view to make any necessary
/// chnages for the player to see. Also accepts handles button inputs from the view.
///
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

    /// when the computer is displaying its sequence, lights up the buttons and changes it back to grey
    void computerRed();
    void computerBlue();

    /// decides the sound for when a round is won
    void randomWinSound();

    // how many button presses the player needs to remember
    int lengthOfSequence;
    //how many times the button has been pressed during the demonstration of a sequence
    int currentInputs;
    //variable used to control how fast the game speeds up
    int speedup;
    //random number variable used for determining colors in the sequence, and which random audio to play
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
    /// tells view to change color of red button
    void changeColorRed(QString);
    /// tells view to disable or enable both the red and blue button
    void redBlueOn(bool);
    /// tells view to diasble or enable the start button
    void startOn(bool);
    /// tell view to update the progress bar
    void updateProgressValue(int);
    void updateProgressMinimum(int);
    void updateProgressMaximum(int);
    /// tells view to display or hide lose label
    void loseMessage(bool);
    /// signals for a sound effect to be played
    void soundEffect();
    /// changes the sound that is going to be played
    void changeSound(QUrl);
};

#endif // MODEL_H
