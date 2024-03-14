#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
private:
    /// blue is true, red is false
    std::vector<bool> colorCombo;
    std::vector<bool> playerCombo;
    void startGame();
    void emitColor(char);
    void endGame();
    void displaySequence();
    void computerRed();
    void computerBlue();
    int lengthOfSequence;
    int currentInputs;
    int speedup;
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
    void updateProgressValue(int);
    void updateProgressMinimum(int);
    void updateProgressMaximum(int);
    void loseMessage(bool);
};

#endif // MODEL_H
