









#include "StreamReader.h"
#include "FactionConfig.h"

using namespace std;

std::map<int, FactionConfig*> FactionConfig::dic;
std::vector<FactionConfig*> FactionConfig::list;

FactionConfig::FactionConfig(
    int
 id_, 
    std::string
 name_, 
    int



* prestigeLevelArr_,
    int



* prestigeArr_,
    std::string



* prestigeNameArr_)
{
    id = id_;
    name = name_;
    prestigeLevelArr = prestigeLevelArr_;
    prestigeArr = prestigeArr_;
    prestigeNameArr = prestigeNameArr_;
}

FactionConfig::~FactionConfig()
{
    delete[] prestigeLevelArr;
    delete[] prestigeArr;
    delete[] prestigeNameArr;
}
    
void FactionConfig::build()
{
    //std::string path = "./data/";
    //path += "FactionConfig.bytes";
    std::string path = "FactionConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "FactionConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 5)
    {
        printf("col cnt invalid %d : %d", col_cnt, 5);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void FactionConfig::add_item(StreamReader* rs)
{
    int arr_item_len_FactionConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    arr_item_len_FactionConfig = rs->read_short();
    
    int



*     prestigeLevelArr_ =     new 
    int



     [arr_item_len_FactionConfig];

    for(int i = 0; i < arr_item_len_FactionConfig; ++i)
        prestigeLevelArr_[i] =         
    rs->read_int();

    arr_item_len_FactionConfig = rs->read_short();
    
    int



*     prestigeArr_ =     new 
    int



     [arr_item_len_FactionConfig];

    for(int i = 0; i < arr_item_len_FactionConfig; ++i)
        prestigeArr_[i] =         
    rs->read_int();

    arr_item_len_FactionConfig = rs->read_short();
    
    std::string



*     prestigeNameArr_ =     new 
    std::string



     [arr_item_len_FactionConfig];

    for(int i = 0; i < arr_item_len_FactionConfig; ++i)
        prestigeNameArr_[i] =         
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

    FactionConfig* new_obj_FactionConfig = new FactionConfig(id_, name_, prestigeLevelArr_, prestigeArr_, prestigeNameArr_);

    dic[id_] = new_obj_FactionConfig;
    list.push_back(new_obj_FactionConfig);
}

void FactionConfig::destroy()
{
    for(std::vector<FactionConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
