#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
using namespace std;
struct Character_config{
    string image_path;
    string size_str;
    int x_position;
    int y_position;
    double x_velocity;
    double y_velocity;
    string motion;
};

class ConfigManager
{
public:

    void read(string filename);
    string m_background_path;
    int m_window_size;
    vector<Character_config*> character_settings;
    void print_characters();
    ~ConfigManager(){
        for(auto cfg:character_settings){
            delete cfg;
        }
    };
};

#endif // CONFIGMANAGER_H
