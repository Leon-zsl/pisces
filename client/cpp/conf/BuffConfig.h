





#include <map>
#include <vector>
#include <string>

class StreamReader;
class BuffConfig
{
public:
    static std::map<int, BuffConfig*> dic;
    static std::vector<BuffConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    BuffConfig(
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




 * destoryCondition_
);
    ~BuffConfig();

    
    int

 id;
    
    std::string

 name;
    
    std::string

 iconUrl;
    
    std::string




 * replacedAnimUrl;
    
    std::string




 * animationUrl;
    
    std::string

 headEffectUrl;
    
    std::string

 effectUrl;
    
    std::string

 description;
    
    int

 buffType;
    
    int

 stackLimit;
    
    int




 * buffPropType;
    
    float




 * buffPropValueA;
    
    float




 * buffPropValueB;
    
    float




 * buffPropValueC;
    
    int

 dotPropType;
    
    int

 dotType;
    
    float

 dotDamageA;
    
    float

 dotDamageB;
    
    float

 dotDamageC;
    
    float

 dotDamageD;
    
    float

 dotDamageE;
    
    float

 dotDamageF;
    
    int

 dotDuration;
    
    int




 * immuneBuffTypeArr;
    
    int




 * immuneSkillTypeArr;
    
    float

 damageReduceMaxA;
    
    float

 damageReduceMaxB;
    
    float

 damageReduceMaxC;
    
    float

 damageReduceMaxD;
    
    int

 buffReturn;
    
    int

 buffEx;
    
    int

 actorState;
    
    int




 * destoryCondition;
};
