#include "dialog.h"
#include <QApplication>
#include "peppafactory.h"
#include "peppagamebuilder.h"
#include "director.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PeppaFactory* pf = new PeppaFactory;
    PeppaGameBuilder* pgb = new PeppaGameBuilder;
    Director director(pgb, pf);
    Dialog w;
    w.setGame(director.makeGame());
    w.loadGame();
    w.show();
    //how can I delete everything in
    delete pf;
    delete pgb;
    return a.exec();
}
