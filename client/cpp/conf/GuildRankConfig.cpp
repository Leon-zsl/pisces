









#include "StreamReader.h"
#include "GuildRankConfig.h"

using namespace std;

std::map<int, GuildRankConfig*> GuildRankConfig::dic;
std::vector<GuildRankConfig*> GuildRankConfig::list;

GuildRankConfig::GuildRankConfig(
    int
 id_, 
    std::string
 name_, 
    int



* rights_)
{
    id = id_;
    name = name_;
    rights = rights_;
}

GuildRankConfig::~GuildRankConfig()
{
    delete[] rights;
}
    
void GuildRankConfig::build()
{
    std::string path = "./data/";
    path += "GuildRankConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "GuildRankConfig")
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

void GuildRankConfig::add_item(StreamReader* rs)
{
    int arr_item_len_GuildRankConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    arr_item_len_GuildRankConfig = rs->read_short();
    
    int



*     rights_ =     new 
    int



     [arr_item_len_GuildRankConfig];

    for(int i = 0; i < arr_item_len_GuildRankConfig; ++i)
        rights_[i] =         
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

    GuildRankConfig* new_obj_GuildRankConfig = new GuildRankConfig(id_, name_, rights_);

    dic[id_] = new_obj_GuildRankConfig;
    list.push_back(new_obj_GuildRankConfig);
}

void GuildRankConfig::destroy()
{
    for(std::vector<GuildRankConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
