





#include <map>
#include <vector>
#include <string>

class StreamReader;
class ItemConfig
{
public:
    static std::map<int, ItemConfig*> dic;
    static std::vector<ItemConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    ItemConfig(
    int

 id_,

    std::string

 name_,

    std::string

 description_,

    std::string

 iconUrl_,

    std::string

 resName_,

    int

 type_,

    int

 npcPrice_,

    int

 grade_,

    int

 level_,

    int

 levelRequired_,

    int

 binding_,

    int

 maxCount_,

    int

 linkID_,

    int

 skillID_,

    bool

 useDestruction_,

    bool

 offlineDestruction_
);
    ~ItemConfig();

    
    int

 id;
    
    std::string

 name;
    
    std::string

 description;
    
    std::string

 iconUrl;
    
    std::string

 resName;
    
    int

 type;
    
    int

 npcPrice;
    
    int

 grade;
    
    int

 level;
    
    int

 levelRequired;
    
    int

 binding;
    
    int

 maxCount;
    
    int

 linkID;
    
    int

 skillID;
    
    bool

 useDestruction;
    
    bool

 offlineDestruction;
};
