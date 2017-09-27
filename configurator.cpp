#include "configurator.h"
#include "ui_configurator.h"

Configurator::Configurator(Apache *apache,Postgre *postgre, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Configurator),
    _apache(apache),
    _postgre(postgre)
{
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);


    connect(this->ui->pushButtonUninstall,SIGNAL(clicked()),this,SLOT(uninstallApache()));
    connect(this->ui->pushButtonUninstallPostgre,SIGNAL(clicked()),this,SLOT(uninstallPostgre()));


    connect(this->ui->actionInstall, SIGNAL(triggered()), this,SLOT(startInstall()));

}

Configurator::~Configurator()
{
    delete ui;
}

void Configurator::initInfo()
{
    /******* APACHE *************/
    if(!this->_apache->dirExist())
    {
        this->ui->tabApache->setEnabled(false);
        this->ui->statusbar->showMessage("Apache is not install, goto www.poohia.com");
    }

    if(this->_apache->isInstall())
        this->ui->pushButtonUninstall->setEnabled(true);
    else
        this->ui->pushButtonUninstall->setEnabled(false);

    this->ui->lineEditPathApache->setText(this->_apache->getPathModule());
    this->ui->lineEditPathPhp->setText(this->_apache->getPathPhp());
    this->ui->lineEditServiceName->setText(this->_apache->name());

    /******* POSTGRE ***********/
    if(!this->_postgre->dirExist())
    {
        this->ui->tabPostgre->setEnabled(false);
        this->ui->statusbar->showMessage("PostGre is not install, goto www.poohia.com");
    }

    if(this->_postgre->isInstall())
        this->ui->pushButtonUninstallPostgre->setEnabled(true);
    else
        this->ui->pushButtonUninstallPostgre->setEnabled(false);

    this->ui->lineEditPathPostgre->setText(Poohia_settings::getPathPostgre());
    this->ui->lineEditPathDataPostgre->setText(Poohia_settings::getPathDataPostgre());
    this->ui->lineEditServicNamePostgre->setText(Poohia_settings::getNameServicePostgre());
}

void Configurator::init()
{
    this->initInfo();
    this->show();
}

void Configurator::startInstall()
{
    this->ui->tabWidget->setCurrentIndex(2);

    /********* APACHE *********************************/
    this->_apache->setPathModule(this->ui->lineEditPathApache->text());
    this->_apache->setName(this->ui->lineEditServiceName->text());
    this->_apache->setPathPhp(ui->lineEditPathPhp->text());
    this->ui->textEditInstall->setText("---- Apache ----");
    this->ui->textEditInstall->append(QString("Php ::: ").append( this->_apache->getPathPhp()));
    this->ui->textEditInstall->append("      --- Add to Path Windows");
    this->ui->textEditInstall->append("Apache ......");
    this->ui->textEditInstall->append(QString("       ---- Path to apache").append(this->_apache->getPathModule()));
    this->ui->textEditInstall->append(QString("       ---- Name Service :").append(this->_apache->getPathPhp()));
    if(this->_apache->isInstall())
        this->ui->textEditInstall->append("This service is always install");
    else
    {
        this->ui->textEditInstall->append("Start install service Apache .......");
        this->_apache->install();
        if(this->_apache->isInstall())
        {
            Poohia_settings::setNameServiceApache(this->ui->lineEditServiceName->text());
            this->ui->textEditInstall->append("Install service ok");
        }
        else
            this->ui->textEditInstall->append("Error to install service");
    }

    /************ POSTGRE *************************************/
    this->ui->textEditInstall->append("---- PostgreSql ----");
    this->ui->textEditInstall->append("Path to data ::: ");
    this->ui->textEditInstall->append(this->_postgre->getDataPath());
    this->ui->textEditInstall->append("PostgreSql ......");
    this->ui->textEditInstall->append(QString("       ---- Path to Postgresql").append(this->ui->lineEditPathPostgre->text()));
    this->ui->textEditInstall->append(QString("       ---- Name Service :").append(this->ui->lineEditServicNamePostgre->text()));
    if(this->_postgre->isInstall())
        this->ui->textEditInstall->append("This service is always install");
    else
    {
        this->ui->textEditInstall->append("Start install service PostgreSql .......");
        this->_postgre->install();
        if(this->_postgre->isInstall())
        {
            Poohia_settings::setNameServicePostgre(this->ui->lineEditServicNamePostgre->text());
            this->ui->textEditInstall->append("Install service ok");
        }
        else
            this->ui->textEditInstall->append("Error to install service");
    }

    /***********************************************************/

    this->_apache->init();
    this->_postgre->init();
    this->initInfo();
}

void Configurator::uninstallApache()
{
    this->_apache->uninstall();
    if(!this->_apache->isInstall())
        ui->statusbar->showMessage("Uninstall ok");
    else
        ui->statusbar->showMessage("Uninstall faill");
}

void Configurator::uninstallPostgre()
{
    this->_postgre->uninstall();
    if(!this->_postgre->isInstall())
        ui->statusbar->showMessage("Uninstall ok");
    else
        ui->statusbar->showMessage("Uninstall faill");
}

void Configurator::on_pushButtonPathPhp_clicked()
{
    // this->ui->lineEditPathPhp->setText(QDir::);
}

void Configurator::closeEvent(QCloseEvent *event)
{
    emit this->installFinish();
}

