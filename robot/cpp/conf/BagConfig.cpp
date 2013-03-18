









#include "StreamReader.h"
#include "BagConfig.h"

using namespace std;

std::map<int, BagConfig*> BagConfig::dic;
std::vector<BagConfig*> BagConfig::list;

BagConfig::BagConfig(
    int
 id_, 
    int
 bagType_, 
    int
 slotCount_)
{
    id = id_;
    bagType = bagType_;
    slotCount = slotCount_;
}

BagConfig::~BagConfig()
{
}
    
void BagConfig::build()
{
    //std::string path = "./data/";
    //path += "BagConfig.bytes";
    std::string path = "BagConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "BagConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 3)
    {
        printf("col cnt invalid %d : %d", col_cnt, 3);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void BagConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    int
     bagType_ =     
    rs->read_int();

    
    int
     slotCount_ =     
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

    BagConfig* new_obj_BagConfig = new BagConfig(id_, bagType_, slotCount_);

    dic[id_] = new_obj_BagConfig;
    list.push_back(new_obj_BagConfig);
}

void BagConfig::destroy()
{
    for(std::vector<BagConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
