#ifndef SOFTWARECLASS_H
#define SOFTWARECLASS_H

#include <QObject>

#include <QFileInfo>
#include <QDir>
#include <QIcon>
#include <QProcess>
#include <QDebug>

class softwareClass : public QFileInfo
{

public:
    explicit softwareClass();
    explicit softwareClass(QString path, QIcon *icon=NULL, QString name="");
    ~softwareClass();
    static inline bool isSoftware(QString path){return QFileInfo(path).isExecutable();}
    inline bool isSoftware() {return this->isExecutable();}
    inline void setIcon(QIcon *icon){if(!icon->isNull())delete this->_icon; this->_icon = icon;}
    inline QIcon* getIcon(){return this->_icon;}
    QString getName();
    inline void setFileName(QString name){this->_name = name;}
signals:

public slots:

private:
    QIcon *_icon;
    QString _name;
};

#endif // SOFTWARECLASS_H
