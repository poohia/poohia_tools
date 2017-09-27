#ifndef VIEWOBJECT_H
#define VIEWOBJECT_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include <QMenu>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QCloseEvent>
#include <QFileDialog>
#include <QAction>



#include "module.h"
#include "updateobject.h"


const QString isStartModuleTooltip = "Is start ";
const QString isStopModuleTooltip =  "Is stop";

const QString nameSoftware = "Poohia tools";
const QString pathToPoohiaWeb = "http://www.poohia.com";

const QString errorModule = " is not a Apache or PostgreSql service.\n May be verify it's installed.";
const QString errorPathPgAdmin = "Path to pgAdmin.exe is not configurate.";
const QString errorPathWWWfolder = "Path to www folder is not configurate.";
const QString errorNotService = " is not a service windows";

const QString saveInformations = "Informations save!";
const QString addInformations = "Add ok";
const QString removeInformations = "Remove ok!";
const QString pushButtonAdd = "Add";
const QString pushButtonSave = "Save";

const QString actionNameService = "Services";
const QString actionNameSoftware = "Softwares";
const QString actionNameExit = "Exit";
const QString actionNameHttp = "Web shortcut";
const QString actionNameFolder = "Folder shortcut";
const QString actionNameAbout = "About";


enum typeAction{
    MODULE,
    SOFTWARE,
    WEB,
    DIR
};



namespace Ui {
class ViewObject;
}


class ViewObject : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewObject(QWidget *parent = 0);
    ~ViewObject();
    void verifyUpdate();

private:
    Ui::ViewObject *ui;


private:

    QSystemTrayIcon *_trayIcon;

    QMenu *_trayIconMenu;
    QMenu *_softwareMenu;
    QMenu *_moduleMenu;
    QMenu *_shortWebMenu;
    QMenu *_shortDirMenu;


    QAction   *_configAction;
    QAction   *_aboutAction;
    QAction   *_quitAction;


    const QIcon _iconPlay;
    const QIcon _iconStop;

    updateObject *_update;


signals:

public slots:
    void showTrayIcon();

private slots:
    void addQAction(QString action, typeAction type);
    void clickToModuleAction();
    void clickToSoftwareAction();
    void clickToDirAction();
    void clickToWebAction();
    void showMessage(QString msg);

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void refreshView();

    void about();
  /*  void removeQActionModule(QString name);
    void clickToQaction();
    /*
    void clickToTrayIcon();

    void refreshView();




*/
    void on_pushButtonAddService_clicked();

    void on_pushButtonRemoveService_clicked();

    void on_comboBoxAllSoftware_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonAddSoftware_clicked();

    void on_pushButtonRemoveSoftware_clicked();

    void on_comboBoxAllDirs_currentIndexChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButtonRemoveDir_clicked();

    void on_pushButtonAddDir_clicked();

    void on_comboBoxAllUrls_currentIndexChanged(const QString &arg1);

    void on_pushButtonAddUrls_clicked();

    void on_pushButtonRemoveUrl_clicked();


    void on_tabWidget_currentChanged(int index);

private:
    void setStatus(QAction *action, bool isStart);
     void refreshModules();

     void addService(QString name);
     void removeService(QString name);
protected:
    void	closeEvent(QCloseEvent * event);
};

#endif // VIEWOBJECT_H
