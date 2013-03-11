



#include <map>
#include <vector>
#include <string>

class StreamReader;
class JewelConfig
{
public:
    static std::map<int, JewelConfig*> dic;
    static std::vector<JewelConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    JewelConfig(
    int
 id_, 
    std::string
 name_, 
    int



* equipParts_,
    int



* stgPropIDs_,
    int



* strgPropValues_,
    int
 equipLevelEffect_);
    ~JewelConfig();

    
    int
     id;
    
    std::string
     name;
    
    int



*     equipParts;
    
    int



*     stgPropIDs;
    
    int



*     strgPropValues;
    
    int
     equipLevelEffect;
};
