#include "configmanager.h"
#include <QPixmap>
#include <iostream>

/*
 * reads from the Json file specified by filename string.
 */
void ConfigManager::read(std::string filename)
{
    QString val;
    QFile file(filename.c_str());

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject object = document.object();

    //reads background information
    QJsonValue background = object.value("Background");
    QJsonObject background_object = background.toObject();
    m_background_path = background_object.value("path").toString().toStdString();
    m_background_width = background_object.value("width").toInt();
    m_background_height = background_object.value("height").toInt();
    m_background_velocity = background_object.value("velocity").toDouble();

    //reads each of the character information

    QJsonValue value = object.value("Character");
    QJsonArray array = value.toArray();
    vector<Character_config*> m_characters;

    for (const auto x : array){
         Character_config* c = new Character_config();
         QJsonObject x_value =x.toObject();
         c->image_path = x_value.value("image_path").toString().toStdString();
         c->size_str = size_check(x_value.value("size").toString().toStdString());
         c->x_position = x_value.value("x_pos").toInt();
         c->y_position = x_value.value("y_pos").toInt();
         c->x_max = m_background_width;
         c->y_max = m_background_height;
         c->motion = x_value.value("motion").toString().toStdString();
         c->x_velocity = x_value.value("x_velocity").toDouble();
         m_characters.push_back(c);
    }
    character_settings = m_characters;
}

//check size to prevent error.
string ConfigManager::size_check(string size){
    if (size!="TINY"&&size!="REGULAR"&&size!="LARGE"&&size!="GIANT"){
        return "REGULAR";
    }else{
        return size;
    }
}

//print the character information for debugging purpose.
void ConfigManager::print_characters() const{
    for(auto const& value: character_settings){
        std::cout<<value->size_str<<" "<<value->image_path<<" "<<value->x_position<<" "<<value->y_position<<" "<<value->motion<<std::endl;
    }
}
