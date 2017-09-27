#include "trayiconobject.h"

TrayIconObject::TrayIconObject(QSystemTrayIcon *parent) : QSystemTrayIcon(parent)
{

}

bool TrayIconObject::event(QEvent *e)
{
    qDebug() << "blabla";
    return true;

}

