#include "apache.h"





Apache::Apache(QString name, QObject *parent)
{
    if(!name.isNull() || !name.isEmpty())
        this->setName(name);

}


Apache::~Apache()
{

}

void Apache::install()
{
    this->installService(execApache, this->_argsInstall);
}

void Apache::uninstall()
{
    this->uninstallService(execApache, this->_argsUninstall);
}

void Apache::init()
{

    /*this->setName(Poohia_settings::getNameServiceApache());
    this->setPathModule(Poohia_settings::getPathApache());
    this->_pathPhp = Poohia_settings::getPathPhp();*/

    //qDebug() << this->name() << this->getPathModule() << this->_pathPhp;
}

bool Apache::isApache()
{
    if(this->isInstall())
        if(this->getPathModule().split(".exe")[0].section("\\",-1) == "httpd")
            return true;

    return false;

}


