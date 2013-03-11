



#include <map>
#include <vector>
#include <string>

class StreamReader;
class EffectConfig
{
public:
    static std::map<int, EffectConfig*> dic;
    static std::vector<EffectConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    EffectConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 effectUrl_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    std::string
 direction_, 
    int
 target_, 
    int
 horStrength_, 
    int
 verStrength_, 
    int
 element_, 
    int
 elementValue_, 
    int
 selfBuffID_, 
    int
 targetBuffID_, 
    bool
 isFocus_, 
    bool
 invincible_, 
    bool
 isBindSkill_, 
    long long
 effectDuration_, 
    bool
 isCrossbody_);
    ~EffectConfig();

    
    int
     id;
    
    std::string
     name;
    
    std::string
     effectUrl;
    
    float
     length;
    
    float
     width;
    
    float
     height;
    
    std::string
     direction;
    
    int
     target;
    
    int
     horStrength;
    
    int
     verStrength;
    
    int
     element;
    
    int
     elementValue;
    
    int
     selfBuffID;
    
    int
     targetBuffID;
    
    bool
     isFocus;
    
    bool
     invincible;
    
    bool
     isBindSkill;
    
    long long
     effectDuration;
    
    bool
     isCrossbody;
};
