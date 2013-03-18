









#include "StreamReader.h"
#include "HairConfig.h"

using namespace std;

std::map<int, HairConfig*> HairConfig::dic;
std::vector<HairConfig*> HairConfig::list;

HairConfig::HairConfig(
    int
 id_, 
    std::string
 hairMaleURL_, 
    std::string
 hairFemaleURL_)
{
    id = id_;
    hairMaleURL = hairMaleURL_;
    hairFemaleURL = hairFemaleURL_;
}

HairConfig::~HairConfig()
{
}
    
void HairConfig::build()
{
    //std::string path = "./data/";
    //path += "HairConfig.bytes";
    std::string path = "HairConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "HairConfig")
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

void HairConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     hairMaleURL_ =     
    rs->read_string();

    
    std::string
     hairFemaleURL_ =     
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

    HairConfig* new_obj_HairConfig = new HairConfig(id_, hairMaleURL_, hairFemaleURL_);

    dic[id_] = new_obj_HairConfig;
    list.push_back(new_obj_HairConfig);
}

void HairConfig::destroy()
{
    for(std::vector<HairConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
