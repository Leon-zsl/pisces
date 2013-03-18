









#include "StreamReader.h"
#include "CollectionConfig.h"

using namespace std;

std::map<int, CollectionConfig*> CollectionConfig::dic;
std::vector<CollectionConfig*> CollectionConfig::list;

CollectionConfig::CollectionConfig(
    int
 id_, 
    std::string
 name_, 
    float
 length_, 
    float
 width_, 
    int
 type_, 
    std::string
 description_, 
    std::string



* resUrl_,
    int
 refreshSecond_, 
    int



* prodItemIDs_,
    int



* rdItemIDs_,
    std::string



* rdItemCounts_,
    int



* prodItemCountLimit_,
    int
 requiredSkillID_, 
    int
 skillLevel_, 
    int
 costItemID_, 
    int
 costItemCount_, 
    int



* periods_,
    std::string



* products_,
    int
 text_)
{
    id = id_;
    name = name_;
    length = length_;
    width = width_;
    type = type_;
    description = description_;
    resUrl = resUrl_;
    refreshSecond = refreshSecond_;
    prodItemIDs = prodItemIDs_;
    rdItemIDs = rdItemIDs_;
    rdItemCounts = rdItemCounts_;
    prodItemCountLimit = prodItemCountLimit_;
    requiredSkillID = requiredSkillID_;
    skillLevel = skillLevel_;
    costItemID = costItemID_;
    costItemCount = costItemCount_;
    periods = periods_;
    products = products_;
    text = text_;
}

CollectionConfig::~CollectionConfig()
{
    delete[] resUrl;
    delete[] prodItemIDs;
    delete[] rdItemIDs;
    delete[] rdItemCounts;
    delete[] prodItemCountLimit;
    delete[] periods;
    delete[] products;
}
    
void CollectionConfig::build()
{
    //std::string path = "./data/";
    //path += "CollectionConfig.bytes";
    std::string path = "CollectionConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "CollectionConfig")
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

void CollectionConfig::add_item(StreamReader* rs)
{
    int arr_item_len_CollectionConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    
    int
     type_ =     
    rs->read_int();

    
    std::string
     description_ =     
    rs->read_string();

    arr_item_len_CollectionConfig = rs->read_short();
    
    std::string



*     resUrl_ =     new 
    std::string



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        resUrl_[i] =         
    rs->read_string();

    
    int
     refreshSecond_ =     
    rs->read_int();

    arr_item_len_CollectionConfig = rs->read_short();
    
    int



*     prodItemIDs_ =     new 
    int



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        prodItemIDs_[i] =         
    rs->read_int();

    arr_item_len_CollectionConfig = rs->read_short();
    
    int



*     rdItemIDs_ =     new 
    int



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        rdItemIDs_[i] =         
    rs->read_int();

    arr_item_len_CollectionConfig = rs->read_short();
    
    std::string



*     rdItemCounts_ =     new 
    std::string



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        rdItemCounts_[i] =         
    rs->read_string();

    arr_item_len_CollectionConfig = rs->read_short();
    
    int



*     prodItemCountLimit_ =     new 
    int



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        prodItemCountLimit_[i] =         
    rs->read_int();

    
    int
     requiredSkillID_ =     
    rs->read_int();

    
    int
     skillLevel_ =     
    rs->read_int();

    
    int
     costItemID_ =     
    rs->read_int();

    
    int
     costItemCount_ =     
    rs->read_int();

    arr_item_len_CollectionConfig = rs->read_short();
    
    int



*     periods_ =     new 
    int



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        periods_[i] =         
    rs->read_int();

    arr_item_len_CollectionConfig = rs->read_short();
    
    std::string



*     products_ =     new 
    std::string



     [arr_item_len_CollectionConfig];

    for(int i = 0; i < arr_item_len_CollectionConfig; ++i)
        products_[i] =         
    rs->read_string();

    
    int
     text_ =     
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

    CollectionConfig* new_obj_CollectionConfig = new CollectionConfig(id_, name_, length_, width_, type_, description_, resUrl_, refreshSecond_, prodItemIDs_, rdItemIDs_, rdItemCounts_, prodItemCountLimit_, requiredSkillID_, skillLevel_, costItemID_, costItemCount_, periods_, products_, text_);

    dic[id_] = new_obj_CollectionConfig;
    list.push_back(new_obj_CollectionConfig);
}

void CollectionConfig::destroy()
{
    for(std::vector<CollectionConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
