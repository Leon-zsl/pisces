





#include <map>
#include <vector>
#include <string>

class StreamReader;
class BagConfig
{
public:
    static std::map<int, BagConfig*> dic;
    static std::vector<BagConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    BagConfig(
    int

 id_,

    int

 bagType_,

    int

 slotCount_
);
    ~BagConfig();

    
    int

 id;
    
    int

 bagType;
    
    int

 slotCount;
};
