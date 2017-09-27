#ifndef APACHE_H
#define APACHE_H

#include <QObject>
#include <QApplication>
#include <QDebug>


#include "module.h"

#define execApache "httpd.exe"
/*#define nameServiceApache Poohia_settings::getNameServiceApache()

#define pathModuleApache Poohia_settings::getPathApache()
#define pathPhp Poohia_settings::getPathPhp()
*/



class Apache : public Module
{
    Q_OBJECT
public:
    explicit Apache(QString name= NULL, QObject *parent = 0);
    ~Apache();


    void install();
    void uninstall();
    void init();

    inline void setPathPhp(QString path){this->_pathPhp = path;}
    inline QString getPathPhp(){return this->_pathPhp;}

    bool isApache();


signals:

public slots:

private:
     QStringList _argsInstall ;
     QStringList _argsUninstall;

     QString _pathPhp;



};

#endif // APACHE_H
