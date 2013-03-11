



#include <map>
#include <vector>
#include <string>

class StreamReader;
class AvatarConfig
{
public:
    static std::map<int, AvatarConfig*> dic;
    static std::vector<AvatarConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    AvatarConfig(
    int
 id_, 
    std::string
 hair_, 
    std::string
 face_, 
    std::string
 trunk_, 
    std::string
 waist_, 
    std::string
 l_arm_, 
    std::string
 r_arm_, 
    std::string
 l_palm_, 
    std::string
 r_palm_, 
    std::string
 l_leg_, 
    std::string
 r_leg_, 
    std::string
 l_feed_, 
    std::string
 r_feed_, 
    std::string
 l_shoes_, 
    std::string
 r_shoes_, 
    std::string
 effect_, 
    std::string
 other1_, 
    std::string
 other2_);
    ~AvatarConfig();

    
    int
     id;
    
    std::string
     hair;
    
    std::string
     face;
    
    std::string
     trunk;
    
    std::string
     waist;
    
    std::string
     l_arm;
    
    std::string
     r_arm;
    
    std::string
     l_palm;
    
    std::string
     r_palm;
    
    std::string
     l_leg;
    
    std::string
     r_leg;
    
    std::string
     l_feed;
    
    std::string
     r_feed;
    
    std::string
     l_shoes;
    
    std::string
     r_shoes;
    
    std::string
     effect;
    
    std::string
     other1;
    
    std::string
     other2;
};
