









#include "StreamReader.h"
#include "GuildConfig.h"

using namespace std;

std::map<int, GuildConfig*> GuildConfig::dic;
std::vector<GuildConfig*> GuildConfig::list;

GuildConfig::GuildConfig(
    int
 id_, 
    int
 memberCapicity_)
{
    id = id_;
    memberCapicity = memberCapicity_;
}

GuildConfig::~GuildConfig()
{
}
    
void GuildConfig::build()
{
    //std::string path = "./data/";
    //path += "GuildConfig.bytes";
    std::string path = "GuildConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "GuildConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 2)
    {
        printf("col cnt invalid %d : %d", col_cnt, 2);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void GuildConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    int
     memberCapicity_ =     
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

    GuildConfig* new_obj_GuildConfig = new GuildConfig(id_, memberCapicity_);

    dic[id_] = new_obj_GuildConfig;
    list.push_back(new_obj_GuildConfig);
}

void GuildConfig::destroy()
{
    for(std::vector<GuildConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
