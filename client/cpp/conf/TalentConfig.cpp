









#include "StreamReader.h"
#include "TalentConfig.h"

using namespace std;

std::map<int, TalentConfig*> TalentConfig::dic;
std::vector<TalentConfig*> TalentConfig::list;

TalentConfig::TalentConfig(
    int
 id_, 
    std::string
 name_, 
    int
 attPropType_, 
    int
 jobID_, 
    int
 consumeType_, 
    int
 attackSkillID_, 
    int



* initSkillIDArr_,
    int



* skillIDArr_,
    int



* weaponType1Arr_,
    int



* weaponType2Arr_,
    int



* weaponType3Arr_)
{
    id = id_;
    name = name_;
    attPropType = attPropType_;
    jobID = jobID_;
    consumeType = consumeType_;
    attackSkillID = attackSkillID_;
    initSkillIDArr = initSkillIDArr_;
    skillIDArr = skillIDArr_;
    weaponType1Arr = weaponType1Arr_;
    weaponType2Arr = weaponType2Arr_;
    weaponType3Arr = weaponType3Arr_;
}

TalentConfig::~TalentConfig()
{
    delete[] initSkillIDArr;
    delete[] skillIDArr;
    delete[] weaponType1Arr;
    delete[] weaponType2Arr;
    delete[] weaponType3Arr;
}
    
void TalentConfig::build()
{
    std::string path = "./data/";
    path += "TalentConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "TalentConfig")
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

void TalentConfig::add_item(StreamReader* rs)
{
    int arr_item_len_TalentConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    int
     attPropType_ =     
    rs->read_int();

    
    int
     jobID_ =     
    rs->read_int();

    
    int
     consumeType_ =     
    rs->read_int();

    
    int
     attackSkillID_ =     
    rs->read_int();

    arr_item_len_TalentConfig = rs->read_short();
    
    int



*     initSkillIDArr_ =     new 
    int



     [arr_item_len_TalentConfig];

    for(int i = 0; i < arr_item_len_TalentConfig; ++i)
        initSkillIDArr_[i] =         
    rs->read_int();

    arr_item_len_TalentConfig = rs->read_short();
    
    int



*     skillIDArr_ =     new 
    int



     [arr_item_len_TalentConfig];

    for(int i = 0; i < arr_item_len_TalentConfig; ++i)
        skillIDArr_[i] =         
    rs->read_int();

    arr_item_len_TalentConfig = rs->read_short();
    
    int



*     weaponType1Arr_ =     new 
    int



     [arr_item_len_TalentConfig];

    for(int i = 0; i < arr_item_len_TalentConfig; ++i)
        weaponType1Arr_[i] =         
    rs->read_int();

    arr_item_len_TalentConfig = rs->read_short();
    
    int



*     weaponType2Arr_ =     new 
    int



     [arr_item_len_TalentConfig];

    for(int i = 0; i < arr_item_len_TalentConfig; ++i)
        weaponType2Arr_[i] =         
    rs->read_int();

    arr_item_len_TalentConfig = rs->read_short();
    
    int



*     weaponType3Arr_ =     new 
    int



     [arr_item_len_TalentConfig];

    for(int i = 0; i < arr_item_len_TalentConfig; ++i)
        weaponType3Arr_[i] =         
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

    TalentConfig* new_obj_TalentConfig = new TalentConfig(id_, name_, attPropType_, jobID_, consumeType_, attackSkillID_, initSkillIDArr_, skillIDArr_, weaponType1Arr_, weaponType2Arr_, weaponType3Arr_);

    dic[id_] = new_obj_TalentConfig;
    list.push_back(new_obj_TalentConfig);
}

void TalentConfig::destroy()
{
    for(std::vector<TalentConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
