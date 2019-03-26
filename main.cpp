#include "dialog.h"
#include <QApplication>
#include "peppafactory.h"
#include "peppagamebuilder.h"
#include "director.h"
#include <iostream>
#include <fstream>
#include <configmanager.h>


using namespace std;
int main(int argc, char *argv[])
{

    ConfigManager* cm = new ConfigManager;
    cm->read(":/resources/config.txt");
    cm->print_characters();

    QApplication a(argc, argv);
    PeppaFactory* pf = new PeppaFactory;
    PeppaGameBuilder* pgb = new PeppaGameBuilder;
    Director director(pgb, pf, cm);
    Dialog w;

    w.setGame(director.makeGame());

    w.loadGame();

    w.show();

    delete cm;
    delete pf;
    delete pgb;
    return a.exec();
}
