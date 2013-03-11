









#include "StreamReader.h"
#include "GuildRankRightsConfig.h"

using namespace std;

std::map<int, GuildRankRightsConfig*> GuildRankRightsConfig::dic;
std::vector<GuildRankRightsConfig*> GuildRankRightsConfig::list;

GuildRankRightsConfig::GuildRankRightsConfig(
    int
 id_, 
    int
 right_, 
    std::string
 desc_, 
    std::string



* npcArr_)
{
    id = id_;
    right = right_;
    desc = desc_;
    npcArr = npcArr_;
}

GuildRankRightsConfig::~GuildRankRightsConfig()
{
    delete[] npcArr;
}
    
void GuildRankRightsConfig::build()
{
    std::string path = "./data/";
    path += "GuildRankRightsConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "GuildRankRightsConfig")
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

void GuildRankRightsConfig::add_item(StreamReader* rs)
{
    int arr_item_len_GuildRankRightsConfig;

    
    int
     id_ =     
    rs->read_int();

    
    int
     right_ =     
    rs->read_int();

    
    std::string
     desc_ =     
    rs->read_string();

    arr_item_len_GuildRankRightsConfig = rs->read_short();
    
    std::string



*     npcArr_ =     new 
    std::string



     [arr_item_len_GuildRankRightsConfig];

    for(int i = 0; i < arr_item_len_GuildRankRightsConfig; ++i)
        npcArr_[i] =         
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

    GuildRankRightsConfig* new_obj_GuildRankRightsConfig = new GuildRankRightsConfig(id_, right_, desc_, npcArr_);

    dic[id_] = new_obj_GuildRankRightsConfig;
    list.push_back(new_obj_GuildRankRightsConfig);
}

void GuildRankRightsConfig::destroy()
{
    for(std::vector<GuildRankRightsConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
