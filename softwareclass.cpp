#include "softwareclass.h"

softwareClass::softwareClass():
    _name(""),
    _icon(new QIcon(":/icons/software.png"))
{
}

softwareClass::softwareClass(QString path, QIcon *icon, QString name)
{
    this->setFile(path);
    this->setIcon(icon);
    this->setFileName(name);



}

softwareClass::~softwareClass()
{
    delete this->_icon;
}

QString softwareClass::getName()
{
    if(this->_name.isEmpty() || this->_name.isNull())
        return this->baseName();
    else
        return this->_name;
}


