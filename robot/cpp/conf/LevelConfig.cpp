









#include "StreamReader.h"
#include "LevelConfig.h"

using namespace std;

std::map<int, LevelConfig*> LevelConfig::dic;
std::vector<LevelConfig*> LevelConfig::list;

LevelConfig::LevelConfig(
    int
 id_, 
    int
 expRequired_, 
    int
 baseExp_, 
    int
 missionBaseExp_, 
    int



* minorMissionType_,
    int



* randGroupLand_,
    int



* randGroupNPCArr_,
    int



* randGroupForbiddenTypeArr_,
    int



* minorMissionLand_,
    int
 minorMissionMoney_, 
    int



* minorMissionItemBonus_,
    int



* minorMissionItemBonusCount_,
    int



* monsterItemIDArr_,
    double



* monsterItemRateArr_,
    int



* bossItemIDArr_,
    double



* bossItemRateArr_,
    int
 monsterCorpseID_, 
    int
 monsterMoney_, 
    float
 monsterMoneyRate_, 
    int
 dailyMissionMoney_)
{
    id = id_;
    expRequired = expRequired_;
    baseExp = baseExp_;
    missionBaseExp = missionBaseExp_;
    minorMissionType = minorMissionType_;
    randGroupLand = randGroupLand_;
    randGroupNPCArr = randGroupNPCArr_;
    randGroupForbiddenTypeArr = randGroupForbiddenTypeArr_;
    minorMissionLand = minorMissionLand_;
    minorMissionMoney = minorMissionMoney_;
    minorMissionItemBonus = minorMissionItemBonus_;
    minorMissionItemBonusCount = minorMissionItemBonusCount_;
    monsterItemIDArr = monsterItemIDArr_;
    monsterItemRateArr = monsterItemRateArr_;
    bossItemIDArr = bossItemIDArr_;
    bossItemRateArr = bossItemRateArr_;
    monsterCorpseID = monsterCorpseID_;
    monsterMoney = monsterMoney_;
    monsterMoneyRate = monsterMoneyRate_;
    dailyMissionMoney = dailyMissionMoney_;
}

LevelConfig::~LevelConfig()
{
    delete[] minorMissionType;
    delete[] randGroupLand;
    delete[] randGroupNPCArr;
    delete[] randGroupForbiddenTypeArr;
    delete[] minorMissionLand;
    delete[] minorMissionItemBonus;
    delete[] minorMissionItemBonusCount;
    delete[] monsterItemIDArr;
    delete[] monsterItemRateArr;
    delete[] bossItemIDArr;
    delete[] bossItemRateArr;
}
    
void LevelConfig::build()
{
    //std::string path = "./data/";
    //path += "LevelConfig.bytes";
    std::string path = "LevelConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "LevelConfig")
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

void LevelConfig::add_item(StreamReader* rs)
{
    int arr_item_len_LevelConfig;

    
    int
     id_ =     
    rs->read_int();

    
    int
     expRequired_ =     
    rs->read_int();

    
    int
     baseExp_ =     
    rs->read_int();

    
    int
     missionBaseExp_ =     
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     minorMissionType_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        minorMissionType_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     randGroupLand_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        randGroupLand_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     randGroupNPCArr_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        randGroupNPCArr_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     randGroupForbiddenTypeArr_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        randGroupForbiddenTypeArr_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     minorMissionLand_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        minorMissionLand_[i] =         
    rs->read_int();

    
    int
     minorMissionMoney_ =     
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     minorMissionItemBonus_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        minorMissionItemBonus_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     minorMissionItemBonusCount_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        minorMissionItemBonusCount_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     monsterItemIDArr_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        monsterItemIDArr_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    double



*     monsterItemRateArr_ =     new 
    double



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        monsterItemRateArr_[i] =         
    rs->read_double();

    arr_item_len_LevelConfig = rs->read_short();
    
    int



*     bossItemIDArr_ =     new 
    int



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        bossItemIDArr_[i] =         
    rs->read_int();

    arr_item_len_LevelConfig = rs->read_short();
    
    double



*     bossItemRateArr_ =     new 
    double



     [arr_item_len_LevelConfig];

    for(int i = 0; i < arr_item_len_LevelConfig; ++i)
        bossItemRateArr_[i] =         
    rs->read_double();

    
    int
     monsterCorpseID_ =     
    rs->read_int();

    
    int
     monsterMoney_ =     
    rs->read_int();

    
    float
     monsterMoneyRate_ =     
    rs->read_float();

    
    int
     dailyMissionMoney_ =     
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

    LevelConfig* new_obj_LevelConfig = new LevelConfig(id_, expRequired_, baseExp_, missionBaseExp_, minorMissionType_, randGroupLand_, randGroupNPCArr_, randGroupForbiddenTypeArr_, minorMissionLand_, minorMissionMoney_, minorMissionItemBonus_, minorMissionItemBonusCount_, monsterItemIDArr_, monsterItemRateArr_, bossItemIDArr_, bossItemRateArr_, monsterCorpseID_, monsterMoney_, monsterMoneyRate_, dailyMissionMoney_);

    dic[id_] = new_obj_LevelConfig;
    list.push_back(new_obj_LevelConfig);
}

void LevelConfig::destroy()
{
    for(std::vector<LevelConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
