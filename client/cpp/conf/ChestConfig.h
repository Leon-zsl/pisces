



#include <map>
#include <vector>
#include <string>

class StreamReader;
class ChestConfig
{
public:
    static std::map<int, ChestConfig*> dic;
    static std::vector<ChestConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    ChestConfig(
    int
 id_, 
    std::string
 name_, 
    bool
 isFixedBonus_, 
    int



* itemIDArr_,
    int



* itemRateArr_,
    int
 keyItemID_);
    ~ChestConfig();

    
    int
     id;
    
    std::string
     name;
    
    bool
     isFixedBonus;
    
    int



*     itemIDArr;
    
    int



*     itemRateArr;
    
    int
     keyItemID;
};
