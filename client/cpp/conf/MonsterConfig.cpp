









#include "StreamReader.h"
#include "MonsterConfig.h"

using namespace std;

std::map<int, MonsterConfig*> MonsterConfig::dic;
std::vector<MonsterConfig*> MonsterConfig::list;

MonsterConfig::MonsterConfig(
    int
 id_, 
    std::string
 name_, 
    int
 type_, 
    int
 propID_, 
    int
 figureID_, 
    float
 numInt_, 
    int
 refreshSecond_, 
    int



* skillIDArr_,
    int



* itemIDArr_,
    double



* itemRateArr_,
    int



* missionItem_,
    float
 sight_, 
    float
 attackRange_, 
    int
 attackSkillID_, 
    std::string



* healthAIArr_,
    std::string



* manaAIArr_,
    std::string



* furyAIArr_,
    std::string



* energyAIArr_,
    bool
 isPeeled_, 
    bool
 cannotMove_)
{
    id = id_;
    name = name_;
    type = type_;
    propID = propID_;
    figureID = figureID_;
    numInt = numInt_;
    refreshSecond = refreshSecond_;
    skillIDArr = skillIDArr_;
    itemIDArr = itemIDArr_;
    itemRateArr = itemRateArr_;
    missionItem = missionItem_;
    sight = sight_;
    attackRange = attackRange_;
    attackSkillID = attackSkillID_;
    healthAIArr = healthAIArr_;
    manaAIArr = manaAIArr_;
    furyAIArr = furyAIArr_;
    energyAIArr = energyAIArr_;
    isPeeled = isPeeled_;
    cannotMove = cannotMove_;
}

MonsterConfig::~MonsterConfig()
{
    delete[] skillIDArr;
    delete[] itemIDArr;
    delete[] itemRateArr;
    delete[] missionItem;
    delete[] healthAIArr;
    delete[] manaAIArr;
    delete[] furyAIArr;
    delete[] energyAIArr;
}
    
void MonsterConfig::build()
{
    //std::string path = "./data/";
    //path += "MonsterConfig.bytes";
    std::string path = "MonsterConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "MonsterConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 20)
    {
        printf("col cnt invalid %d : %d", col_cnt, 20);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void MonsterConfig::add_item(StreamReader* rs)
{
    int arr_item_len_MonsterConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    int
     type_ =     
    rs->read_int();

    
    int
     propID_ =     
    rs->read_int();

    
    int
     figureID_ =     
    rs->read_int();

    
    float
     numInt_ =     
    rs->read_float();

    
    int
     refreshSecond_ =     
    rs->read_int();

    arr_item_len_MonsterConfig = rs->read_short();
    
    int



*     skillIDArr_ =     new 
    int



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        skillIDArr_[i] =         
    rs->read_int();

    arr_item_len_MonsterConfig = rs->read_short();
    
    int



*     itemIDArr_ =     new 
    int



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        itemIDArr_[i] =         
    rs->read_int();

    arr_item_len_MonsterConfig = rs->read_short();
    
    double



*     itemRateArr_ =     new 
    double



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        itemRateArr_[i] =         
    rs->read_double();

    arr_item_len_MonsterConfig = rs->read_short();
    
    int



*     missionItem_ =     new 
    int



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        missionItem_[i] =         
    rs->read_int();

    
    float
     sight_ =     
    rs->read_float();

    
    float
     attackRange_ =     
    rs->read_float();

    
    int
     attackSkillID_ =     
    rs->read_int();

    arr_item_len_MonsterConfig = rs->read_short();
    
    std::string



*     healthAIArr_ =     new 
    std::string



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        healthAIArr_[i] =         
    rs->read_string();

    arr_item_len_MonsterConfig = rs->read_short();
    
    std::string



*     manaAIArr_ =     new 
    std::string



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        manaAIArr_[i] =         
    rs->read_string();

    arr_item_len_MonsterConfig = rs->read_short();
    
    std::string



*     furyAIArr_ =     new 
    std::string



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        furyAIArr_[i] =         
    rs->read_string();

    arr_item_len_MonsterConfig = rs->read_short();
    
    std::string



*     energyAIArr_ =     new 
    std::string



     [arr_item_len_MonsterConfig];

    for(int i = 0; i < arr_item_len_MonsterConfig; ++i)
        energyAIArr_[i] =         
    rs->read_string();

    
    bool
     isPeeled_ =     
    rs->read_bool();

    
    bool
     cannotMove_ =     
    rs->read_bool();

        
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

    MonsterConfig* new_obj_MonsterConfig = new MonsterConfig(id_, name_, type_, propID_, figureID_, numInt_, refreshSecond_, skillIDArr_, itemIDArr_, itemRateArr_, missionItem_, sight_, attackRange_, attackSkillID_, healthAIArr_, manaAIArr_, furyAIArr_, energyAIArr_, isPeeled_, cannotMove_);

    dic[id_] = new_obj_MonsterConfig;
    list.push_back(new_obj_MonsterConfig);
}

void MonsterConfig::destroy()
{
    for(std::vector<MonsterConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
