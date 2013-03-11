



#include <map>
#include <vector>
#include <string>

class StreamReader;
class EquipConfig
{
public:
    static std::map<int, EquipConfig*> dic;
    static std::vector<EquipConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    EquipConfig(
    int
 id_, 
    std::string
 name_, 
    int
 part_, 
    int
 weaponProp_, 
    int
 weaponType_, 
    int
 clothType_, 
    int



* jobLimit_,
    int
 maxEndure_, 
    int



* propIDArr_,
    int



* propValueArr_,
    float
 fixParam_, 
    int



* avatarIDArr_,
    std::string



* avatarNameArr_,
    int
 holeCount_);
    ~EquipConfig();

    
    int
     id;
    
    std::string
     name;
    
    int
     part;
    
    int
     weaponProp;
    
    int
     weaponType;
    
    int
     clothType;
    
    int



*     jobLimit;
    
    int
     maxEndure;
    
    int



*     propIDArr;
    
    int



*     propValueArr;
    
    float
     fixParam;
    
    int



*     avatarIDArr;
    
    std::string



*     avatarNameArr;
    
    int
     holeCount;
};
