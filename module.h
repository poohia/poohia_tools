#ifndef MODULE_H
#define MODULE_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QThread>
#include <QAction>


#include "qtservice.h"
#include "poohia_settings.h"


class ModuleClass : public QObject
{
    Q_OBJECT
public:
    explicit ModuleClass(QString name = NULL, QObject *parent = 0);
    ~ModuleClass();



    inline bool isInstall(){return this->_module->isInstalled();}
    inline bool isStart(){return this->_module->isRunning();}
    inline QString name(){return this->_module->serviceName();}
    bool setName(QString name);
    inline bool setPause(){return this->_module->pause();}
    inline bool setResume(){return this->_module->resume();}
    inline bool start(){/*
        QFuture<bool> future = QtConcurrent::run(
                    this, &Module::startModule
                    );
        return future.result();*/
        return this->_module->start();
    }
    inline bool stop(){/*
        QFuture<bool> future = QtConcurrent::run(
                    this, &Module::stopModule
                    );
        return future.result();*/
        return this->_module->stop();
    }
    inline QString getPathModule(){return this->_module->serviceFilePath();}

    inline bool setPathModule(QString path){ this->_pathModule = path ; this->_pathBin = QString(path).append("bin/"); return this->dirExist();}
    inline bool dirExist(){return QDir(this->_pathModule).exists() && QDir(this->_pathBin).exists();}





signals:

public slots:
    inline bool verifyIsStart(){return this->isStart();}

private:
    QProcess *_process;

    QString _pathModule;
    QString _name;
    QString _pathBin;


private:
    bool startModule();
    bool stopModule();
protected:
    QtServiceController* _module;


    void installService(QString exec, QStringList args);
    void uninstallService(QString exec, QStringList args);



};

class StartStopModuleController: public QThread
{
    Q_OBJECT


public:
    explicit StartStopModuleController();
    ~StartStopModuleController();
    inline void setQAction(QAction *action){this->_action = action;}


private:
    QAction *_action;
protected:
    void run();

signals:
    void emitMessage(QString);
};

class StartModuleController: public QThread
{
    Q_OBJECT


public:
    explicit StartModuleController();
    ~StartModuleController();
    inline void setQAction(QAction *action){this->_action = action;}


private:
    QAction *_action;
protected:
    void run();

signals:
    void emitMessage(QString);
};
class StopModuleController: public QThread
{
    Q_OBJECT


public:
    explicit StopModuleController();
    ~StopModuleController();
    inline void setQAction(QAction *action){this->_action = action;}


private:
    QAction *_action;
protected:
    void run();

signals:
    void emitMessage(QString);
};
class RestartModuleController: public QThread
{
    Q_OBJECT


public:
    explicit RestartModuleController();
    ~RestartModuleController();
    inline void setQAction(QAction *action){this->_action = action;}


private:
    QAction *_action;
protected:
    void run();

signals:
    void emitMessage(QString);
};
#endif // MODULE_H
