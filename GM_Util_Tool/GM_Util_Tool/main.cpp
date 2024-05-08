#include "GM_Util_Tool.h"
#include <QtWidgets/QApplication>
#include <Entity.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GM_Util_Tool w;
    w.show();
    Entity e1;
    e1.setArmor(12);
    QTextStream (stdout)<<"test";
    std::cout << "test";
    system("PAUSE");
   
    return a.exec();
}
