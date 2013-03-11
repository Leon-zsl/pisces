









#include "StreamReader.h"
#include "BoxConfig.h"

using namespace std;

std::map<int, BoxConfig*> BoxConfig::dic;
std::vector<BoxConfig*> BoxConfig::list;

BoxConfig::BoxConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 resUrl_, 
    bool
 isInteractive_, 
    int
 refreshSecond_, 
    int
 health_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    int
 damageSkillID_, 
    std::string



* dropObjectsData_)
{
    id = id_;
    name = name_;
    resUrl = resUrl_;
    isInteractive = isInteractive_;
    refreshSecond = refreshSecond_;
    health = health_;
    length = length_;
    width = width_;
    height = height_;
    damageSkillID = damageSkillID_;
    dropObjectsData = dropObjectsData_;
}

BoxConfig::~BoxConfig()
{
    delete[] dropObjectsData;
}
    
void BoxConfig::build()
{
    std::string path = "./data/";
    path += "BoxConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "BoxConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 11)
    {
        printf("col cnt invalid %d : %d", col_cnt, 11);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void BoxConfig::add_item(StreamReader* rs)
{
    int arr_item_len_BoxConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     resUrl_ =     
    rs->read_string();

    
    bool
     isInteractive_ =     
    rs->read_bool();

    
    int
     refreshSecond_ =     
    rs->read_int();

    
    int
     health_ =     
    rs->read_int();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    
    float
     height_ =     
    rs->read_float();

    
    int
     damageSkillID_ =     
    rs->read_int();

    arr_item_len_BoxConfig = rs->read_short();
    
    std::string



*     dropObjectsData_ =     new 
    std::string



     [arr_item_len_BoxConfig];

    for(int i = 0; i < arr_item_len_BoxConfig; ++i)
        dropObjectsData_[i] =         
    rs->read_string();

        
    if(id_ == 0)
    {
        printf("invalid key: %d", id_);
        return;
    }
    if(dic.find(id_) != dic.end())
    {
        printf("duplicate key: %d", id_);
        return;
    }

    BoxConfig* new_obj_BoxConfig = new BoxConfig(id_, name_, resUrl_, isInteractive_, refreshSecond_, health_, length_, width_, height_, damageSkillID_, dropObjectsData_);

    dic[id_] = new_obj_BoxConfig;
    list.push_back(new_obj_BoxConfig);
}

void BoxConfig::destroy()
{
    for(std::vector<BoxConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
