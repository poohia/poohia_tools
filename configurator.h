#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QProcess>

#include "apache.h"
#include "postgre.h"


namespace Ui {
class Configurator;
}

class Configurator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Configurator(Apache *apache,Postgre *postgre, QWidget *parent = 0);

    ~Configurator();

private:
    Ui::Configurator *ui;

    Apache *_apache;
    Postgre *_postgre;


    void initInfo();

public slots:
    void init();

private slots:
    void startInstall();
    void uninstallApache();
    void uninstallPostgre();
    void on_pushButtonPathPhp_clicked();

signals:
    void installFinish();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CONFIGURATOR_H
