#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

using namespace std;
/*
 * temporarily stores the configuration file related to each characters.
 */
struct Character_config{
    string image_path;
    string size_str;
    int x_position;
    int y_position;
    int x_max;
    int y_max;
    double x_velocity;
    double y_velocity;
    string motion;
};

/*
 * The purpose of this class is to temporarily stores the configuration file data.
 * config manager is then passed to the director in the builder pattern to assemble the game.
 */
class ConfigManager
{
public:

    void read(string filename);

    string m_background_path;
    int m_background_width;
    int m_background_height;
    int m_background_velocity;
    string size_check(string size);
    vector<Character_config*> character_settings;
    void print_characters() const;
    ~ConfigManager(){
        for(auto cfg:character_settings){
            delete cfg;
        }
    }
};

#endif // CONFIGMANAGER_H
