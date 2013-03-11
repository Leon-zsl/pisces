









#include "StreamReader.h"
#include "NpcConfig.h"

using namespace std;

std::map<int, NpcConfig*> NpcConfig::dic;
std::vector<NpcConfig*> NpcConfig::list;

NpcConfig::NpcConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 modelUrl_, 
    std::string
 animIdle_, 
    std::string
 animTalk_, 
    std::string
 animEffect_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    int



* textIDArr_,
    int
 factionID_, 
    int
 cargoID_, 
    int



* features_,
    std::string



* featureNames_,
    int



* missionIDArr_,
    int
 transferJobID_, 
    int
 deputyID_)
{
    id = id_;
    name = name_;
    modelUrl = modelUrl_;
    animIdle = animIdle_;
    animTalk = animTalk_;
    animEffect = animEffect_;
    length = length_;
    width = width_;
    height = height_;
    textIDArr = textIDArr_;
    factionID = factionID_;
    cargoID = cargoID_;
    features = features_;
    featureNames = featureNames_;
    missionIDArr = missionIDArr_;
    transferJobID = transferJobID_;
    deputyID = deputyID_;
}

NpcConfig::~NpcConfig()
{
    delete[] textIDArr;
    delete[] features;
    delete[] featureNames;
    delete[] missionIDArr;
}
    
void NpcConfig::build()
{
    std::string path = "./data/";
    path += "NpcConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "NpcConfig")
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

void NpcConfig::add_item(StreamReader* rs)
{
    int arr_item_len_NpcConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     modelUrl_ =     
    rs->read_string();

    
    std::string
     animIdle_ =     
    rs->read_string();

    
    std::string
     animTalk_ =     
    rs->read_string();

    
    std::string
     animEffect_ =     
    rs->read_string();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    
    float
     height_ =     
    rs->read_float();

    arr_item_len_NpcConfig = rs->read_short();
    
    int



*     textIDArr_ =     new 
    int



     [arr_item_len_NpcConfig];

    for(int i = 0; i < arr_item_len_NpcConfig; ++i)
        textIDArr_[i] =         
    rs->read_int();

    
    int
     factionID_ =     
    rs->read_int();

    
    int
     cargoID_ =     
    rs->read_int();

    arr_item_len_NpcConfig = rs->read_short();
    
    int



*     features_ =     new 
    int



     [arr_item_len_NpcConfig];

    for(int i = 0; i < arr_item_len_NpcConfig; ++i)
        features_[i] =         
    rs->read_int();

    arr_item_len_NpcConfig = rs->read_short();
    
    std::string



*     featureNames_ =     new 
    std::string



     [arr_item_len_NpcConfig];

    for(int i = 0; i < arr_item_len_NpcConfig; ++i)
        featureNames_[i] =         
    rs->read_string();

    arr_item_len_NpcConfig = rs->read_short();
    
    int



*     missionIDArr_ =     new 
    int



     [arr_item_len_NpcConfig];

    for(int i = 0; i < arr_item_len_NpcConfig; ++i)
        missionIDArr_[i] =         
    rs->read_int();

    
    int
     transferJobID_ =     
    rs->read_int();

    
    int
     deputyID_ =     
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

    NpcConfig* new_obj_NpcConfig = new NpcConfig(id_, name_, modelUrl_, animIdle_, animTalk_, animEffect_, length_, width_, height_, textIDArr_, factionID_, cargoID_, features_, featureNames_, missionIDArr_, transferJobID_, deputyID_);

    dic[id_] = new_obj_NpcConfig;
    list.push_back(new_obj_NpcConfig);
}

void NpcConfig::destroy()
{
    for(std::vector<NpcConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
