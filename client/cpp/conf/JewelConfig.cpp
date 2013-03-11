









#include "StreamReader.h"
#include "JewelConfig.h"

using namespace std;

std::map<int, JewelConfig*> JewelConfig::dic;
std::vector<JewelConfig*> JewelConfig::list;

JewelConfig::JewelConfig(
    int
 id_, 
    std::string
 name_, 
    int



* equipParts_,
    int



* stgPropIDs_,
    int



* strgPropValues_,
    int
 equipLevelEffect_)
{
    id = id_;
    name = name_;
    equipParts = equipParts_;
    stgPropIDs = stgPropIDs_;
    strgPropValues = strgPropValues_;
    equipLevelEffect = equipLevelEffect_;
}

JewelConfig::~JewelConfig()
{
    delete[] equipParts;
    delete[] stgPropIDs;
    delete[] strgPropValues;
}
    
void JewelConfig::build()
{
    std::string path = "./data/";
    path += "JewelConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "JewelConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 6)
    {
        printf("col cnt invalid %d : %d", col_cnt, 6);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void JewelConfig::add_item(StreamReader* rs)
{
    int arr_item_len_JewelConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    arr_item_len_JewelConfig = rs->read_short();
    
    int



*     equipParts_ =     new 
    int



     [arr_item_len_JewelConfig];

    for(int i = 0; i < arr_item_len_JewelConfig; ++i)
        equipParts_[i] =         
    rs->read_int();

    arr_item_len_JewelConfig = rs->read_short();
    
    int



*     stgPropIDs_ =     new 
    int



     [arr_item_len_JewelConfig];

    for(int i = 0; i < arr_item_len_JewelConfig; ++i)
        stgPropIDs_[i] =         
    rs->read_int();

    arr_item_len_JewelConfig = rs->read_short();
    
    int



*     strgPropValues_ =     new 
    int



     [arr_item_len_JewelConfig];

    for(int i = 0; i < arr_item_len_JewelConfig; ++i)
        strgPropValues_[i] =         
    rs->read_int();

    
    int
     equipLevelEffect_ =     
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

    JewelConfig* new_obj_JewelConfig = new JewelConfig(id_, name_, equipParts_, stgPropIDs_, strgPropValues_, equipLevelEffect_);

    dic[id_] = new_obj_JewelConfig;
    list.push_back(new_obj_JewelConfig);
}

void JewelConfig::destroy()
{
    for(std::vector<JewelConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
