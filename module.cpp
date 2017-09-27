#include "module.h"

ModuleClass::ModuleClass(QString name, QObject *parent) :
    QObject(parent)
{
    this->_process = new QProcess;
    if(!name.isNull() || !name.isEmpty())
        this->setName(name);




}

ModuleClass::~ModuleClass()
{
    delete this->_process;
}

bool ModuleClass::setName(QString name)
{

    /*
    if(this->_module != NULL)
    {
        qDebug() << "module existe";
        if(this->name() != name)
            delete this->_module;
    }
*/

    this->_module = new QtServiceController(name);
    if(this->_module)
        return true;
    return false;

}

bool ModuleClass::startModule()
{
    return QtServiceController(this->name()).start();
}

bool ModuleClass::stopModule()
{
    return QtServiceController(this->name()).stop();
}

void ModuleClass::installService(QString exec, QStringList args)
{

    this->_process->start(this->_pathBin + exec,args);
    this->_process->waitForFinished();
}

void ModuleClass::uninstallService(QString exec, QStringList args)
{
    if(this->isStart())
        this->stop();
    this->_process->start(this->_pathBin + exec,args);
    this->_process->waitForFinished();
}





StartStopModuleController::StartStopModuleController():
    _action(NULL)
{

}

StartStopModuleController::~StartStopModuleController()
{

}

void StartStopModuleController::run()
{
    QString startstop = "" ;
    if(!ModuleClass(this->_action->objectName()).isStart())
    {
        startstop = "start ";
    }
    else
    {
        startstop = "stop ";
    }
    QProcess process;
    process.start("net "+ startstop +this->_action->objectName());
    process.waitForFinished();

    this->_action->setEnabled(true);

    if(ModuleClass(this->_action->objectName()).isStart())
        emit this->emitMessage(this->_action->objectName() + " is start"  );
    else
        emit this->emitMessage(this->_action->objectName() + " is stop"  );

    this->exec();
}


StartModuleController::StartModuleController():
    _action(NULL)
{

}

StartModuleController::~StartModuleController()
{

}

void StartModuleController::run()
{
    if(!ModuleClass(this->_action->objectName()).isStart()){


        QProcess process;
        process.start("net start " +this->_action->objectName());
        process.waitForFinished();

        this->_action->setEnabled(true);

        if(ModuleClass(this->_action->objectName()).isStart())
            emit this->emitMessage(this->_action->objectName() + " is start"  );
        else
            emit this->emitMessage("Can't start " + this->_action->objectName() + ". Verify you are admin acces ." );

        this->exec();
    }
}

StopModuleController::StopModuleController():
    _action(NULL)
{

}

StopModuleController::~StopModuleController()
{

}

void StopModuleController::run()
{
    if(ModuleClass(this->_action->objectName()).isStart()){


        QProcess process;
        process.start("net stop " +this->_action->objectName());
        process.waitForFinished();

        this->_action->setEnabled(true);

        if(!ModuleClass(this->_action->objectName()).isStart())
            emit this->emitMessage(this->_action->objectName() + " is stop"  );
        else
            emit this->emitMessage("Can't stop " + this->_action->objectName() + ". Verify you are admin acces ." );

        this->exec();
    }
}



RestartModuleController::RestartModuleController():
    _action(NULL)
{

}

RestartModuleController::~RestartModuleController()
{

}

void RestartModuleController::run()
{
    QProcess process;
    if(!ModuleClass(this->_action->objectName()).isStart()){
        process.start("net stop " + this->_action->objectName());
        process.waitForFinished();
    }

    process.start("net start " +this->_action->objectName());
    process.waitForFinished();

    this->_action->setEnabled(true);

    if(ModuleClass(this->_action->objectName()).isStart())
        emit this->emitMessage(this->_action->objectName() + " is start"  );
    else
        emit this->emitMessage("Can't start " + this->_action->objectName() + ". Verify you are admin acces ." );

    this->exec();

}
