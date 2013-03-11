









#include "StreamReader.h"
#include "SkillConfig.h"

using namespace std;

std::map<int, SkillConfig*> SkillConfig::dic;
std::vector<SkillConfig*> SkillConfig::list;

SkillConfig::SkillConfig(
    int
 id_, 
    int
 exSkillID_, 
    std::string
 name_, 
    std::string
 iconUrl_, 
    std::string
 animUrl_, 
    std::string
 preAnimUrl_, 
    std::string
 preAnimEffectUrl_, 
    std::string
 bulletEffect_, 
    std::string
 trapTriggerEffect_, 
    std::string
 behitEffect_, 
    std::string
 description_, 
    int
 propType_, 
    int
 skillFlag_, 
    int
 effectType_, 
    bool
 useGlobalCD_, 
    int
 targetFlag_, 
    int
 consumeType_, 
    float
 consumeA_, 
    float
 consumeB_, 
    float
 consumeC_, 
    float
 consumeD_, 
    int
 coolDown_, 
    int
 castType_, 
    long long
 singDuration_, 
    long long
 duration_, 
    int
 effectCount_, 
    float
 rangeMin_, 
    float
 rangeMax_, 
    float
 effectWidth_, 
    int
 buffRequireID_, 
    int
 buffCost_, 
    int



* buffSelfID_,
    float



* buffSelfRate_,
    int



* buffSelfCount_,
    long long



* buffSelfIntervel_,
    int



* buffTargetID_,
    float



* buffTargetRate_,
    int



* buffTargetCount_,
    long long



* buffTargetInterval_,
    int



* buffRemoveTypeArr_,
    float
 chargeSpeed_, 
    float
 chargeOffset_, 
    int
 damageType_, 
    float
 damageA_, 
    float
 damageB_, 
    float
 damageC_, 
    float
 damageD_, 
    float
 damageE_, 
    float
 damageF_, 
    float
 vampireRate_, 
    int
 upgradeType_, 
    int
 upgradeCost_, 
    int
 requireLevel_, 
    int
 requireSkillID_, 
    int
 talentID_)
{
    id = id_;
    exSkillID = exSkillID_;
    name = name_;
    iconUrl = iconUrl_;
    animUrl = animUrl_;
    preAnimUrl = preAnimUrl_;
    preAnimEffectUrl = preAnimEffectUrl_;
    bulletEffect = bulletEffect_;
    trapTriggerEffect = trapTriggerEffect_;
    behitEffect = behitEffect_;
    description = description_;
    propType = propType_;
    skillFlag = skillFlag_;
    effectType = effectType_;
    useGlobalCD = useGlobalCD_;
    targetFlag = targetFlag_;
    consumeType = consumeType_;
    consumeA = consumeA_;
    consumeB = consumeB_;
    consumeC = consumeC_;
    consumeD = consumeD_;
    coolDown = coolDown_;
    castType = castType_;
    singDuration = singDuration_;
    duration = duration_;
    effectCount = effectCount_;
    rangeMin = rangeMin_;
    rangeMax = rangeMax_;
    effectWidth = effectWidth_;
    buffRequireID = buffRequireID_;
    buffCost = buffCost_;
    buffSelfID = buffSelfID_;
    buffSelfRate = buffSelfRate_;
    buffSelfCount = buffSelfCount_;
    buffSelfIntervel = buffSelfIntervel_;
    buffTargetID = buffTargetID_;
    buffTargetRate = buffTargetRate_;
    buffTargetCount = buffTargetCount_;
    buffTargetInterval = buffTargetInterval_;
    buffRemoveTypeArr = buffRemoveTypeArr_;
    chargeSpeed = chargeSpeed_;
    chargeOffset = chargeOffset_;
    damageType = damageType_;
    damageA = damageA_;
    damageB = damageB_;
    damageC = damageC_;
    damageD = damageD_;
    damageE = damageE_;
    damageF = damageF_;
    vampireRate = vampireRate_;
    upgradeType = upgradeType_;
    upgradeCost = upgradeCost_;
    requireLevel = requireLevel_;
    requireSkillID = requireSkillID_;
    talentID = talentID_;
}

SkillConfig::~SkillConfig()
{
    delete[] buffSelfID;
    delete[] buffSelfRate;
    delete[] buffSelfCount;
    delete[] buffSelfIntervel;
    delete[] buffTargetID;
    delete[] buffTargetRate;
    delete[] buffTargetCount;
    delete[] buffTargetInterval;
    delete[] buffRemoveTypeArr;
}
    
