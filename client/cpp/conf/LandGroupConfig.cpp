









#include "StreamReader.h"
#include "LandGroupConfig.h"

using namespace std;

std::map<int, LandGroupConfig*> LandGroupConfig::dic;
std::vector<LandGroupConfig*> LandGroupConfig::list;

LandGroupConfig::LandGroupConfig(
    int
 id_, 
    std::string
 landGroupName_, 
    std::string
 normalIcon_, 
    std::string
 hoverIcon_, 
    std::string
 activeIcon_, 
    float
 posX_, 
    float
 posY_, 
    float
 ctrPosX_, 
    float
 ctrPosY_, 
    float
 ctrWidth_, 
    float
 ctrHeight_, 
    int
 landType_, 
    bool
 landPluFlag_, 
    int



* landIDArr_,
    int



* landPortalArr_,
    std::string



* iconArr_,
    std::string



* infoIconArr_)
{
    id = id_;
    landGroupName = landGroupName_;
    normalIcon = normalIcon_;
    hoverIcon = hoverIcon_;
    activeIcon = activeIcon_;
    posX = posX_;
    posY = posY_;
    ctrPosX = ctrPosX_;
    ctrPosY = ctrPosY_;
    ctrWidth = ctrWidth_;
    ctrHeight = ctrHeight_;
    landType = landType_;
    landPluFlag = landPluFlag_;
    landIDArr = landIDArr_;
    landPortalArr = landPortalArr_;
    iconArr = iconArr_;
    infoIconArr = infoIconArr_;
}

LandGroupConfig::~LandGroupConfig()
{
    delete[] landIDArr;
    delete[] landPortalArr;
    delete[] iconArr;
    delete[] infoIconArr;
}
    
void LandGroupConfig::build()
{
    std::string path = "./data/";
    path += "LandGroupConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "LandGroupConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 17)
    {
        printf("col cnt invalid %d : %d", col_cnt, 17);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void LandGroupConfig::add_item(StreamReader* rs)
{
    int arr_item_len_LandGroupConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     landGroupName_ =     
    rs->read_string();

    
    std::string
     normalIcon_ =     
    rs->read_string();

    
    std::string
     hoverIcon_ =     
    rs->read_string();

    
    std::string
     activeIcon_ =     
    rs->read_string();

    
    float
     posX_ =     
    rs->read_float();

    
    float
     posY_ =     
    rs->read_float();

    
    float
     ctrPosX_ =     
    rs->read_float();

    
    float
     ctrPosY_ =     
    rs->read_float();

    
    float
     ctrWidth_ =     
    rs->read_float();

    
    float
     ctrHeight_ =     
    rs->read_float();

    
    int
     landType_ =     
    rs->read_int();

    
    bool
     landPluFlag_ =     
    rs->read_bool();

    arr_item_len_LandGroupConfig = rs->read_short();
    
    int



*     landIDArr_ =     new 
    int



     [arr_item_len_LandGroupConfig];

    for(int i = 0; i < arr_item_len_LandGroupConfig; ++i)
        landIDArr_[i] =         
    rs->read_int();

    arr_item_len_LandGroupConfig = rs->read_short();
    
    int



*     landPortalArr_ =     new 
    int



     [arr_item_len_LandGroupConfig];

    for(int i = 0; i < arr_item_len_LandGroupConfig; ++i)
        landPortalArr_[i] =         
    rs->read_int();

    arr_item_len_LandGroupConfig = rs->read_short();
    
    std::string



*     iconArr_ =     new 
    std::string



     [arr_item_len_LandGroupConfig];

    for(int i = 0; i < arr_item_len_LandGroupConfig; ++i)
        iconArr_[i] =         
    rs->read_string();

    arr_item_len_LandGroupConfig = rs->read_short();
    
    std::string



*     infoIconArr_ =     new 
    std::string



     [arr_item_len_LandGroupConfig];

    for(int i = 0; i < arr_item_len_LandGroupConfig; ++i)
        infoIconArr_[i] =         
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

    LandGroupConfig* new_obj_LandGroupConfig = new LandGroupConfig(id_, landGroupName_, normalIcon_, hoverIcon_, activeIcon_, posX_, posY_, ctrPosX_, ctrPosY_, ctrWidth_, ctrHeight_, landType_, landPluFlag_, landIDArr_, landPortalArr_, iconArr_, infoIconArr_);

    dic[id_] = new_obj_LandGroupConfig;
    list.push_back(new_obj_LandGroupConfig);
}

void LandGroupConfig::destroy()
{
    for(std::vector<LandGroupConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
