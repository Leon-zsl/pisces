









#include "StreamReader.h"
#include "DeputySkillConfig.h"

using namespace std;

std::map<int, DeputySkillConfig*> DeputySkillConfig::dic;
std::vector<DeputySkillConfig*> DeputySkillConfig::list;

DeputySkillConfig::DeputySkillConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 texUrl_, 
    int
 deputyID_, 
    int



* itemIDs_,
    int



* itemCounts_,
    bool
 isSltItemRqr_, 
    int



* addiItemIDs_,
    int



* addItemCounts_,
    std::string



* randomItems_,
    int
 targetItemID_, 
    int
 targetItemCount_, 
    int
 requiredItemID_, 
    int
 deputyLevel_, 
    std::string
 description_, 
    int
 orangeLevel_, 
    int
 yellowLevel_, 
    int
 greenLevel_, 
    int
 money_, 
    int
 subDeputyID_, 
    int



* stgPart_,
    int
 costTime_, 
    int



* stgPropIDs_,
    int



* stgPropValues_,
    int
 stgSkillID_)
{
    id = id_;
    name = name_;
    texUrl = texUrl_;
    deputyID = deputyID_;
    itemIDs = itemIDs_;
    itemCounts = itemCounts_;
    isSltItemRqr = isSltItemRqr_;
    addiItemIDs = addiItemIDs_;
    addItemCounts = addItemCounts_;
    randomItems = randomItems_;
    targetItemID = targetItemID_;
    targetItemCount = targetItemCount_;
    requiredItemID = requiredItemID_;
    deputyLevel = deputyLevel_;
    description = description_;
    orangeLevel = orangeLevel_;
    yellowLevel = yellowLevel_;
    greenLevel = greenLevel_;
    money = money_;
    subDeputyID = subDeputyID_;
    stgPart = stgPart_;
    costTime = costTime_;
    stgPropIDs = stgPropIDs_;
    stgPropValues = stgPropValues_;
    stgSkillID = stgSkillID_;
}

DeputySkillConfig::~DeputySkillConfig()
{
    delete[] itemIDs;
    delete[] itemCounts;
    delete[] addiItemIDs;
    delete[] addItemCounts;
    delete[] randomItems;
    delete[] stgPart;
    delete[] stgPropIDs;
    delete[] stgPropValues;
}
    
void DeputySkillConfig::build()
{
    //std::string path = "./data/";
    //path += "DeputySkillConfig.bytes";
    std::string path = "DeputySkillConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "DeputySkillConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 25)
    {
        printf("col cnt invalid %d : %d", col_cnt, 25);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void DeputySkillConfig::add_item(StreamReader* rs)
{
    int arr_item_len_DeputySkillConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     texUrl_ =     
    rs->read_string();

    
    int
     deputyID_ =     
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     itemIDs_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        itemIDs_[i] =         
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     itemCounts_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        itemCounts_[i] =         
    rs->read_int();

    
    bool
     isSltItemRqr_ =     
    rs->read_bool();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     addiItemIDs_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        addiItemIDs_[i] =         
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     addItemCounts_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        addItemCounts_[i] =         
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    std::string



*     randomItems_ =     new 
    std::string



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        randomItems_[i] =         
    rs->read_string();

    
    int
     targetItemID_ =     
    rs->read_int();

    
    int
     targetItemCount_ =     
    rs->read_int();

    
    int
     requiredItemID_ =     
    rs->read_int();

    
    int
     deputyLevel_ =     
    rs->read_int();

    
    std::string
     description_ =     
    rs->read_string();

    
    int
     orangeLevel_ =     
    rs->read_int();

    
    int
     yellowLevel_ =     
    rs->read_int();

    
    int
     greenLevel_ =     
    rs->read_int();

    
    int
     money_ =     
    rs->read_int();

    
    int
     subDeputyID_ =     
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     stgPart_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        stgPart_[i] =         
    rs->read_int();

    
    int
     costTime_ =     
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     stgPropIDs_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        stgPropIDs_[i] =         
    rs->read_int();

    arr_item_len_DeputySkillConfig = rs->read_short();
    
    int



*     stgPropValues_ =     new 
    int



     [arr_item_len_DeputySkillConfig];

    for(int i = 0; i < arr_item_len_DeputySkillConfig; ++i)
        stgPropValues_[i] =         
    rs->read_int();

    
    int
     stgSkillID_ =     
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

    DeputySkillConfig* new_obj_DeputySkillConfig = new DeputySkillConfig(id_, name_, texUrl_, deputyID_, itemIDs_, itemCounts_, isSltItemRqr_, addiItemIDs_, addItemCounts_, randomItems_, targetItemID_, targetItemCount_, requiredItemID_, deputyLevel_, description_, orangeLevel_, yellowLevel_, greenLevel_, money_, subDeputyID_, stgPart_, costTime_, stgPropIDs_, stgPropValues_, stgSkillID_);

    dic[id_] = new_obj_DeputySkillConfig;
    list.push_back(new_obj_DeputySkillConfig);
}

void DeputySkillConfig::destroy()
{
    for(std::vector<DeputySkillConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
