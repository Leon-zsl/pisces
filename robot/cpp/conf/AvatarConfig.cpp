









#include "StreamReader.h"
#include "AvatarConfig.h"

using namespace std;

std::map<int, AvatarConfig*> AvatarConfig::dic;
std::vector<AvatarConfig*> AvatarConfig::list;

AvatarConfig::AvatarConfig(
    int
 id_, 
    std::string
 hair_, 
    std::string
 face_, 
    std::string
 trunk_, 
    std::string
 waist_, 
    std::string
 l_arm_, 
    std::string
 r_arm_, 
    std::string
 l_palm_, 
    std::string
 r_palm_, 
    std::string
 l_leg_, 
    std::string
 r_leg_, 
    std::string
 l_feed_, 
    std::string
 r_feed_, 
    std::string
 l_shoes_, 
    std::string
 r_shoes_, 
    std::string
 effect_, 
    std::string
 other1_, 
    std::string
 other2_)
{
    id = id_;
    hair = hair_;
    face = face_;
    trunk = trunk_;
    waist = waist_;
    l_arm = l_arm_;
    r_arm = r_arm_;
    l_palm = l_palm_;
    r_palm = r_palm_;
    l_leg = l_leg_;
    r_leg = r_leg_;
    l_feed = l_feed_;
    r_feed = r_feed_;
    l_shoes = l_shoes_;
    r_shoes = r_shoes_;
    effect = effect_;
    other1 = other1_;
    other2 = other2_;
}

AvatarConfig::~AvatarConfig()
{
}
    
void AvatarConfig::build()
{
    //std::string path = "./data/";
    //path += "AvatarConfig.bytes";
    std::string path = "AvatarConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "AvatarConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 18)
    {
        printf("col cnt invalid %d : %d", col_cnt, 18);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void AvatarConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     hair_ =     
    rs->read_string();

    
    std::string
     face_ =     
    rs->read_string();

    
    std::string
     trunk_ =     
    rs->read_string();

    
    std::string
     waist_ =     
    rs->read_string();

    
    std::string
     l_arm_ =     
    rs->read_string();

    
    std::string
     r_arm_ =     
    rs->read_string();

    
    std::string
     l_palm_ =     
    rs->read_string();

    
    std::string
     r_palm_ =     
    rs->read_string();

    
    std::string
     l_leg_ =     
    rs->read_string();

    
    std::string
     r_leg_ =     
    rs->read_string();

    
    std::string
     l_feed_ =     
    rs->read_string();

    
    std::string
     r_feed_ =     
    rs->read_string();

    
    std::string
     l_shoes_ =     
    rs->read_string();

    
    std::string
     r_shoes_ =     
    rs->read_string();

    
    std::string
     effect_ =     
    rs->read_string();

    
    std::string
     other1_ =     
    rs->read_string();

    
    std::string
     other2_ =     
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

    AvatarConfig* new_obj_AvatarConfig = new AvatarConfig(id_, hair_, face_, trunk_, waist_, l_arm_, r_arm_, l_palm_, r_palm_, l_leg_, r_leg_, l_feed_, r_feed_, l_shoes_, r_shoes_, effect_, other1_, other2_);

    dic[id_] = new_obj_AvatarConfig;
    list.push_back(new_obj_AvatarConfig);
}

void AvatarConfig::destroy()
{
    for(std::vector<AvatarConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
