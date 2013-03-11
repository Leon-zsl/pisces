









#include "StreamReader.h"
#include "BuffConfig.h"

using namespace std;

std::map<int, BuffConfig*> BuffConfig::dic;
std::vector<BuffConfig*> BuffConfig::list;

BuffConfig::BuffConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 iconUrl_, 
    std::string



* replacedAnimUrl_,
    std::string



* animationUrl_,
    std::string
 headEffectUrl_, 
    std::string
 effectUrl_, 
    std::string
 description_, 
    int
 buffType_, 
    int
 stackLimit_, 
    int



* buffPropType_,
    float



* buffPropValueA_,
    float



* buffPropValueB_,
    float



* buffPropValueC_,
    int
 dotPropType_, 
    int
 dotType_, 
    float
 dotDamageA_, 
    float
 dotDamageB_, 
    float
 dotDamageC_, 
    float
 dotDamageD_, 
    float
 dotDamageE_, 
    float
 dotDamageF_, 
    int
 dotDuration_, 
    int



* immuneBuffTypeArr_,
    int



* immuneSkillTypeArr_,
    float
 damageReduceMaxA_, 
    float
 damageReduceMaxB_, 
    float
 damageReduceMaxC_, 
    float
 damageReduceMaxD_, 
    int
 buffReturn_, 
    int
 buffEx_, 
    int
 actorState_, 
    int



* destoryCondition_)
{
    id = id_;
    name = name_;
    iconUrl = iconUrl_;
    replacedAnimUrl = replacedAnimUrl_;
    animationUrl = animationUrl_;
    headEffectUrl = headEffectUrl_;
    effectUrl = effectUrl_;
    description = description_;
    buffType = buffType_;
    stackLimit = stackLimit_;
    buffPropType = buffPropType_;
    buffPropValueA = buffPropValueA_;
    buffPropValueB = buffPropValueB_;
    buffPropValueC = buffPropValueC_;
    dotPropType = dotPropType_;
    dotType = dotType_;
    dotDamageA = dotDamageA_;
    dotDamageB = dotDamageB_;
    dotDamageC = dotDamageC_;
    dotDamageD = dotDamageD_;
    dotDamageE = dotDamageE_;
    dotDamageF = dotDamageF_;
    dotDuration = dotDuration_;
    immuneBuffTypeArr = immuneBuffTypeArr_;
    immuneSkillTypeArr = immuneSkillTypeArr_;
    damageReduceMaxA = damageReduceMaxA_;
    damageReduceMaxB = damageReduceMaxB_;
    damageReduceMaxC = damageReduceMaxC_;
    damageReduceMaxD = damageReduceMaxD_;
    buffReturn = buffReturn_;
    buffEx = buffEx_;
    actorState = actorState_;
    destoryCondition = destoryCondition_;
}

BuffConfig::~BuffConfig()
{
    delete[] replacedAnimUrl;
    delete[] animationUrl;
    delete[] buffPropType;
    delete[] buffPropValueA;
    delete[] buffPropValueB;
    delete[] buffPropValueC;
    delete[] immuneBuffTypeArr;
    delete[] immuneSkillTypeArr;
    delete[] destoryCondition;
}
    
void BuffConfig::build()
{
    std::string path = "./data/";
    path += "BuffConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "BuffConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 33)
    {
        printf("col cnt invalid %d : %d", col_cnt, 33);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void BuffConfig::add_item(StreamReader* rs)
{
    int arr_item_len_BuffConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     iconUrl_ =     
    rs->read_string();

    arr_item_len_BuffConfig = rs->read_short();
    
    std::string



*     replacedAnimUrl_ =     new 
    std::string



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        replacedAnimUrl_[i] =         
    rs->read_string();

    arr_item_len_BuffConfig = rs->read_short();
    
    std::string



*     animationUrl_ =     new 
    std::string



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        animationUrl_[i] =         
    rs->read_string();

    
    std::string
     headEffectUrl_ =     
    rs->read_string();

    
    std::string
     effectUrl_ =     
    rs->read_string();

    
    std::string
     description_ =     
    rs->read_string();

    
    int
     buffType_ =     
    rs->read_int();

    
    int
     stackLimit_ =     
    rs->read_int();

    arr_item_len_BuffConfig = rs->read_short();
    
    int



*     buffPropType_ =     new 
    int



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        buffPropType_[i] =         
    rs->read_int();

    arr_item_len_BuffConfig = rs->read_short();
    
    float



*     buffPropValueA_ =     new 
    float



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        buffPropValueA_[i] =         
    rs->read_float();

    arr_item_len_BuffConfig = rs->read_short();
    
    float



*     buffPropValueB_ =     new 
    float



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        buffPropValueB_[i] =         
    rs->read_float();

    arr_item_len_BuffConfig = rs->read_short();
    
    float



*     buffPropValueC_ =     new 
    float



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        buffPropValueC_[i] =         
    rs->read_float();

    
    int
     dotPropType_ =     
    rs->read_int();

    
    int
     dotType_ =     
    rs->read_int();

    
    float
     dotDamageA_ =     
    rs->read_float();

    
    float
     dotDamageB_ =     
    rs->read_float();

    
    float
     dotDamageC_ =     
    rs->read_float();

    
    float
     dotDamageD_ =     
    rs->read_float();

    
    float
     dotDamageE_ =     
    rs->read_float();

    
    float
     dotDamageF_ =     
    rs->read_float();

    
    int
     dotDuration_ =     
    rs->read_int();

    arr_item_len_BuffConfig = rs->read_short();
    
    int



*     immuneBuffTypeArr_ =     new 
    int



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        immuneBuffTypeArr_[i] =         
    rs->read_int();

    arr_item_len_BuffConfig = rs->read_short();
    
    int



*     immuneSkillTypeArr_ =     new 
    int



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        immuneSkillTypeArr_[i] =         
    rs->read_int();

    
    float
     damageReduceMaxA_ =     
    rs->read_float();

    
    float
     damageReduceMaxB_ =     
    rs->read_float();

    
    float
     damageReduceMaxC_ =     
    rs->read_float();

    
    float
     damageReduceMaxD_ =     
    rs->read_float();

    
    int
     buffReturn_ =     
    rs->read_int();

    
    int
     buffEx_ =     
    rs->read_int();

    
    int
     actorState_ =     
    rs->read_int();

    arr_item_len_BuffConfig = rs->read_short();
    
    int



*     destoryCondition_ =     new 
    int



     [arr_item_len_BuffConfig];

    for(int i = 0; i < arr_item_len_BuffConfig; ++i)
        destoryCondition_[i] =         
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

    BuffConfig* new_obj_BuffConfig = new BuffConfig(id_, name_, iconUrl_, replacedAnimUrl_, animationUrl_, headEffectUrl_, effectUrl_, description_, buffType_, stackLimit_, buffPropType_, buffPropValueA_, buffPropValueB_, buffPropValueC_, dotPropType_, dotType_, dotDamageA_, dotDamageB_, dotDamageC_, dotDamageD_, dotDamageE_, dotDamageF_, dotDuration_, immuneBuffTypeArr_, immuneSkillTypeArr_, damageReduceMaxA_, damageReduceMaxB_, damageReduceMaxC_, damageReduceMaxD_, buffReturn_, buffEx_, actorState_, destoryCondition_);

    dic[id_] = new_obj_BuffConfig;
    list.push_back(new_obj_BuffConfig);
}

void BuffConfig::destroy()
{
    for(std::vector<BuffConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
