#ifndef POSTGRE_H
#define POSTGRE_H

#include <QObject>
#include <QApplication>
#include <QDebug>


#include "module.h"

#define execPostGre "pg_ctl.exe"
/*#define nameServicePostGre Poohia_settings::getNameServicePostgre()

#define pathModulePostGre Poohia_settings::getPathPostgre()*/

class Postgre : public Module
{
    Q_OBJECT


public:
    explicit Postgre(QString name=NULL, QObject *parent = 0);

    void install();
    void uninstall();

    inline QString getDataPath(){return this->_dataPath;}
    inline void setDataPath(QString path){this->_dataPath = path;}

    void init();

    bool isPostGre();



signals:

public slots:

private:
    QStringList _argsInstall ;
    QStringList _argsUninstall;


    QString _dataPath;



};

#endif // POSTGRE_H
