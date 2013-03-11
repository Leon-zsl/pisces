









#include "StreamReader.h"
#include "EffectConfig.h"

using namespace std;

std::map<int, EffectConfig*> EffectConfig::dic;
std::vector<EffectConfig*> EffectConfig::list;

EffectConfig::EffectConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 effectUrl_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    std::string
 direction_, 
    int
 target_, 
    int
 horStrength_, 
    int
 verStrength_, 
    int
 element_, 
    int
 elementValue_, 
    int
 selfBuffID_, 
    int
 targetBuffID_, 
    bool
 isFocus_, 
    bool
 invincible_, 
    bool
 isBindSkill_, 
    long long
 effectDuration_, 
    bool
 isCrossbody_)
{
    id = id_;
    name = name_;
    effectUrl = effectUrl_;
    length = length_;
    width = width_;
    height = height_;
    direction = direction_;
    target = target_;
    horStrength = horStrength_;
    verStrength = verStrength_;
    element = element_;
    elementValue = elementValue_;
    selfBuffID = selfBuffID_;
    targetBuffID = targetBuffID_;
    isFocus = isFocus_;
    invincible = invincible_;
    isBindSkill = isBindSkill_;
    effectDuration = effectDuration_;
    isCrossbody = isCrossbody_;
}

EffectConfig::~EffectConfig()
{
}
    
void EffectConfig::build()
{
    std::string path = "./data/";
    path += "EffectConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "EffectConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 19)
    {
        printf("col cnt invalid %d : %d", col_cnt, 19);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void EffectConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     effectUrl_ =     
    rs->read_string();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    
    float
     height_ =     
    rs->read_float();

    
    std::string
     direction_ =     
    rs->read_string();

    
    int
     target_ =     
    rs->read_int();

    
    int
     horStrength_ =     
    rs->read_int();

    
    int
     verStrength_ =     
    rs->read_int();

    
    int
     element_ =     
    rs->read_int();

    
    int
     elementValue_ =     
    rs->read_int();

    
    int
     selfBuffID_ =     
    rs->read_int();

    
    int
     targetBuffID_ =     
    rs->read_int();

    
    bool
     isFocus_ =     
    rs->read_bool();

    
    bool
     invincible_ =     
    rs->read_bool();

    
    bool
     isBindSkill_ =     
    rs->read_bool();

    
    long long
     effectDuration_ =     
    rs->read_long();

    
    bool
     isCrossbody_ =     
    rs->read_bool();

        
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

    EffectConfig* new_obj_EffectConfig = new EffectConfig(id_, name_, effectUrl_, length_, width_, height_, direction_, target_, horStrength_, verStrength_, element_, elementValue_, selfBuffID_, targetBuffID_, isFocus_, invincible_, isBindSkill_, effectDuration_, isCrossbody_);

    dic[id_] = new_obj_EffectConfig;
    list.push_back(new_obj_EffectConfig);
}

void EffectConfig::destroy()
{
    for(std::vector<EffectConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
