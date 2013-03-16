





#include <map>
#include <vector>
#include <string>

class StreamReader;
class TalentConfig
{
public:
    static std::map<int, TalentConfig*> dic;
    static std::vector<TalentConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    TalentConfig(
    int

 id_,

    std::string

 name_,

    int

 attPropType_,

    int

 jobID_,

    int

 consumeType_,

    int

 attackSkillID_,

    int




 * initSkillIDArr_,

    int




 * skillIDArr_,

    int




 * weaponType1Arr_,

    int




 * weaponType2Arr_,

    int




 * weaponType3Arr_
);
    ~TalentConfig();

    
    int

 id;
    
    std::string

 name;
    
    int

 attPropType;
    
    int

 jobID;
    
    int

 consumeType;
    
    int

 attackSkillID;
    
    int




 * initSkillIDArr;
    
    int




 * skillIDArr;
    
    int




 * weaponType1Arr;
    
    int




 * weaponType2Arr;
    
    int




 * weaponType3Arr;
};
