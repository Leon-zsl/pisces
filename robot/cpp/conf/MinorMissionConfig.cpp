









#include "StreamReader.h"
#include "MinorMissionConfig.h"

using namespace std;

std::map<int, MinorMissionConfig*> MinorMissionConfig::dic;
std::vector<MinorMissionConfig*> MinorMissionConfig::list;

MinorMissionConfig::MinorMissionConfig(
    int
 id_, 
    std::string
 missionName_, 
    int



* prestigeRequired_,
    int



* nameText_,
    int



* missionIntroText_,
    int



* missionWayText_,
    int



* missionCompleteText_,
    int
 missionCompleteCondText_, 
    int



* missionNPCText_,
    int



* missionMonsterText_,
    int



* vipParam_,
    float
 expBonusCoe_, 
    float
 moneyBonus_, 
    int
 prestigeBonus_, 
    int
 timeLimit_, 
    int



* boxEx_,
    int



* destroyBoxes_,
    int



* mineID_,
    int



* missionNPC_)
{
    id = id_;
    missionName = missionName_;
    prestigeRequired = prestigeRequired_;
    nameText = nameText_;
    missionIntroText = missionIntroText_;
    missionWayText = missionWayText_;
    missionCompleteText = missionCompleteText_;
    missionCompleteCondText = missionCompleteCondText_;
    missionNPCText = missionNPCText_;
    missionMonsterText = missionMonsterText_;
    vipParam = vipParam_;
    expBonusCoe = expBonusCoe_;
    moneyBonus = moneyBonus_;
    prestigeBonus = prestigeBonus_;
    timeLimit = timeLimit_;
    boxEx = boxEx_;
    destroyBoxes = destroyBoxes_;
    mineID = mineID_;
    missionNPC = missionNPC_;
}

MinorMissionConfig::~MinorMissionConfig()
{
    delete[] prestigeRequired;
    delete[] nameText;
    delete[] missionIntroText;
    delete[] missionWayText;
    delete[] missionCompleteText;
    delete[] missionNPCText;
    delete[] missionMonsterText;
    delete[] vipParam;
    delete[] boxEx;
    delete[] destroyBoxes;
    delete[] mineID;
    delete[] missionNPC;
}
    
void MinorMissionConfig::build()
{
    //std::string path = "./data/";
    //path += "MinorMissionConfig.bytes";
    std::string path = "MinorMissionConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "MinorMissionConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 19)
    {
        printf("col cnt invalid %d : %d", col_cnt, 19);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void MinorMissionConfig::add_item(StreamReader* rs)
{
    int arr_item_len_MinorMissionConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     missionName_ =     
    rs->read_string();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     prestigeRequired_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        prestigeRequired_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     nameText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        nameText_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionIntroText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionIntroText_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionWayText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionWayText_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionCompleteText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionCompleteText_[i] =         
    rs->read_int();

    
    int
     missionCompleteCondText_ =     
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionNPCText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionNPCText_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionMonsterText_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionMonsterText_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     vipParam_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        vipParam_[i] =         
    rs->read_int();

    
    float
     expBonusCoe_ =     
    rs->read_float();

    
    float
     moneyBonus_ =     
    rs->read_float();

    
    int
     prestigeBonus_ =     
    rs->read_int();

    
    int
     timeLimit_ =     
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     boxEx_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        boxEx_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     destroyBoxes_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        destroyBoxes_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     mineID_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        mineID_[i] =         
    rs->read_int();

    arr_item_len_MinorMissionConfig = rs->read_short();
    
    int



*     missionNPC_ =     new 
    int



     [arr_item_len_MinorMissionConfig];

    for(int i = 0; i < arr_item_len_MinorMissionConfig; ++i)
        missionNPC_[i] =         
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

    MinorMissionConfig* new_obj_MinorMissionConfig = new MinorMissionConfig(id_, missionName_, prestigeRequired_, nameText_, missionIntroText_, missionWayText_, missionCompleteText_, missionCompleteCondText_, missionNPCText_, missionMonsterText_, vipParam_, expBonusCoe_, moneyBonus_, prestigeBonus_, timeLimit_, boxEx_, destroyBoxes_, mineID_, missionNPC_);

    dic[id_] = new_obj_MinorMissionConfig;
    list.push_back(new_obj_MinorMissionConfig);
}

void MinorMissionConfig::destroy()
{
    for(std::vector<MinorMissionConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
