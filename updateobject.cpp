#include "updateobject.h"

updateObject::updateObject(QObject *parent) : QThread(parent)
{

}



void updateObject::run()
{
    QProcess process;
    process.setWorkingDirectory(QApplication::applicationDirPath());

    process.start("Poohia_update.exe", QStringList() << "-v");


    this->exec();
}

