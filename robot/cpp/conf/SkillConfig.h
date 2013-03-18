





#include <map>
#include <vector>
#include <string>

class StreamReader;
class SkillConfig
{
public:
    static std::map<int, SkillConfig*> dic;
    static std::vector<SkillConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    SkillConfig(
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

 talentID_
);
    ~SkillConfig();

    
    int

 id;
    
    int

 exSkillID;
    
    std::string

 name;
    
    std::string

 iconUrl;
    
    std::string

 animUrl;
    
    std::string

 preAnimUrl;
    
    std::string

 preAnimEffectUrl;
    
    std::string

 bulletEffect;
    
    std::string

 trapTriggerEffect;
    
    std::string

 behitEffect;
    
    std::string

 description;
    
    int

 propType;
    
    int

 skillFlag;
    
    int

 effectType;
    
    bool

 useGlobalCD;
    
    int

 targetFlag;
    
    int

 consumeType;
    
    float

 consumeA;
    
    float

 consumeB;
    
    float

 consumeC;
    
    float

 consumeD;
    
    int

 coolDown;
    
    int

 castType;
    
    long long

 singDuration;
    
    long long

 duration;
    
    int

 effectCount;
    
    float

 rangeMin;
    
    float

 rangeMax;
    
    float

 effectWidth;
    
    int

 buffRequireID;
    
    int

 buffCost;
    
    int




 * buffSelfID;
    
    float




 * buffSelfRate;
    
    int




 * buffSelfCount;
    
    long long




 * buffSelfIntervel;
    
    int




 * buffTargetID;
    
    float




 * buffTargetRate;
    
    int




 * buffTargetCount;
    
    long long




 * buffTargetInterval;
    
    int




 * buffRemoveTypeArr;
    
    float

 chargeSpeed;
    
    float

 chargeOffset;
    
    int

 damageType;
    
    float

 damageA;
    
    float

 damageB;
    
    float

 damageC;
    
    float

 damageD;
    
    float

 damageE;
    
    float

 damageF;
    
    float

 vampireRate;
    
    int

 upgradeType;
    
    int

 upgradeCost;
    
    int

 requireLevel;
    
    int

 requireSkillID;
    
    int

 talentID;
};
