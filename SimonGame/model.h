#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void bluePressed();
    //void redPressed();

signals:
    void flashBlue(QString);
    //void flashRed();
};

#endif // MODEL_H
