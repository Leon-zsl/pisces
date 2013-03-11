









#include "StreamReader.h"
#include "LandConfig.h"

using namespace std;

std::map<int, LandConfig*> LandConfig::dic;
std::vector<LandConfig*> LandConfig::list;

LandConfig::LandConfig(
    int
 id_, 
    std::string
 landName_, 
    int
 landType_, 
    int
 playerLimit_, 
    int



* sceneIDArr_,
    std::string
 landNameRes_, 
    int



* monsterIDArr_,
    int



* bossIDArr_,
    int



* mineIDArr_,
    int



* mineRateArr_,
    int
 mineCount_, 
    int



* boxIDArr_,
    int
 boxCount_, 
    int



* mapIDArr_,
    int



* connLandIDArr_,
    int



* connLandTimeArr_)
{
    id = id_;
    landName = landName_;
    landType = landType_;
    playerLimit = playerLimit_;
    sceneIDArr = sceneIDArr_;
    landNameRes = landNameRes_;
    monsterIDArr = monsterIDArr_;
    bossIDArr = bossIDArr_;
    mineIDArr = mineIDArr_;
    mineRateArr = mineRateArr_;
    mineCount = mineCount_;
    boxIDArr = boxIDArr_;
    boxCount = boxCount_;
    mapIDArr = mapIDArr_;
    connLandIDArr = connLandIDArr_;
    connLandTimeArr = connLandTimeArr_;
}

LandConfig::~LandConfig()
{
    delete[] sceneIDArr;
    delete[] monsterIDArr;
    delete[] bossIDArr;
    delete[] mineIDArr;
    delete[] mineRateArr;
    delete[] boxIDArr;
    delete[] mapIDArr;
    delete[] connLandIDArr;
    delete[] connLandTimeArr;
}
    
void LandConfig::build()
{
    std::string path = "./data/";
    path += "LandConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "LandConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 16)
    {
        printf("col cnt invalid %d : %d", col_cnt, 16);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void LandConfig::add_item(StreamReader* rs)
{
    int arr_item_len_LandConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     landName_ =     
    rs->read_string();

    
    int
     landType_ =     
    rs->read_int();

    
    int
     playerLimit_ =     
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     sceneIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        sceneIDArr_[i] =         
    rs->read_int();

    
    std::string
     landNameRes_ =     
    rs->read_string();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     monsterIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        monsterIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     bossIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        bossIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     mineIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        mineIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     mineRateArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        mineRateArr_[i] =         
    rs->read_int();

    
    int
     mineCount_ =     
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     boxIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        boxIDArr_[i] =         
    rs->read_int();

    
    int
     boxCount_ =     
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     mapIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        mapIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     connLandIDArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        connLandIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandConfig = rs->read_short();
    
    int



*     connLandTimeArr_ =     new 
    int



     [arr_item_len_LandConfig];

    for(int i = 0; i < arr_item_len_LandConfig; ++i)
        connLandTimeArr_[i] =         
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

    LandConfig* new_obj_LandConfig = new LandConfig(id_, landName_, landType_, playerLimit_, sceneIDArr_, landNameRes_, monsterIDArr_, bossIDArr_, mineIDArr_, mineRateArr_, mineCount_, boxIDArr_, boxCount_, mapIDArr_, connLandIDArr_, connLandTimeArr_);

    dic[id_] = new_obj_LandConfig;
    list.push_back(new_obj_LandConfig);
}

void LandConfig::destroy()
{
    for(std::vector<LandConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
