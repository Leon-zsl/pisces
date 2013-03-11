









#include "StreamReader.h"
#include "SocialStatusConfig.h"

using namespace std;

std::map<int, SocialStatusConfig*> SocialStatusConfig::dic;
std::vector<SocialStatusConfig*> SocialStatusConfig::list;

SocialStatusConfig::SocialStatusConfig(
    int
 id_, 
    int
 statusId_, 
    std::string
 desc_)
{
    id = id_;
    statusId = statusId_;
    desc = desc_;
}

SocialStatusConfig::~SocialStatusConfig()
{
}
    
void SocialStatusConfig::build()
{
    //std::string path = "./data/";
    //path += "SocialStatusConfig.bytes";
    std::string path = "SocialStatusConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "SocialStatusConfig")
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

void SocialStatusConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    int
     statusId_ =     
    rs->read_int();

    
    std::string
     desc_ =     
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

    SocialStatusConfig* new_obj_SocialStatusConfig = new SocialStatusConfig(id_, statusId_, desc_);

    dic[id_] = new_obj_SocialStatusConfig;
    list.push_back(new_obj_SocialStatusConfig);
}

void SocialStatusConfig::destroy()
{
    for(std::vector<SocialStatusConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
