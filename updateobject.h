#ifndef UPDATEOBJECT_H
#define UPDATEOBJECT_H

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

class updateObject : public QThread
{
    Q_OBJECT
public:
    explicit updateObject(QObject *parent = 0);


protected:
    void run();

};

#endif // UPDATEOBJECT_H
