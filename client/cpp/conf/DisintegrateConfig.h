



#include <map>
#include <vector>
#include <string>

class StreamReader;
class DisintegrateConfig
{
public:
    static std::map<int, DisintegrateConfig*> dic;
    static std::vector<DisintegrateConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    DisintegrateConfig(
    int
 id_, 
    int



* itemIDs_,
    std::string



* itemCounts_,
    int
 addItemIDs_);
    ~DisintegrateConfig();

    
    int
     id;
    
    int



*     itemIDs;
    
    std::string



*     itemCounts;
    
    int
     addItemIDs;
};
