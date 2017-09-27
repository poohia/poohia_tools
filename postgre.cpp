#include "postgre.h"

Postgre::Postgre(QString name, QObject *parent)
{
    if(!name.isNull() || !name.isEmpty())
        this->setName(name);
}

void Postgre::install()
{
    this->installService(execPostGre, this->_argsInstall);
}

void Postgre::uninstall()
{
    this->uninstallService(execPostGre, this->_argsUninstall);

}

void Postgre::init()
{
    /*this->setName(Poohia_settings::getNameServicePostgre());
    this->setPathModule(Poohia_settings::getPathPostgre());
    this->_dataPath = Poohia_settings::getPathDataPostgre();*/

}

bool Postgre::isPostGre()
{
    if(this->isInstall())
        if(this->getPathModule().split(".exe")[0].section("\\",-1) == "pg_ctl")
            return true;

    return false;
}
