



#include <map>
#include <vector>
#include <string>

class StreamReader;
class TrainingConfig
{
public:
    static std::map<int, TrainingConfig*> dic;
    static std::vector<TrainingConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    TrainingConfig(
    int
 id_, 
    int
 preID_, 
    std::string
 bgResName_, 
    float
 bgOffsetX_, 
    float
 bgOffsetY_, 
    std::string



* texResName_,
    float
 texOffsetX_, 
    float
 texOffsetY_, 
    int
 exp_);
    ~TrainingConfig();

    
    int
     id;
    
    int
     preID;
    
    std::string
     bgResName;
    
    float
     bgOffsetX;
    
    float
     bgOffsetY;
    
    std::string



*     texResName;
    
    float
     texOffsetX;
    
    float
     texOffsetY;
    
    int
     exp;
};
