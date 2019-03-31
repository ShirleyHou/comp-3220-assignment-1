#include <QApplication>
#include <configmanager.h>

#include "peppafactory.h"
#include "peppagamebuilder.h"
#include "director.h"
#include "dialog.h"
#include "peppa_evil_factory.h"

using namespace std;
int main(int argc, char *argv[])
{

    ConfigManager* cm = new ConfigManager;
    cm->read(":/resources/config.txt");
    cm->print_characters();

    QApplication a(argc, argv);

    //abstract factory pattern + builder pattern
    PeppaFactory* pf = new PeppaFactory;
    peppa_evil_factory* pef = new peppa_evil_factory;

    //builder pattern
    PeppaGameBuilder* pgb = new PeppaGameBuilder;
    Director director(pgb, pef, cm);
    Dialog w;
    Game* game1 = director.makeGame("qrc:/resources/sound/swag.mp3");
    Director director2(pgb, pf, cm);
    Game* game2 = director2.makeGame("qrc:/resources/sound/peppa.mp3");
    vector<Game*> games;

    games.push_back(game2);
    games.push_back(game1);

    w.setGames(games);
    w.loadGame();

    w.show();

    delete cm;
    delete pf;
    delete pgb;
    return a.exec();
}
