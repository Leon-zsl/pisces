









#include "StreamReader.h"
#include "DisintegrateConfig.h"

using namespace std;

std::map<int, DisintegrateConfig*> DisintegrateConfig::dic;
std::vector<DisintegrateConfig*> DisintegrateConfig::list;

DisintegrateConfig::DisintegrateConfig(
    int
 id_, 
    int



* itemIDs_,
    std::string



* itemCounts_,
    int
 addItemIDs_)
{
    id = id_;
    itemIDs = itemIDs_;
    itemCounts = itemCounts_;
    addItemIDs = addItemIDs_;
}

DisintegrateConfig::~DisintegrateConfig()
{
    delete[] itemIDs;
    delete[] itemCounts;
}
    
void DisintegrateConfig::build()
{
    std::string path = "./data/";
    path += "DisintegrateConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "DisintegrateConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 4)
    {
        printf("col cnt invalid %d : %d", col_cnt, 4);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void DisintegrateConfig::add_item(StreamReader* rs)
{
    int arr_item_len_DisintegrateConfig;

    
    int
     id_ =     
    rs->read_int();

    arr_item_len_DisintegrateConfig = rs->read_short();
    
    int



*     itemIDs_ =     new 
    int



     [arr_item_len_DisintegrateConfig];

    for(int i = 0; i < arr_item_len_DisintegrateConfig; ++i)
        itemIDs_[i] =         
    rs->read_int();

    arr_item_len_DisintegrateConfig = rs->read_short();
    
    std::string



*     itemCounts_ =     new 
    std::string



     [arr_item_len_DisintegrateConfig];

    for(int i = 0; i < arr_item_len_DisintegrateConfig; ++i)
        itemCounts_[i] =         
    rs->read_string();

    
    int
     addItemIDs_ =     
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

    DisintegrateConfig* new_obj_DisintegrateConfig = new DisintegrateConfig(id_, itemIDs_, itemCounts_, addItemIDs_);

    dic[id_] = new_obj_DisintegrateConfig;
    list.push_back(new_obj_DisintegrateConfig);
}

void DisintegrateConfig::destroy()
{
    for(std::vector<DisintegrateConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
