#ifndef TRAYICONOBJECT_H
#define TRAYICONOBJECT_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QEvent>

class TrayIconObject : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit TrayIconObject(QSystemTrayIcon *parent = 0);

protected:
    bool event(QEvent * e);

signals:

public slots:

};

#endif // TRAYICONOBJECT_H
