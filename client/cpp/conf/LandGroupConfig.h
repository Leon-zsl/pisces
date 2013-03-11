



#include <map>
#include <vector>
#include <string>

class StreamReader;
class LandGroupConfig
{
public:
    static std::map<int, LandGroupConfig*> dic;
    static std::vector<LandGroupConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    LandGroupConfig(
    int
 id_, 
    std::string
 landGroupName_, 
    std::string
 normalIcon_, 
    std::string
 hoverIcon_, 
    std::string
 activeIcon_, 
    float
 posX_, 
    float
 posY_, 
    float
 ctrPosX_, 
    float
 ctrPosY_, 
    float
 ctrWidth_, 
    float
 ctrHeight_, 
    int
 landType_, 
    bool
 landPluFlag_, 
    int



* landIDArr_,
    int



* landPortalArr_,
    std::string



* iconArr_,
    std::string



* infoIconArr_);
    ~LandGroupConfig();

    
    int
     id;
    
    std::string
     landGroupName;
    
    std::string
     normalIcon;
    
    std::string
     hoverIcon;
    
    std::string
     activeIcon;
    
    float
     posX;
    
    float
     posY;
    
    float
     ctrPosX;
    
    float
     ctrPosY;
    
    float
     ctrWidth;
    
    float
     ctrHeight;
    
    int
     landType;
    
    bool
     landPluFlag;
    
    int



*     landIDArr;
    
    int



*     landPortalArr;
    
    std::string



*     iconArr;
    
    std::string



*     infoIconArr;
};
