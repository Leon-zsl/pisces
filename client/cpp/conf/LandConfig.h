



#include <map>
#include <vector>
#include <string>

class StreamReader;
class LandConfig
{
public:
    static std::map<int, LandConfig*> dic;
    static std::vector<LandConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    LandConfig(
    int
 id_, 
    std::string
 landName_, 
    int
 landType_, 
    int
 playerLimit_, 
    int



* sceneIDArr_,
    std::string
 landNameRes_, 
    int



* monsterIDArr_,
    int



* bossIDArr_,
    int



* mineIDArr_,
    int



* mineRateArr_,
    int
 mineCount_, 
    int



* boxIDArr_,
    int
 boxCount_, 
    int



* mapIDArr_,
    int



* connLandIDArr_,
    int



* connLandTimeArr_);
    ~LandConfig();

    
    int
     id;
    
    std::string
     landName;
    
    int
     landType;
    
    int
     playerLimit;
    
    int



*     sceneIDArr;
    
    std::string
     landNameRes;
    
    int



*     monsterIDArr;
    
    int



*     bossIDArr;
    
    int



*     mineIDArr;
    
    int



*     mineRateArr;
    
    int
     mineCount;
    
    int



*     boxIDArr;
    
    int
     boxCount;
    
    int



*     mapIDArr;
    
    int



*     connLandIDArr;
    
    int



*     connLandTimeArr;
};
