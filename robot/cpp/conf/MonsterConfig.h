





#include <map>
#include <vector>
#include <string>

class StreamReader;
class MonsterConfig
{
public:
    static std::map<int, MonsterConfig*> dic;
    static std::vector<MonsterConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    MonsterConfig(
    int

 id_,

    std::string

 name_,

    int

 type_,

    int

 propID_,

    int

 figureID_,

    float

 numInt_,

    int

 refreshSecond_,

    int




 * skillIDArr_,

    int




 * itemIDArr_,

    double




 * itemRateArr_,

    int




 * missionItem_,

    float

 sight_,

    float

 attackRange_,

    int

 attackSkillID_,

    std::string




 * healthAIArr_,

    std::string




 * manaAIArr_,

    std::string




 * furyAIArr_,

    std::string




 * energyAIArr_,

    bool

 isPeeled_,

    bool

 cannotMove_
);
    ~MonsterConfig();

    
    int

 id;
    
    std::string

 name;
    
    int

 type;
    
    int

 propID;
    
    int

 figureID;
    
    float

 numInt;
    
    int

 refreshSecond;
    
    int




 * skillIDArr;
    
    int




 * itemIDArr;
    
    double




 * itemRateArr;
    
    int




 * missionItem;
    
    float

 sight;
    
    float

 attackRange;
    
    int

 attackSkillID;
    
    std::string




 * healthAIArr;
    
    std::string




 * manaAIArr;
    
    std::string




 * furyAIArr;
    
    std::string




 * energyAIArr;
    
    bool

 isPeeled;
    
    bool

 cannotMove;
};
