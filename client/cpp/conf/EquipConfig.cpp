









#include "StreamReader.h"
#include "EquipConfig.h"

using namespace std;

std::map<int, EquipConfig*> EquipConfig::dic;
std::vector<EquipConfig*> EquipConfig::list;

EquipConfig::EquipConfig(
    int
 id_, 
    std::string
 name_, 
    int
 part_, 
    int
 weaponProp_, 
    int
 weaponType_, 
    int
 clothType_, 
    int



* jobLimit_,
    int
 maxEndure_, 
    int



* propIDArr_,
    int



* propValueArr_,
    float
 fixParam_, 
    int



* avatarIDArr_,
    std::string



* avatarNameArr_,
    int
 holeCount_)
{
    id = id_;
    name = name_;
    part = part_;
    weaponProp = weaponProp_;
    weaponType = weaponType_;
    clothType = clothType_;
    jobLimit = jobLimit_;
    maxEndure = maxEndure_;
    propIDArr = propIDArr_;
    propValueArr = propValueArr_;
    fixParam = fixParam_;
    avatarIDArr = avatarIDArr_;
    avatarNameArr = avatarNameArr_;
    holeCount = holeCount_;
}

EquipConfig::~EquipConfig()
{
    delete[] jobLimit;
    delete[] propIDArr;
    delete[] propValueArr;
    delete[] avatarIDArr;
    delete[] avatarNameArr;
}
    
void EquipConfig::build()
{
    //std::string path = "./data/";
    //path += "EquipConfig.bytes";
    std::string path = "EquipConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "EquipConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 14)
    {
        printf("col cnt invalid %d : %d", col_cnt, 14);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void EquipConfig::add_item(StreamReader* rs)
{
    int arr_item_len_EquipConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    int
     part_ =     
    rs->read_int();

    
    int
     weaponProp_ =     
    rs->read_int();

    
    int
     weaponType_ =     
    rs->read_int();

    
    int
     clothType_ =     
    rs->read_int();

    arr_item_len_EquipConfig = rs->read_short();
    
    int



*     jobLimit_ =     new 
    int



     [arr_item_len_EquipConfig];

    for(int i = 0; i < arr_item_len_EquipConfig; ++i)
        jobLimit_[i] =         
    rs->read_int();

    
    int
     maxEndure_ =     
    rs->read_int();

    arr_item_len_EquipConfig = rs->read_short();
    
    int



*     propIDArr_ =     new 
    int



     [arr_item_len_EquipConfig];

    for(int i = 0; i < arr_item_len_EquipConfig; ++i)
        propIDArr_[i] =         
    rs->read_int();

    arr_item_len_EquipConfig = rs->read_short();
    
    int



*     propValueArr_ =     new 
    int



     [arr_item_len_EquipConfig];

    for(int i = 0; i < arr_item_len_EquipConfig; ++i)
        propValueArr_[i] =         
    rs->read_int();

    
    float
     fixParam_ =     
    rs->read_float();

    arr_item_len_EquipConfig = rs->read_short();
    
    int



*     avatarIDArr_ =     new 
    int



     [arr_item_len_EquipConfig];

    for(int i = 0; i < arr_item_len_EquipConfig; ++i)
        avatarIDArr_[i] =         
    rs->read_int();

    arr_item_len_EquipConfig = rs->read_short();
    
    std::string



*     avatarNameArr_ =     new 
    std::string



     [arr_item_len_EquipConfig];

    for(int i = 0; i < arr_item_len_EquipConfig; ++i)
        avatarNameArr_[i] =         
    rs->read_string();

    
    int
     holeCount_ =     
    rs->read_int();

        
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

    EquipConfig* new_obj_EquipConfig = new EquipConfig(id_, name_, part_, weaponProp_, weaponType_, clothType_, jobLimit_, maxEndure_, propIDArr_, propValueArr_, fixParam_, avatarIDArr_, avatarNameArr_, holeCount_);

    dic[id_] = new_obj_EquipConfig;
    list.push_back(new_obj_EquipConfig);
}

void EquipConfig::destroy()
{
    for(std::vector<EquipConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
