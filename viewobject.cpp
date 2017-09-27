#include "viewobject.h"
#include "ui_viewobject.h"

ViewObject::ViewObject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewObject),
    _iconPlay(":/icons/stop.png"),
    _iconStop(":/icons/play.png"),
    _trayIcon(new QSystemTrayIcon(this))
{
    ui->setupUi(this);

    this->setWindowTitle(nameSoftware);
    this->_trayIcon->setToolTip(nameSoftware);
    this->_trayIcon->setIcon(QIcon(":/icons/icon.png"));


    connect(this->_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    this->showTrayIcon();
}

ViewObject::~ViewObject()
{
    delete ui;
    delete this->_trayIcon;
}

void ViewObject::verifyUpdate()
{
    this->_update = new updateObject;
    connect(this->_update, SIGNAL(finished()), this->_update, SLOT(deleteLater()));
    this->_update->start();
}

void ViewObject::showTrayIcon()
{
    /************************   INI  ********************************/

    this->_trayIconMenu = new QMenu(this);
    this->_moduleMenu = new QMenu(actionNameService, this);
    this->_moduleMenu->setIcon(QIcon(":/icons/service.png"));
    this->_softwareMenu = new QMenu(actionNameSoftware, this);
    this->_softwareMenu->setIcon(QIcon(":/icons/defaultsoftware.png"));
    this->_shortDirMenu = new QMenu(actionNameFolder, this);
    this->_shortDirMenu->setIcon(QIcon(":/icons/dossier.png"));
    this->_shortWebMenu = new QMenu(actionNameHttp, this);
    this->_shortWebMenu->setIcon(QIcon(":/icons/internet.png"));

    this->_configAction =  new QAction("Configuration", this);
    this->_configAction->setIcon(QIcon(":/icons/configuration.png"));
    connect(this->_configAction, SIGNAL(triggered()), this, SLOT(refreshView()));

    this->_quitAction = new QAction(actionNameExit, this);
    this->_quitAction->setIcon(QIcon(":/icons/exit.png"));
    connect(this->_quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    this->_aboutAction = new QAction("About",this);
    this->_aboutAction->setIcon(QIcon(":/icons/info.png"));
    connect(this->_aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    /*****************************************************************/



    /********************** SERVICES ****************************/
    foreach(QString module, Poohia_settings::getModules())
        this->addQAction(module,MODULE);
    foreach(QString software, Poohia_settings::getSoftwares())
        this->addQAction(software, SOFTWARE);
    foreach(QString web, Poohia_settings::getWeb())
        this->addQAction(web, WEB);
    foreach (QString dir, Poohia_settings::getDir())
        this->addQAction(dir, DIR);


    this->_trayIconMenu->addAction(this->_aboutAction);
    this->_trayIconMenu->addAction(this->_configAction);
    this->_trayIconMenu->addSeparator();
    this->_trayIconMenu->addMenu(this->_shortWebMenu);
    this->_trayIconMenu->addMenu(this->_shortDirMenu);
    this->_trayIconMenu->addSeparator();
    this->_trayIconMenu->addMenu(this->_softwareMenu);
    this->_trayIconMenu->addMenu(this->_moduleMenu);
    this->_trayIconMenu->addSeparator();
    this->_trayIconMenu->addAction(this->_quitAction);

    this->_trayIcon->setContextMenu(this->_trayIconMenu);

    if(!this->_trayIcon->isVisible())
        this->_trayIcon->show();

}

void ViewObject::addQAction(QString action, typeAction type)
{
    QAction *newAction = new QAction(this);
    switch(type)
    {
    case MODULE:
        if(ModuleClass(action).isInstall())
        {
            newAction->setObjectName(action);

            (ModuleClass(action).isStart())?
                        newAction->setText("stop " + action): newAction->setText("start "+action);
            this->setStatus(newAction, ModuleClass(action).isStart());
            this->_moduleMenu->addAction(newAction);
            connect(newAction, SIGNAL(triggered()), this, SLOT(clickToModuleAction()));
            connect(this, SIGNAL(destroyed()), newAction, SLOT(deleteLater()));
        }else delete newAction;
        break;
    case SOFTWARE:
        if(QFileInfo(Poohia_settings::getPathSoftware(action)).isExecutable())
        {

            newAction->setObjectName(action);
            newAction->setText(action);

            (QIcon(Poohia_settings::getIconSoftware(action)).availableSizes().isEmpty())?
                        newAction->setIcon(QIcon(":/icons/defaultsoftware.png")):
                        newAction->setIcon(QIcon(Poohia_settings::getIconSoftware(action)));


            this->_softwareMenu->addAction(newAction);
            connect(newAction, SIGNAL(triggered()), this, SLOT(clickToSoftwareAction()));
            connect(this, SIGNAL(destroyed()), newAction, SLOT(deleteLater()));

        }else delete newAction;
        break;
    case WEB:
        newAction->setObjectName(action);
        newAction->setText(action);
        newAction->setIcon(QIcon(":/icons/internet.png"));
        this->_shortWebMenu->addAction(newAction);
        connect(newAction, SIGNAL(triggered()), this, SLOT(clickToWebAction()));
        connect(this, SIGNAL(destroyed()), newAction, SLOT(deleteLater()));
        break;
    case DIR:
        if(QFileInfo(Poohia_settings::getPathDir(action)).isDir())
        {
            newAction->setObjectName(action);
            newAction->setText(action);
            newAction->setIcon(QIcon(":/icons/dossier.png"));
            this->_shortDirMenu->addAction(newAction);
            connect(newAction, SIGNAL(triggered()), this, SLOT(clickToDirAction()));
            connect(this, SIGNAL(destroyed()), newAction, SLOT(deleteLater()));
        }else delete newAction;

        break;
    }
}

void ViewObject::clickToModuleAction()
{
    QObject *emetteur = sender();
    QAction * emetteurCasted = qobject_cast<QAction*>(emetteur);
    emetteurCasted->setEnabled(false);

    if(ModuleClass(emetteurCasted->objectName()).isStart())
    {
        StopModuleController *stopModule = new StopModuleController();
        stopModule->setQAction(emetteurCasted);
        connect(stopModule, SIGNAL(finished()), stopModule, SLOT(deleteLater()));
        connect(stopModule, SIGNAL(emitMessage(QString)), this, SLOT(showMessage(QString)));
        stopModule->start();
    }
    else
    {
        StartModuleController *startModule = new StartModuleController();
        startModule->setQAction(emetteurCasted);
        connect(startModule, SIGNAL(finished()), startModule, SLOT(deleteLater()));
        connect(startModule, SIGNAL(emitMessage(QString)), this, SLOT(showMessage(QString)));
        startModule->start();
    }
}

void ViewObject::clickToSoftwareAction()
{

    QObject *emetteur = sender();
    QAction * emetteurCasted = qobject_cast<QAction*>(emetteur);

    if(QFileInfo(Poohia_settings::getPathSoftware(emetteurCasted->objectName())).isExecutable())
    {

        if(!QDesktopServices::openUrl(QUrl("file:///"+Poohia_settings::getPathSoftware(emetteurCasted->objectName()))))
            QMessageBox::warning(this,nameSoftware,"Can't open : " + Poohia_settings::getPathSoftware(emetteurCasted->objectName()));
    }
}

void ViewObject::clickToDirAction()
{
    QObject *emetteur = sender();
    QAction * emetteurCasted = qobject_cast<QAction*>(emetteur);
    if(QFileInfo(Poohia_settings::getPathDir(emetteurCasted->objectName())).isDir())
        if(!QDesktopServices::openUrl(QUrl("file:///"+Poohia_settings::getPathDir(emetteurCasted->objectName()),  QUrl::TolerantMode)))
            QMessageBox::warning(this,nameSoftware,"Can't open : " + Poohia_settings::getPathDir(emetteurCasted->objectName()) );
}

void ViewObject::clickToWebAction()
{
    QObject *emetteur = sender();
    QAction * emetteurCasted = qobject_cast<QAction*>(emetteur);
    if(!QDesktopServices::openUrl(QUrl(Poohia_settings::getPathWeb(emetteurCasted->objectName()))))
        QMessageBox::warning(this,nameSoftware,"Can't open : " + Poohia_settings::getPathWeb(emetteurCasted->objectName()));
}
void ViewObject::showMessage(QString msg)
{
    this->_trayIcon->showMessage(nameSoftware,msg);
}

void ViewObject::refreshModules()
{
    foreach(QAction* action, this->_moduleMenu->actions())
    {
        QString name = action->objectName();
        if(ModuleClass(name).isInstall())
        {
            this->setStatus(action, ModuleClass(name).isStart());
        }
        else this->_moduleMenu->removeAction(action);
    }
}

void ViewObject::addService(QString name)
{
    if(ModuleClass(name).isInstall())
    {
        this->addQAction(name,MODULE);
        Poohia_settings::setModule(name);
    }
    else
        QMessageBox::warning(this, nameSoftware,name + errorNotService);
}

void ViewObject::removeService(QString name)
{
    foreach(QAction *action, this->_moduleMenu->actions())
        if(action->objectName() == name)
        {
            this->_moduleMenu->removeAction(action);
            Poohia_settings::removeModule(name);
        }
    this->refreshView();
}

void ViewObject::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::DoubleClick:
        //qDebug() << "double click";
        if(this->isHidden()) this->show();
        break;
    case QSystemTrayIcon::Trigger:
        //qDebug() << "click";

        break;
    case QSystemTrayIcon::Context:
        //qDebug() << "Context";
        this->refreshModules();
        break;
    }
}

void ViewObject::setStatus(QAction *action, bool isStart)
{
    if(isStart)
    {
        action->setToolTip(isStartModuleTooltip);
        action->setText(action->text().replace("start","stop"));
        action->setIcon(_iconPlay);
    }
    else
    {
        action->setToolTip(isStopModuleTooltip);
        action->setText(action->text().replace("stop","start"));
        action->setIcon(_iconStop);
    }
}

void ViewObject::refreshView()
{
    this->ui->comboBoxAllService->clear();
    this->ui->comboBoxAllService->addItem(" ");

    this->ui->comboBoxAllSoftware->clear();
    this->ui->comboBoxAllSoftware->addItem(" ");

    this->ui->comboBoxAllDirs->clear();
    this->ui->comboBoxAllDirs->addItem(" ");

    this->ui->comboBoxAllUrls->clear();
    this->ui->comboBoxAllUrls->addItem(" ");

    foreach(QAction* action, this->_moduleMenu->actions())
        this->ui->comboBoxAllService->addItem(action->objectName());

    foreach(QAction* action, this->_softwareMenu->actions())
        this->ui->comboBoxAllSoftware->addItem(action->objectName());

    foreach(QAction *action, this->_shortDirMenu->actions())
        this->ui->comboBoxAllDirs->addItem(action->objectName());

    foreach(QAction *action, this->_shortWebMenu->actions())
        this->ui->comboBoxAllUrls->addItem(action->objectName());

    if(this->isHidden())
        this->show();
}

void ViewObject::about()
{
    QDesktopServices::openUrl(QUrl(pathToPoohiaWeb));
}

void ViewObject::closeEvent(QCloseEvent *event)
{
    this->_trayIcon->show();
    this->hide();
    event->ignore();
}

void ViewObject::on_pushButtonAddService_clicked()
{
    this->addService(this->ui->lineEditNameService->text());
    this->ui->lineEditNameService->clear();
    this->ui->statusBar->showMessage(addInformations);
    this->refreshView();
}

void ViewObject::on_pushButtonRemoveService_clicked()
{
    this->removeService(ui->comboBoxAllService->currentText());
    this->ui->statusBar->showMessage(removeInformations);
}

void ViewObject::on_comboBoxAllSoftware_currentIndexChanged(const QString &arg1)
{


    if(arg1 == " ")
    {
        this->ui->lineEditNameSoftware->setReadOnly(false);
        this->ui->pushButtonRemoveSoftware->setEnabled(false);
        this->ui->pushButtonAddSoftware->setText(pushButtonAdd);
        this->ui->lineEditNameSoftware->clear();
        this->ui->lineEditPathSoftware->clear();
        this->ui->lineEditPathIcon->clear();
    }
    else
    {
        this->ui->lineEditNameSoftware->setReadOnly(true);
        this->ui->pushButtonRemoveSoftware->setEnabled(true);
        this->ui->pushButtonAddSoftware->setText(pushButtonSave);


        this->ui->lineEditNameSoftware->setText(arg1);
        this->ui->lineEditPathSoftware->setText(Poohia_settings::getPathSoftware(arg1));
        this->ui->lineEditPathIcon->setText(Poohia_settings::getIconSoftware(arg1));
        //     this->ui->labelSoftwareIcon->setPixmap(QPixmap(this->ui->lineEditPathIcon->text()));
    }
}

void ViewObject::on_pushButton_clicked()
{
    QString tmp = QFileDialog::getOpenFileName(0, tr("Open File"), "/",
                                               tr("Executable (*.exe)"));
    if(!tmp.isEmpty())
        this->ui->lineEditPathSoftware->setText(tmp);
}

void ViewObject::on_pushButton_2_clicked()
{
    QString tmp = QFileDialog::getOpenFileName(0, tr("Open File"), "/",
                                               tr("Image (*.png *.jpg *.ico *.bmp)"));
    if(!tmp.isEmpty())
        this->ui->lineEditPathIcon->setText(tmp);
}

void ViewObject::on_pushButtonAddSoftware_clicked()
{
    QAction *tmpSoftware;
    if(QFileInfo(ui->lineEditPathSoftware->text()).isExecutable())
    {
        Poohia_settings::setSoftware(ui->lineEditNameSoftware->text(), ui->lineEditPathSoftware->text(), ui->lineEditPathIcon->text());

        bool actionExiste = false;
        foreach (QAction *action, this->_softwareMenu->actions())
            if(action->objectName() == ui->lineEditNameSoftware->text())
                actionExiste = true;
        if(!actionExiste)
        {
           tmpSoftware  = new QAction(this);
            tmpSoftware->setObjectName(ui->lineEditNameSoftware->text());
            tmpSoftware->setText(ui->lineEditNameSoftware->text());

            (QIcon(this->ui->lineEditPathIcon->text()).availableSizes().isEmpty())?
                        tmpSoftware->setIcon(QIcon(":/icons/defaultsoftware.png")):
                        tmpSoftware->setIcon(QIcon(ui->lineEditPathIcon->text()));
            this->_softwareMenu->addAction(tmpSoftware);

            connect(tmpSoftware, SIGNAL(triggered()), this, SLOT(clickToSoftwareAction()));
            connect(this, SIGNAL(destroyed()), tmpSoftware, SLOT(deleteLater()));
        }


        ui->statusBar->showMessage(ui->pushButtonAddSoftware->text() + " ok");
    }
    else
        ui->statusBar->showMessage(ui->lineEditPathIcon->text() + " is not a software");
    this->refreshView();
}

void ViewObject::on_pushButtonRemoveSoftware_clicked()
{
    Poohia_settings::removeSoftware(ui->lineEditNameSoftware->text());

    foreach (QAction *action, this->_softwareMenu->actions())
        if(action->objectName() == ui->lineEditNameSoftware->text())
            this->_softwareMenu->removeAction(action);
    ui->statusBar->showMessage(removeInformations);
    this->refreshView();
}

void ViewObject::on_comboBoxAllDirs_currentIndexChanged(const QString &arg1)
{
    if(arg1 == " ")
    {
        ui->pushButtonRemoveDir->setEnabled(false);
        ui->lineEditNameDirs->setReadOnly(false);
        ui->lineEditNameDirs->clear();
        ui->lineEditPathDir->clear();
        ui->pushButtonAddDir->setText(pushButtonAdd);
    }
    else
    {
        ui->pushButtonRemoveDir->setEnabled(true);
        ui->lineEditNameDirs->setReadOnly(true);
        ui->lineEditNameDirs->setText(arg1);
        ui->lineEditPathDir->setText(Poohia_settings::getPathDir(arg1));
        ui->pushButtonAddDir->setText(pushButtonSave);
    }
}

void ViewObject::on_pushButton_5_clicked()
{
    QString tmp = QFileDialog::getExistingDirectory(this, tr("Open dir"), "/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!tmp.isEmpty())
        this->ui->lineEditPathDir->setText(
                tmp
                );
}

void ViewObject::on_pushButtonRemoveDir_clicked()
{
    Poohia_settings::removeDir(ui->lineEditNameDirs->text());
    foreach(QAction *action, this->_shortDirMenu->actions())
        if(action->objectName() == ui->lineEditNameDirs->text())
            this->_shortDirMenu->removeAction(action);

    this->ui->statusBar->showMessage(removeInformations);
    this->refreshView();
}

void ViewObject::on_pushButtonAddDir_clicked()
{
    QAction *tmpDir;
    if(QFileInfo(ui->lineEditPathDir->text()).isDir())
    {
        Poohia_settings::setDir(ui->lineEditNameDirs->text(), ui->lineEditPathDir->text());
        bool actionExiste = false;
        foreach (QAction *action, this->_shortDirMenu->actions())
            if(action->objectName() == this->ui->lineEditNameDirs->text())
                actionExiste = true;
        if(!actionExiste)
        {
            tmpDir = new QAction(this);
            tmpDir->setObjectName(this->ui->lineEditNameDirs->text());
            tmpDir->setText(this->ui->lineEditNameDirs->text());
            tmpDir->setIcon(QIcon(":/icons/dossier.png"));
            this->_shortDirMenu->addAction(tmpDir);
            connect(tmpDir, SIGNAL(triggered()), this, SLOT(clickToDirAction()));
            connect(this, SIGNAL(destroyed()), tmpDir, SLOT(deleteLater()));


        }
        this->ui->statusBar->showMessage(ui->pushButtonAddDir->text() + " ok");
    }
    else
        ui->statusBar->showMessage(ui->lineEditPathDir->text() + " is not folder");

    this->refreshView();
}

void ViewObject::on_comboBoxAllUrls_currentIndexChanged(const QString &arg1)
{
    if(arg1 == " ")
    {
        ui->pushButtonRemoveUrl->setEnabled(false);
        ui->lineEditNameUrl->clear();
        ui->lineEditNameUrl->setReadOnly(false);
        ui->lineEditUrls->clear();
        ui->pushButtonAddUrls->setText(pushButtonAdd);
    }
    else
    {
        ui->pushButtonRemoveUrl->setEnabled(true);
        ui->lineEditNameUrl->setText(arg1);
        ui->lineEditNameUrl->setReadOnly(true);
        ui->lineEditUrls->setText(Poohia_settings::getPathWeb(arg1));
        ui->pushButtonAddUrls->setText(pushButtonSave);
    }
}

void ViewObject::on_pushButtonAddUrls_clicked()
{
    QAction *tmpWeb;
    Poohia_settings::setWeb(ui->lineEditNameUrl->text(), ui->lineEditUrls->text());
    ui->statusBar->showMessage(ui->pushButtonAddUrls->text() + " ok");
    bool actionExist = false;
    foreach(QAction *action, this->_shortWebMenu->actions())
        if(action->objectName() == ui->lineEditNameUrl->text())
            actionExist = true;
    if(!actionExist)
    {
        tmpWeb = new QAction(this);
        tmpWeb->setObjectName(ui->lineEditNameUrl->text());
        tmpWeb->setText(ui->lineEditNameUrl->text());
        tmpWeb->setIcon(QIcon(":/icons/internet.png"));
        this->_shortWebMenu->addAction(tmpWeb);
        connect(tmpWeb, SIGNAL(triggered()), this, SLOT(clickToWebAction()));
        connect(this, SIGNAL(destroyed()), tmpWeb, SLOT(deleteLater()));
    }
    this->refreshView();
}

void ViewObject::on_pushButtonRemoveUrl_clicked()
{
    Poohia_settings::removeWeb(ui->lineEditNameUrl->text());
    foreach(QAction *action, this->_shortWebMenu->actions())
        if(action->objectName() == ui->lineEditNameUrl->text())
            this->_shortWebMenu->removeAction(action);
    ui->statusBar->showMessage(removeInformations);
    this->refreshView();
}



void ViewObject::on_tabWidget_currentChanged(int index)
{
    this->ui->statusBar->clearMessage();
}
