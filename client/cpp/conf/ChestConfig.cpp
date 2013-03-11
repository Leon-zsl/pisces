









#include "StreamReader.h"
#include "ChestConfig.h"

using namespace std;

std::map<int, ChestConfig*> ChestConfig::dic;
std::vector<ChestConfig*> ChestConfig::list;

ChestConfig::ChestConfig(
    int
 id_, 
    std::string
 name_, 
    bool
 isFixedBonus_, 
    int



* itemIDArr_,
    int



* itemRateArr_,
    int
 keyItemID_)
{
    id = id_;
    name = name_;
    isFixedBonus = isFixedBonus_;
    itemIDArr = itemIDArr_;
    itemRateArr = itemRateArr_;
    keyItemID = keyItemID_;
}

ChestConfig::~ChestConfig()
{
    delete[] itemIDArr;
    delete[] itemRateArr;
}
    
void ChestConfig::build()
{
    std::string path = "./data/";
    path += "ChestConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "ChestConfig")
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

void ChestConfig::add_item(StreamReader* rs)
{
    int arr_item_len_ChestConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    bool
     isFixedBonus_ =     
    rs->read_bool();

    arr_item_len_ChestConfig = rs->read_short();
    
    int



*     itemIDArr_ =     new 
    int



     [arr_item_len_ChestConfig];

    for(int i = 0; i < arr_item_len_ChestConfig; ++i)
        itemIDArr_[i] =         
    rs->read_int();

    arr_item_len_ChestConfig = rs->read_short();
    
    int



*     itemRateArr_ =     new 
    int



     [arr_item_len_ChestConfig];

    for(int i = 0; i < arr_item_len_ChestConfig; ++i)
        itemRateArr_[i] =         
    rs->read_int();

    
    int
     keyItemID_ =     
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

    ChestConfig* new_obj_ChestConfig = new ChestConfig(id_, name_, isFixedBonus_, itemIDArr_, itemRateArr_, keyItemID_);

    dic[id_] = new_obj_ChestConfig;
    list.push_back(new_obj_ChestConfig);
}

void ChestConfig::destroy()
{
    for(std::vector<ChestConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
