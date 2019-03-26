#include "configmanager.h"

#include <iostream>
void ConfigManager::read(std::string filename)
{
    QString val;
    QFile file(filename.c_str());

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject object = document.object();

    QJsonValue value = object.value("Character");
    QJsonArray array = value.toArray();
    vector<Character_config*> m_characters;

    for (const auto x : array){
         Character_config* c = new Character_config();
         QJsonObject x_value =x.toObject();
         c->image_path = x_value.value("image_path").toString().toStdString();
         c->size_str = x_value.value("size").toString().toStdString();
         c->x_position = x_value.value("x_pos").toInt();
         c->y_position = x_value.value("y_pos").toInt();
         c->motion = x_value.value("motion").toString().toStdString();
         m_characters.push_back(c);
    }
    character_settings = m_characters;
         //cout << v.toObject().value("name").toString().toStdString()<<endl;
}


void ConfigManager::print_characters(){
    for(auto const& value: character_settings){
        std::cout<<value->size_str<<" "<<value->image_path<<" "<<value->x_position<<" "<<value->y_position<<" "<<value->motion<<std::endl;
    }
}
