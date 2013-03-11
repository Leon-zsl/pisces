









#include "StreamReader.h"
#include "SceneConfig.h"

using namespace std;

std::map<int, SceneConfig*> SceneConfig::dic;
std::vector<SceneConfig*> SceneConfig::list;

SceneConfig::SceneConfig(
    int
 id_, 
    std::string
 sceneName_, 
    int
 sceneType_, 
    std::string
 resName_, 
    int
 landID_, 
    int
 level_, 
    float
 length_, 
    float
 width_, 
    std::string



* fixedBlockArr_,
    std::string
 bornPos_, 
    std::string



* portalArr_,
    std::string



* npcArr_,
    std::string



* boxMinePosArr_,
    std::string



* monsterPosArr_,
    std::string
 bossPos_, 
    std::string
 exBoxPos_)
{
    id = id_;
    sceneName = sceneName_;
    sceneType = sceneType_;
    resName = resName_;
    landID = landID_;
    level = level_;
    length = length_;
    width = width_;
    fixedBlockArr = fixedBlockArr_;
    bornPos = bornPos_;
    portalArr = portalArr_;
    npcArr = npcArr_;
    boxMinePosArr = boxMinePosArr_;
    monsterPosArr = monsterPosArr_;
    bossPos = bossPos_;
    exBoxPos = exBoxPos_;
}

SceneConfig::~SceneConfig()
{
    delete[] fixedBlockArr;
    delete[] portalArr;
    delete[] npcArr;
    delete[] boxMinePosArr;
    delete[] monsterPosArr;
}
    
void SceneConfig::build()
{
    std::string path = "./data/";
    path += "SceneConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "SceneConfig")
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

void SceneConfig::add_item(StreamReader* rs)
{
    int arr_item_len_SceneConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     sceneName_ =     
    rs->read_string();

    
    int
     sceneType_ =     
    rs->read_int();

    
    std::string
     resName_ =     
    rs->read_string();

    
    int
     landID_ =     
    rs->read_int();

    
    int
     level_ =     
    rs->read_int();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    arr_item_len_SceneConfig = rs->read_short();
    
    std::string



*     fixedBlockArr_ =     new 
    std::string



     [arr_item_len_SceneConfig];

    for(int i = 0; i < arr_item_len_SceneConfig; ++i)
        fixedBlockArr_[i] =         
    rs->read_string();

    
    std::string
     bornPos_ =     
    rs->read_string();

    arr_item_len_SceneConfig = rs->read_short();
    
    std::string



*     portalArr_ =     new 
    std::string



     [arr_item_len_SceneConfig];

    for(int i = 0; i < arr_item_len_SceneConfig; ++i)
        portalArr_[i] =         
    rs->read_string();

    arr_item_len_SceneConfig = rs->read_short();
    
    std::string



*     npcArr_ =     new 
    std::string



     [arr_item_len_SceneConfig];

    for(int i = 0; i < arr_item_len_SceneConfig; ++i)
        npcArr_[i] =         
    rs->read_string();

    arr_item_len_SceneConfig = rs->read_short();
    
    std::string



*     boxMinePosArr_ =     new 
    std::string



     [arr_item_len_SceneConfig];

    for(int i = 0; i < arr_item_len_SceneConfig; ++i)
        boxMinePosArr_[i] =         
    rs->read_string();

    arr_item_len_SceneConfig = rs->read_short();
    
    std::string



*     monsterPosArr_ =     new 
    std::string



     [arr_item_len_SceneConfig];

    for(int i = 0; i < arr_item_len_SceneConfig; ++i)
        monsterPosArr_[i] =         
    rs->read_string();

    
    std::string
     bossPos_ =     
    rs->read_string();

    
    std::string
     exBoxPos_ =     
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

    SceneConfig* new_obj_SceneConfig = new SceneConfig(id_, sceneName_, sceneType_, resName_, landID_, level_, length_, width_, fixedBlockArr_, bornPos_, portalArr_, npcArr_, boxMinePosArr_, monsterPosArr_, bossPos_, exBoxPos_);

    dic[id_] = new_obj_SceneConfig;
    list.push_back(new_obj_SceneConfig);
}

void SceneConfig::destroy()
{
    for(std::vector<SceneConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
