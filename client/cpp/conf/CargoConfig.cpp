









#include "StreamReader.h"
#include "CargoConfig.h"

using namespace std;

std::map<int, CargoConfig*> CargoConfig::dic;
std::vector<CargoConfig*> CargoConfig::list;

CargoConfig::CargoConfig(
    int
 id_, 
    std::string
 name_, 
    int



* itemIDArr_,
    int



* itemLimitArr_,
    std::string



* prestigeLevelArr_,
    std::string



* priceArr_)
{
    id = id_;
    name = name_;
    itemIDArr = itemIDArr_;
    itemLimitArr = itemLimitArr_;
    prestigeLevelArr = prestigeLevelArr_;
    priceArr = priceArr_;
}

CargoConfig::~CargoConfig()
{
    delete[] itemIDArr;
    delete[] itemLimitArr;
    delete[] prestigeLevelArr;
    delete[] priceArr;
}
    
void CargoConfig::build()
{
    std::string path = "./data/";
    path += "CargoConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "CargoConfig")
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

void CargoConfig::add_item(StreamReader* rs)
{
    int arr_item_len_CargoConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    arr_item_len_CargoConfig = rs->read_short();
    
    int



*     itemIDArr_ =     new 
    int



     [arr_item_len_CargoConfig];

    for(int i = 0; i < arr_item_len_CargoConfig; ++i)
        itemIDArr_[i] =         
    rs->read_int();

    arr_item_len_CargoConfig = rs->read_short();
    
    int



*     itemLimitArr_ =     new 
    int



     [arr_item_len_CargoConfig];

    for(int i = 0; i < arr_item_len_CargoConfig; ++i)
        itemLimitArr_[i] =         
    rs->read_int();

    arr_item_len_CargoConfig = rs->read_short();
    
    std::string



*     prestigeLevelArr_ =     new 
    std::string



     [arr_item_len_CargoConfig];

    for(int i = 0; i < arr_item_len_CargoConfig; ++i)
        prestigeLevelArr_[i] =         
    rs->read_string();

    arr_item_len_CargoConfig = rs->read_short();
    
    std::string



*     priceArr_ =     new 
    std::string



     [arr_item_len_CargoConfig];

    for(int i = 0; i < arr_item_len_CargoConfig; ++i)
        priceArr_[i] =         
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

    CargoConfig* new_obj_CargoConfig = new CargoConfig(id_, name_, itemIDArr_, itemLimitArr_, prestigeLevelArr_, priceArr_);

    dic[id_] = new_obj_CargoConfig;
    list.push_back(new_obj_CargoConfig);
}

void CargoConfig::destroy()
{
    for(std::vector<CargoConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
