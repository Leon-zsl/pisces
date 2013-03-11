



#include <map>
#include <vector>
#include <string>

class StreamReader;
class LevelConfig
{
public:
    static std::map<int, LevelConfig*> dic;
    static std::vector<LevelConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    LevelConfig(
    int
 id_, 
    int
 expRequired_, 
    int
 baseExp_, 
    int
 missionBaseExp_, 
    int



* minorMissionType_,
    int



* randGroupLand_,
    int



* randGroupNPCArr_,
    int



* randGroupForbiddenTypeArr_,
    int



* minorMissionLand_,
    int
 minorMissionMoney_, 
    int



* minorMissionItemBonus_,
    int



* minorMissionItemBonusCount_,
    int



* monsterItemIDArr_,
    double



* monsterItemRateArr_,
    int



* bossItemIDArr_,
    double



* bossItemRateArr_,
    int
 monsterCorpseID_, 
    int
 monsterMoney_, 
    float
 monsterMoneyRate_, 
    int
 dailyMissionMoney_);
    ~LevelConfig();

    
    int
     id;
    
    int
     expRequired;
    
    int
     baseExp;
    
    int
     missionBaseExp;
    
    int



*     minorMissionType;
    
    int



*     randGroupLand;
    
    int



*     randGroupNPCArr;
    
    int



*     randGroupForbiddenTypeArr;
    
    int



*     minorMissionLand;
    
    int
     minorMissionMoney;
    
    int



*     minorMissionItemBonus;
    
    int



*     minorMissionItemBonusCount;
    
    int



*     monsterItemIDArr;
    
    double



*     monsterItemRateArr;
    
    int



*     bossItemIDArr;
    
    double



*     bossItemRateArr;
    
    int
     monsterCorpseID;
    
    int
     monsterMoney;
    
    float
     monsterMoneyRate;
    
    int
     dailyMissionMoney;
};
