









#include "StreamReader.h"
#include "DeputyConfig.h"

using namespace std;

std::map<int, DeputyConfig*> DeputyConfig::dic;
std::vector<DeputyConfig*> DeputyConfig::list;

DeputyConfig::DeputyConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 texUrl_, 
    int



* deputyPointsLimits_,
    int



* jobLevels_,
    std::string



* levelName_,
    int



* moneys_,
    int
 subDeputyCount_, 
    std::string



* subDeputyNames_,
    int



* initDeputySkillIDs_,
    std::string
 description_)
{
    id = id_;
    name = name_;
    texUrl = texUrl_;
    deputyPointsLimits = deputyPointsLimits_;
    jobLevels = jobLevels_;
    levelName = levelName_;
    moneys = moneys_;
    subDeputyCount = subDeputyCount_;
    subDeputyNames = subDeputyNames_;
    initDeputySkillIDs = initDeputySkillIDs_;
    description = description_;
}

DeputyConfig::~DeputyConfig()
{
    delete[] deputyPointsLimits;
    delete[] jobLevels;
    delete[] levelName;
    delete[] moneys;
    delete[] subDeputyNames;
    delete[] initDeputySkillIDs;
}
    
void DeputyConfig::build()
{
    std::string path = "./data/";
    path += "DeputyConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "DeputyConfig")
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

void DeputyConfig::add_item(StreamReader* rs)
{
    int arr_item_len_DeputyConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     texUrl_ =     
    rs->read_string();

    arr_item_len_DeputyConfig = rs->read_short();
    
    int



*     deputyPointsLimits_ =     new 
    int



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        deputyPointsLimits_[i] =         
    rs->read_int();

    arr_item_len_DeputyConfig = rs->read_short();
    
    int



*     jobLevels_ =     new 
    int



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        jobLevels_[i] =         
    rs->read_int();

    arr_item_len_DeputyConfig = rs->read_short();
    
    std::string



*     levelName_ =     new 
    std::string



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        levelName_[i] =         
    rs->read_string();

    arr_item_len_DeputyConfig = rs->read_short();
    
    int



*     moneys_ =     new 
    int



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        moneys_[i] =         
    rs->read_int();

    
    int
     subDeputyCount_ =     
    rs->read_int();

    arr_item_len_DeputyConfig = rs->read_short();
    
    std::string



*     subDeputyNames_ =     new 
    std::string



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        subDeputyNames_[i] =         
    rs->read_string();

    arr_item_len_DeputyConfig = rs->read_short();
    
    int



*     initDeputySkillIDs_ =     new 
    int



     [arr_item_len_DeputyConfig];

    for(int i = 0; i < arr_item_len_DeputyConfig; ++i)
        initDeputySkillIDs_[i] =         
    rs->read_int();

    
    std::string
     description_ =     
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

    DeputyConfig* new_obj_DeputyConfig = new DeputyConfig(id_, name_, texUrl_, deputyPointsLimits_, jobLevels_, levelName_, moneys_, subDeputyCount_, subDeputyNames_, initDeputySkillIDs_, description_);

    dic[id_] = new_obj_DeputyConfig;
    list.push_back(new_obj_DeputyConfig);
}

void DeputyConfig::destroy()
{
    for(std::vector<DeputyConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
