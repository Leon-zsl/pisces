



#include <map>
#include <vector>
#include <string>

class StreamReader;
class NpcConfig
{
public:
    static std::map<int, NpcConfig*> dic;
    static std::vector<NpcConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    NpcConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 modelUrl_, 
    std::string
 animIdle_, 
    std::string
 animTalk_, 
    std::string
 animEffect_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    int



* textIDArr_,
    int
 factionID_, 
    int
 cargoID_, 
    int



* features_,
    std::string



* featureNames_,
    int



* missionIDArr_,
    int
 transferJobID_, 
    int
 deputyID_);
    ~NpcConfig();

    
    int
     id;
    
    std::string
     name;
    
    std::string
     modelUrl;
    
    std::string
     animIdle;
    
    std::string
     animTalk;
    
    std::string
     animEffect;
    
    float
     length;
    
    float
     width;
    
    float
     height;
    
    int



*     textIDArr;
    
    int
     factionID;
    
    int
     cargoID;
    
    int



*     features;
    
    std::string



*     featureNames;
    
    int



*     missionIDArr;
    
    int
     transferJobID;
    
    int
     deputyID;
};
