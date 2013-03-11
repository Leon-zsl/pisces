



#include <map>
#include <vector>
#include <string>

class StreamReader;
class MinorMissionConfig
{
public:
    static std::map<int, MinorMissionConfig*> dic;
    static std::vector<MinorMissionConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    MinorMissionConfig(
    int
 id_, 
    std::string
 missionName_, 
    int



* prestigeRequired_,
    int



* nameText_,
    int



* missionIntroText_,
    int



* missionWayText_,
    int



* missionCompleteText_,
    int
 missionCompleteCondText_, 
    int



* missionNPCText_,
    int



* missionMonsterText_,
    int



* vipParam_,
    float
 expBonusCoe_, 
    float
 moneyBonus_, 
    int
 prestigeBonus_, 
    int
 timeLimit_, 
    int



* boxEx_,
    int



* destroyBoxes_,
    int



* mineID_,
    int



* missionNPC_);
    ~MinorMissionConfig();

    
    int
     id;
    
    std::string
     missionName;
    
    int



*     prestigeRequired;
    
    int



*     nameText;
    
    int



*     missionIntroText;
    
    int



*     missionWayText;
    
    int



*     missionCompleteText;
    
    int
     missionCompleteCondText;
    
    int



*     missionNPCText;
    
    int



*     missionMonsterText;
    
    int



*     vipParam;
    
    float
     expBonusCoe;
    
    float
     moneyBonus;
    
    int
     prestigeBonus;
    
    int
     timeLimit;
    
    int



*     boxEx;
    
    int



*     destroyBoxes;
    
    int



*     mineID;
    
    int



*     missionNPC;
};
