#ifndef DIRCLASS_H
#define DIRCLASS_H

#include <QObject>
#include <QDir>

class dirClass : public QObject
{
    Q_OBJECT
public:
    explicit dirClass(QObject *parent = 0);

signals:

public slots:

};

#endif // DIRCLASS_H
