#include "viewobject.h"
#include <QApplication>
#include <QStyleFactory>
#include <QtSingleApplication>



#include "poohia_settings.h"

int main(int argc, char *argv[])
{
    QtSingleApplication app("Poohia_tools",argc, argv);
    if(app.sendMessage("Wake up!"))
    {
        QMessageBox::critical( 0, "Poohia_tools.exe", "Poohia_tools.exe is already running!" );
        return 0;
    }
    else
    {
        //a.setStyle("Fusion");
        qApp->setStyle(QStyleFactory::create("Fusion"));

        qApp->setStyle(QStyleFactory::create("Fusion"));
        QPalette p = qApp->palette();
       // p.setColor(QPalette::Window, QColor(53,53,53));
       //p.setColor(QPalette::Button, QColor(255,102,0));
       p.setColor(QPalette::Highlight, QColor(142,45,197));
        //p.setColor(QPalette::Highlight, QColor(255,102,0));
        p.setColor(QPalette::ButtonText, QColor(0,0,0));
        p.setColor(QPalette::WindowText, QColor(0,0,0));
        qApp->setPalette(p);
        ViewObject w;
        w.verifyUpdate();
        w.showTrayIcon();
        /*if(!Poohia_settings::getFirstStart())
        {
            w.show();
            Poohia_settings::setFirstStart(true);
        }*/


        return app.exec();
    }
}