void SkillConfig::build()
{
    std::string path = "./data/";
    path += "SkillConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "SkillConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 55)
    {
        printf("col cnt invalid %d : %d", col_cnt, 55);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void SkillConfig::add_item(StreamReader* rs)
{
    int arr_item_len_SkillConfig;

    
    int
     id_ =     
    rs->read_int();

    
    int
     exSkillID_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     iconUrl_ =     
    rs->read_string();

    
    std::string
     animUrl_ =     
    rs->read_string();

    
    std::string
     preAnimUrl_ =     
    rs->read_string();

    
    std::string
     preAnimEffectUrl_ =     
    rs->read_string();

    
    std::string
     bulletEffect_ =     
    rs->read_string();

    
    std::string
     trapTriggerEffect_ =     
    rs->read_string();

    
    std::string
     behitEffect_ =     
    rs->read_string();

    
    std::string
     description_ =     
    rs->read_string();

    
    int
     propType_ =     
    rs->read_int();

    
    int
     skillFlag_ =     
    rs->read_int();

    
    int
     effectType_ =     
    rs->read_int();

    
    bool
     useGlobalCD_ =     
    rs->read_bool();

    
    int
     targetFlag_ =     
    rs->read_int();

    
    int
     consumeType_ =     
    rs->read_int();

    
    float
     consumeA_ =     
    rs->read_float();

    
    float
     consumeB_ =     
    rs->read_float();

    
    float
     consumeC_ =     
    rs->read_float();

    
    float
     consumeD_ =     
    rs->read_float();

    
    int
     coolDown_ =     
    rs->read_int();

    
    int
     castType_ =     
    rs->read_int();

    
    long long
     singDuration_ =     
    rs->read_long();

    
    long long
     duration_ =     
    rs->read_long();

    
    int
     effectCount_ =     
    rs->read_int();

    
    float
     rangeMin_ =     
    rs->read_float();

    
    float
     rangeMax_ =     
    rs->read_float();

    
    float
     effectWidth_ =     
    rs->read_float();

    
    int
     buffRequireID_ =     
    rs->read_int();

    
    int
     buffCost_ =     
    rs->read_int();

    arr_item_len_SkillConfig = rs->read_short();
    
    int



*     buffSelfID_ =     new 
    int



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffSelfID_[i] =         
    rs->read_int();

    arr_item_len_SkillConfig = rs->read_short();
    
    float



*     buffSelfRate_ =     new 
    float



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffSelfRate_[i] =         
    rs->read_float();

    arr_item_len_SkillConfig = rs->read_short();
    
    int



*     buffSelfCount_ =     new 
    int



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffSelfCount_[i] =         
    rs->read_int();

    arr_item_len_SkillConfig = rs->read_short();
    
    long long



*     buffSelfIntervel_ =     new 
    long long



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffSelfIntervel_[i] =         
    rs->read_long();

    arr_item_len_SkillConfig = rs->read_short();
    
    int



*     buffTargetID_ =     new 
    int



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffTargetID_[i] =         
    rs->read_int();

    arr_item_len_SkillConfig = rs->read_short();
    
    float



*     buffTargetRate_ =     new 
    float



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffTargetRate_[i] =         
    rs->read_float();

    arr_item_len_SkillConfig = rs->read_short();
    
    int



*     buffTargetCount_ =     new 
    int



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffTargetCount_[i] =         
    rs->read_int();

    arr_item_len_SkillConfig = rs->read_short();
    
    long long



*     buffTargetInterval_ =     new 
    long long



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffTargetInterval_[i] =         
    rs->read_long();

    arr_item_len_SkillConfig = rs->read_short();
    
    int



*     buffRemoveTypeArr_ =     new 
    int



     [arr_item_len_SkillConfig];

    for(int i = 0; i < arr_item_len_SkillConfig; ++i)
        buffRemoveTypeArr_[i] =         
    rs->read_int();

    
    float
     chargeSpeed_ =     
    rs->read_float();

    
    float
     chargeOffset_ =     
    rs->read_float();

    
    int
     damageType_ =     
    rs->read_int();

    
    float
     damageA_ =     
    rs->read_float();

    
    float
     damageB_ =     
    rs->read_float();

    
    float
     damageC_ =     
    rs->read_float();

    
    float
     damageD_ =     
    rs->read_float();

    
    float
     damageE_ =     
    rs->read_float();

    
    float
     damageF_ =     
    rs->read_float();

    
    float
     vampireRate_ =     
    rs->read_float();

    
    int
     upgradeType_ =     
    rs->read_int();

    
    int
     upgradeCost_ =     
    rs->read_int();

    
    int
     requireLevel_ =     
    rs->read_int();

    
    int
     requireSkillID_ =     
    rs->read_int();

    
    int
     talentID_ =     
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

    SkillConfig* new_obj_SkillConfig = new SkillConfig(id_, exSkillID_, name_, iconUrl_, animUrl_, preAnimUrl_, preAnimEffectUrl_, bulletEffect_, trapTriggerEffect_, behitEffect_, description_, propType_, skillFlag_, effectType_, useGlobalCD_, targetFlag_, consumeType_, consumeA_, consumeB_, consumeC_, consumeD_, coolDown_, castType_, singDuration_, duration_, effectCount_, rangeMin_, rangeMax_, effectWidth_, buffRequireID_, buffCost_, buffSelfID_, buffSelfRate_, buffSelfCount_, buffSelfIntervel_, buffTargetID_, buffTargetRate_, buffTargetCount_, buffTargetInterval_, buffRemoveTypeArr_, chargeSpeed_, chargeOffset_, damageType_, damageA_, damageB_, damageC_, damageD_, damageE_, damageF_, vampireRate_, upgradeType_, upgradeCost_, requireLevel_, requireSkillID_, talentID_);

    dic[id_] = new_obj_SkillConfig;
    list.push_back(new_obj_SkillConfig);
}

void SkillConfig::destroy()
{
    for(std::vector<SkillConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
